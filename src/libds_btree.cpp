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
  typedef std::unique_ptr<Node> NodePtr;

  void PrintPreOrder(Node* root, std::ostream& stream);
  void InsertNode(NodePtr& ptr);

  NodePtr root_;
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

void BinaryTree::InsertNode(NodePtr& ptr) {
  if(!ptr) {
    return;
  }
  if(!root_) {
    root_ = std::move(ptr);
    return;
  }
  Node* current = root_.get();
  while(current != nullptr) {
    if(current->value >= ptr->value) {
      if(!current->left) {
        current->left = std::move(ptr);
        break;
      }
      current = current->left.get();
    } else {
      if(!current->right) {
        current->right = std::move(ptr);
        break;
      }
      current = current->right.get();
    }
  }
}

bool BinaryTree::Remove(const int& value) {
  Node* current = root_.get();
  if(current->value == value) {
    NodePtr right_tmp(std::move(current->right));
    root_ = std::move(current->left);
    InsertNode(right_tmp);
    return true;
  }
  while(current != nullptr) {
    if(current->value >= value) {
      if(current->left && current->left->value == value) {
        NodePtr right_tmp(std::move(current->left->right));
        current->left = std::move(current->left->left);
        InsertNode(right_tmp);
        return true;
      }
      current = current->left.get();
    } else {
      if(current->right && current->right->value == value) {
        NodePtr right_tmp(std::move(current->right->right));
        current->right = std::move(current->right->left);
        InsertNode(right_tmp);
        return true;
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
  t.Print(std::cout);
  t.Remove(5);
  t.Remove(1);
  t.Remove(3);
  t.Remove(97);
  t.Print(std::cout);
  t.Insert(5);
  t.Insert(5);
  t.Print(std::cout);

  return 0;
}
