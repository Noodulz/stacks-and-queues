#include <iostream>
#include <unistd.h>
#include <assert.h>
#include "ABS.h"
using namespace std;

// 1 million = 1 second
int main() {
  // Initialize stack
  cout << "Creating an array-based stack..." << endl;
  usleep(1000000);
  ABS<int> testStack(10);
  assert(testStack.getMaxCapacity() == 10);
  cout << "Max capacity now: " << testStack.getMaxCapacity() << endl;
  assert(testStack.getSize() == 0);
  cout << "Size now: " << testStack.getSize() << endl;
  usleep(1000000);
  cout << "Stack initialized with correct size and capacity!\n" << endl;

  // Pushing values to stack
  cout << "Pushing 20 values to the stack...\n" << endl;
  for (int i = 0; i < 20; i++) {
    testStack.push(i);
    cout << "Pushed " << testStack.peek() << " Size: " << testStack.getSize() << " Capacity: " << testStack.getMaxCapacity() << endl;
  }
  usleep(2000000);
  assert(testStack.getSize() == 20);
  cout << "\nStack  now: ";
  for (int i = 0; i < testStack.getSize(); i++) {
    cout << testStack.getData()[i] << " ";
  }

  // Testing pop function, make sure it resizes
  cout << "\nPopping 20 values from the testStack...\n" << endl;
  usleep(2000000);
  for (int i = 0; i < 20; i++) {
    cout << "Popped: " << testStack.pop() << " Size: " << testStack.getSize() << " Capacity: " << testStack.getMaxCapacity() << endl;
  }
  cout << "\nStack is now empty! Let's try peeking..." << endl;
  usleep(1000000);
  cout << testStack.peek() << endl;
   
}
