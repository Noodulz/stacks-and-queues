#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

template <typename T>
class ABQ {
   private:
      int* capacity;
      int* size;
      T* queueArray;
      int scaleFactor = 2;
   public:
      ABQ();
      ABQ(int capacity);
      ABQ(const ABQ &d);
      ABQ &operator==(const ABQ &d);
      ~ABQ();
      void enqueue(T data);
      T dequeue();
      T peek();
      unsigned int getSize();
      unsigned int getMaxCapacity();
      T* getData();
};

template <typename T>
ABQ<T>::ABQ() {
   this->capacity = new int;
   this->size = new int;
   *capacity = 1;
   *size = 0;
   queueArray = new T[*capacity];
}
template <typename T>
ABQ<T>::ABQ(int c) {
   capacity = new int;
   size = new int;
   *capacity = c;
   *size = 0;
   queueArray = new T[*capacity];
}
template <typename T>
ABQ<T>::~ABQ() {
   delete[] queueArray;
   delete size;
   delete capacity;
}
template <typename T>
ABQ<T>::ABQ(const ABQ &d) {
   capacity = new int;
   size = new int;
   *capacity = *(d.capacity);
   *capacity = *(d.size);
}
template <typename T>
void ABQ<T>::enqueue(T data) {
   if (*size >= *capacity) {
      T* newQueueArray = new T[*capacity * (int) scaleFactor];
      newQueueArray[0] = data;
      for (int i = 0; i < *size; i++) {
         newQueueArray[i + 1] = queueArray[i];
      }
      *capacity = *capacity * scaleFactor;
      *size = *size + 1;
      delete[] queueArray;
      queueArray = newQueueArray;
   }
   else {
      T* newQueueArray = new T[*capacity];
      newQueueArray[0] = data;
      for (int i = 0; i < *size; i++) {
         newQueueArray[i + 1] = queueArray[i];
      }
      *size = *size + 1;
      delete[] queueArray;
      queueArray = newQueueArray;
   }
}
template <typename T>
T ABQ<T>::dequeue() {
   T top = queueArray[*size - 1];
   if (queueArray[*size - 1] == 0) {
      top = queueArray[*size - 2];
   }
   else {
      top = queueArray[*size - 1];
   }
   *size -= 1;
   double currentRatio = (double) *size / *capacity;
   double scale = 0.5;
   if (*size < 0) {
      throw runtime_error("Queue empty!");
   }
   else if (currentRatio >= scale) {
      return top;
   }
   else if (currentRatio < scale) {
      *capacity = (int) *capacity / 2;
      T* newQueueArray = new T[*capacity];
      for (int i = 0; i < *size; i++) {
         newQueueArray[i] = queueArray[i];
      }
      delete[] queueArray;
      queueArray = newQueueArray;
      return top;
   }
   else if (currentRatio >= 0.5) {
      return top;
   }
   else {
      return top;
   }
}
template <typename T>
T ABQ<T>::peek() {
   if (*size <= 0) {
      throw runtime_error("Stack empty!");
   }
   else {
      return queueArray[*size - 1];
   }
}
template <typename T>
unsigned int ABQ<T>::getSize() {
   unsigned int getSize = *size;
   return getSize;
}
template <typename T>
unsigned int ABQ<T>::getMaxCapacity() {
   unsigned int getCapacity = *capacity;
   return getCapacity;
}
template <typename T>
T* ABQ<T>::getData() {
   return queueArray;
}

      