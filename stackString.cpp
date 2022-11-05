#include <iostream>

class Stack {
  private:
      int top = -1;
      int stackSize = 5;
      char listStack[5];


  public:
      // void stackList(int size) {
      //   listStack[size];
      //   stackSize = size;
      // }

      void push(char data) {
        top ++;
        if(top == stackSize) {
          top--;
          std::cout << "stack is full\n";
          return;
        }
        listStack[top] = data;
      }
      void pop() {
        if(top == -1) {
          std::cout << "stack is empty\n";
          return;
        }
        top --;
      }

      char atTop() {
        return listStack[top];
      }

      void printStack() {
        for(int i = 0; i <= top; i++ ) {
          std::cout << listStack[i] << " ";
        }
        std::cout << "\n";
      }

      void reverse(std::string &data, int size) {
        for(int i = 0; i < size; i++) {
          data[i] = listStack[top];
          pop();
        }
        std::cout << "reversed string is " << data << "\n";
      }


};

int main() {
  std::string name;
  std::cout << "input something: ";
  std::cin >> name;
  int size = name.size();
  Stack stack;
  // stack.stackList(size);
  for(int i = 0; i < size; i++) {
    stack.push(name[i]);
  }
  stack.reverse(name, size);
  // stack.printStack();
  // stack.pop();
  // stack.printStack();
  return 0;
}