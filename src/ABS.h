#include <iostream>
#include <string>
#include <stdexcept>
using namespace std; 

// This implementation uses templates to support stacks of various types
template <typename T>
class ABS{
   private:
      int* capacity;
      int* size;
      T* stackArray;
      int scaleFactor = 2; // The stack will be resized and adjusted if the capacity is full, by a factor of 2
   public:
      ABS();
      ABS(int capacity);
      ABS(const ABS &d);
      ABS &operator=(const ABS &d); // Defined by default?
      ~ABS();
      void push(T data);
      T pop();
      T peek();
      unsigned int getSize();
      unsigned int getMaxCapacity();
      T* getData(); 
};

// Beginning of function definitions

// Default constructor
template <typename T>
ABS<T>::ABS() {
   this->capacity = new int;
   this->size = new int;
   *capacity = 1;
   *size = 0;
   stackArray = new T[*capacity];
}
template <typename T>
ABS<T>::ABS(int c) {
   capacity = new int;
   size = new int;
   *capacity = c;
   *size = 0;
   stackArray = new T[*capacity];
}
// Copy constructor
template <typename T>
ABS<T>::ABS(const ABS &d) {
   capacity = new int;
   size = new int;
   *capacity = *(d.capacity);
   *size = *(d.size);
}
// Destructor
template <typename T>
ABS<T>::~ABS() {
   delete[] stackArray;
   delete size;
   delete capacity;
}
// Stack push
template <typename T>
void ABS<T>::push(T data) {
   if (*size >= *capacity) {
      T* newStackArray = new T[*capacity * (int) scaleFactor];
      for (int i = 0; i < *size; i++) {
         newStackArray[i] = stackArray[i];
      }
      *capacity = *capacity * scaleFactor;
      *size = *size + 1;
      newStackArray[*size - 1] = data;
      delete[] stackArray;
      stackArray = newStackArray;
   }
   else {
      *size = *size + 1;
      stackArray[*size - 1] = data;
   }
}
// Stack pop
template <typename T>
T ABS<T>::pop() {
   T top = stackArray[*size - 1];
   if (stackArray[*size - 1] == 0) {
      top = stackArray[*size - 2];
   }
   else {
      top = stackArray[*size - 1];
   }
   *size -= 1;
   double currentRatio = (double) *size / *capacity;
   double scale = 0.5;
   if (*size < 0) {
      throw runtime_error("Stack empty!");
   }
   else if (currentRatio >= scale) {
      return top;
   }
   else if (currentRatio < scale) {
      *capacity = (int) *capacity / 2;
      T* newStackArray = new T[*capacity];
      for (int i = 0; i < *size; i++) {
         newStackArray[i] = stackArray[i];
      }
      delete[] stackArray;
      stackArray = newStackArray;
      return top;
   }
   else if (currentRatio >= 0.5) {
      return top;
   }
   else {
      return top;
   }
}
// Peek at the top value of stack
template <typename T>
T ABS<T>::peek() {
   if (*size <= 0) {
      throw runtime_error("Stack empty!");
   }
   else {
      return stackArray[*size - 1];
   }
}
// Returns size of stack
template <typename T>
unsigned int ABS<T>::getSize() {
   unsigned int getSize = *size;
   return getSize;
}
// Returns current capacity of stack
template <typename T>
unsigned int ABS<T>::getMaxCapacity() {
   unsigned int getCapacity = *capacity;
   return getCapacity;
}
// Returns current stack and its dynamically allocated array
template <typename T>
T* ABS<T>::getData() {
   return stackArray;
}
