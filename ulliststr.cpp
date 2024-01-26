#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// --------------------
// WRITE YOUR CODE HERE
// --------------------

/**
  * Adds a new value to the back of the list
  *   - MUST RUN in O(1)
  */
void ULListStr::push_back(const std::string& val) {
  // three cases
  // 1. if it is empty
  if (empty()) {
    head_ = new Item();
    tail_ = head_;
  }

  // 2. if the current node is smaller than the arrsize
  if (tail_->last < ARRSIZE) {
    tail_->val[tail_->last++] = val;
  } 
  // 3. if the current node exceeds the arrsize
  else {
    Item* newTail = new Item();
    newTail->prev = tail_;
    tail_->next = newTail;
    tail_ = newTail;
    tail_->val[tail_->last++] = val;
    tail_->first = 0;
  }
  size_++;
}



/**
  * Removes a value from the back of the list
  *   - MUST RUN in O(1)
  */
void ULListStr::pop_back() {
  if (empty()) {
    throw std::out_of_range("empty");
  }

  if (tail_->last > tail_->first + 1) {
    tail_->last--;
  } 
  else {
    if (tail_->prev != nullptr) {
      tail_ = tail_->prev;
      delete tail_->next;
      tail_->next = nullptr;
    } 
    else {
      delete tail_;
      head_ = tail_ = nullptr;
    }
  }
  size_--;
}

/**
  * Adds a new value to the front of the list.
  * If there is room before the 'first' value in
  * the head node add it there, otherwise, 
  * allocate a new head node.
  *   - MUST RUN in O(1)
  */
void ULListStr::push_front(const std::string& val) {
  // three cases
  // 1. if it is empty
  if (empty()) {
    head_ = new Item();
    tail_ = head_;
    head_->first = ARRSIZE - 1;
    head_->last = ARRSIZE;
    head_->val[head_->first] = val;
  }
  // 2. if the current node is smaller than the arrsize (not zero)
  else if (head_->first > 0) {
    head_->val[--head_->first] = val;
  } 
  // 3. if the current node exceeds the arrsize
  else {
    Item* newHead = new Item();
    newHead->next = head_;
    head_->prev = newHead;
    head_ = newHead;
    head_->val[ARRSIZE - 1] = val;
    head_->first = ARRSIZE - 1;
    head_->last = ARRSIZE;
  }
  size_++;
}

/**
  * Removes a value from the front of the list
  *   - MUST RUN in O(1)
  */
void ULListStr::pop_front() {
  if (empty()) {
    throw std::out_of_range("empty");
  }

  if (head_->first < head_->last - 1) {
    head_->first++;
  } 
  else {
    if (head_->next != nullptr) {
      head_ = head_->next;
      delete head_->prev;
      head_->prev = nullptr;
    } 
    else {
      delete head_;
      head_ = tail_ = nullptr;
    }
  }
  size_--; 
}

/**
  * Returns a const reference to the back element
  *   - MUST RUN in O(1)
  */
std::string const & ULListStr::back() const {
  if (empty()) {
    throw std::out_of_range("empty");
  }
  return tail_->val[tail_->last - 1];
}

/**
  * Returns a const reference to the front element
  *   - MUST RUN in O(1)
  */
std::string const & ULListStr::front() const {
  if (empty()) {
    throw std::out_of_range("empty");
  }
  return head_->val[head_->first];
}
  
/** 
  * Returns a pointer to the item at index, loc,
  *  if loc is valid and NULL otherwise
  *   - MUST RUN in O(n) 
  */

std::string* ULListStr::getValAtLoc(size_t loc) const {
  if (loc >= size_) {
    return nullptr;
  }

  Item* current = head_;
  while (current != nullptr && loc >= (current->last - current->first)) {
    loc -= (current->last - current->first);
    current = current->next;
  }

  if (current != nullptr) {
    return &(current->val[current->first + loc]);
  } 
  else {
    return nullptr;
  }
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
