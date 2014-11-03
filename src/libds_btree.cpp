// Basic binary tree data structure implemented in C++

#include <memory>
#include <iostream>

class BinaryTree {
public:
  BinaryTree();
  ~BinaryTree();
  void Insert(const int& value);
  bool Remove(const int& value);
  bool Find(const int& value);
  void Print(std::ostream& stream);

private:
  struct Node {
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;
    int value;
  };

  void PrintPreOrder(Node* root, std::ostream& stream);

  std::unique_ptr<Node> root_;
};

BinaryTree::BinaryTree() :
  root_(nullptr)
{}

BinaryTree::~BinaryTree() {}

void BinaryTree::Insert(const int& value) {
  if(!root_) {
    root_.reset(new Node());
    root_->value = value;
    return;
  }
  Node* current = root_.get();
  while(current != nullptr) {
    if(current->value >= value) {
      if(!current->left) {
        current->left.reset(new Node());
        current->left->value = value;
        break;
      }
      current = current->left.get();
    } else {
      if(!current->right) {
        current->right.reset(new Node());
        current->right->value = value;
        break;
      }
      current = current->right.get();
    }
  }
}

bool BinaryTree::Remove(const int& value) {
  Node* current = root_.get();
  while(current != nullptr) {
    if(current->value >= value) {
      if(current->left && current->left->value == value) {
        std::unique_ptr<Node> right_tmp(std::move(current->left->right));
        current->left = std::move(current->left->left);
        // find place for right
        current = current->left.get();
        while(current != nullptr) {
          if(!current->right) {
            current->right = std::move(right_tmp);
            break;
          }
          current = current->right.get();
        }
        break;
      }
      current = current->left.get();
    } else {
      if(current->left && current->right->value == value) {
        std::unique_ptr<Node> right_tmp(std::move(current->right->right));
        current->right = std::move(current->right->left);
        // find place for right
        current = current->right.get();
        while(current != nullptr) {
          if(!current->right) {
            current->right = std::move(right_tmp);
            break;
          }
          current = current->right.get();
        }
        break;
      }
      current = current->right.get();
    }
  }
  return false;
}

bool BinaryTree::Find(const int& value) {
  Node* current = root_.get();
  while(current != nullptr) {
    if(current->value == value) {
      return true;
    }
    else if(current->value >= value) {
      current = current->left.get();
    } else {
      current = current->right.get();
    }
  }
  return false;
}

void BinaryTree::Print(std::ostream& stream) {
  PrintPreOrder(root_.get(), stream);
  stream << std::endl;
}

void BinaryTree::PrintPreOrder(Node* root, std::ostream& stream) {
  if(root) {
    PrintPreOrder(root->left.get(), stream);
    stream << root->value << " ";
    PrintPreOrder(root->right.get(), stream);
  }
}

int main()
{
  BinaryTree t;
  t.Insert(1);
  t.Insert(97);
  t.Insert(44);
  t.Insert(4);
  t.Insert(3);
  t.Insert(10);
  t.Insert(100);
  t.Insert(5);
  t.Insert(5);
  t.Print(std::cout);
  std::cout << "Find: " << 10 << " : " << t.Find(10) << std::endl;
  std::cout << "Find: " << 100 << " : " << t.Find(100) << std::endl;
  std::cout << "Find: " << 99 << " : " << t.Find(99) << std::endl;
  t.Remove(10);
  t.Remove(5);
  t.Remove(4);
  t.Remove(100);
  t.Remove(44);
  t.Remove(5);
  t.Print(std::cout);

  return 0;
}
