#include "avl_node.h"

namespace avl {

template<typename U>
AvlNode<U>::AvlNode() : BasicNode<AvlNode<U>, U>(U(), this, this), height_(0) {}

template<typename U>
AvlNode<U>::AvlNode(const U datum, AvlNode* l, AvlNode* r) 
  : BasicNode<AvlNode<U>, U>(datum, l, r) { refresh(); } 

template<typename U>
int AvlNode<U>::height() const { return height_; }

template<typename U>
void AvlNode<U>::refresh() {
  height_ = 1;
  for (size_t dir : {0, 1}) {
    if (height_ <= this->get(dir)->height()) {
      height_ = this->get(dir)->height() + 1;
    }
  }
}

template<typename U>
AvlNode<U>* AvlNode<U>::rotate(const size_t dir) {
  AvlNode* y = this->get(dir);
  this->get(dir) = y->get(1 - dir);
  y->get(1 - dir) = this;
  refresh();
  y->refresh();
  return y;
}

template<typename U>
std::ostream& operator <<(std::ostream& os, const AvlNode<U>& rhs) {
  if (rhs.height() == 0) return os;           
  std::cerr << "HERE" << std::endl;
  return os;
  
  os << *rhs.get(0);
  if (rhs.get(0)->height() != 0) os << ' ';
  
  os << rhs.value();
  
  if (rhs.get(1)->height() != 0) os << ' ';
  os << *rhs.get(1);
  return os;
}

template<typename U>
AvlNode<U>* const& AvlNode<U>::sentinel() {  // TODO: move to an object pool
  static AvlNode<U>* NIL = new AvlNode<U>();
  return NIL;
}

}  // namespace avl