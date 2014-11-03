// Basic data structures implemented in C++

#include <memory>
#include <iostream>

class List {
public:

  List();
  ~List();
  void AppendHead(const int& value);
  void AppendTail(const int& value);
  int RemoveHead();
  int RemoveTail();

private:
  struct Node {
    std::unique_ptr<Node> next;
    int value;
  };
  std::unique_ptr<Node> head_;
  Node* tail_;
};

List::List() :
  tail_(nullptr)
{}

List::~List() {}

void List::AppendHead(const int& value) {
  if(head_.get() == nullptr) {
    head_.reset(new List::Node());
    head_.get()->value = value;
    tail_ = head_.get();
  } else {
    List::Node* tmp = new List::Node();
    tmp->value = value;
    tmp->next = std::move(head_);
    head_.reset(tmp);
  }
}

void List::AppendTail(const int& value) {
  if(head_.get() == nullptr) {
    head_.reset(new List::Node());
    head_.get()->value = value;
    tail_ = head_.get();
  } else {
    List::Node* tmp = new List::Node();
    tmp->value = value;
    tmp->next = nullptr;
    tail_->next.reset(tmp);
    tail_ = tail_->next.get();
  }
}

int List::RemoveHead() {
  if(head_.get() == nullptr) {
    return -1;
  } else {
    int tmp = head_.get()->value;
    head_ = std::move(head_.get()->next);
    return tmp;
  }
}

int List::RemoveTail() {
  if(tail_ == nullptr) {
    return -1;
  } else if(head_.get() == tail_) {
    int tmp = tail_->value;
    tail_ = nullptr;
    head_.release();
    return tmp;
  } else {
    int tmp = tail_->value;
    Node* prev = nullptr;
    Node* current = head_.get();
    while(current != nullptr && current->next.get() != nullptr) {
      prev = current;
      current = current->next.get();
    }
    prev->next.release();
    tail_ = prev;
    return tmp;
  }
}

int main()
{
  List l;
  l.AppendTail(10);
  l.AppendHead(1);
  l.AppendHead(2);
  l.AppendTail(12);
  l.AppendHead(3);
  l.AppendTail(11);
  l.AppendHead(4);
  l.AppendTail(13);
  std::cout << l.RemoveHead() << std::endl;
  std::cout << l.RemoveTail() << std::endl;
  std::cout << l.RemoveHead() << std::endl;
  std::cout << l.RemoveTail() << std::endl;
  std::cout << l.RemoveHead() << std::endl;
  std::cout << l.RemoveTail() << std::endl;
  std::cout << l.RemoveHead() << std::endl;
  std::cout << l.RemoveTail() << std::endl;
  std::cout << l.RemoveHead() << std::endl;
  std::cout << l.RemoveTail() << std::endl;
  return 0;
}
