#include <iostream>

class StackAlg {
  public:
      int top = -1;
      int nums[5];

      void push(int num) {
        top ++;
        if(top == 5) {
          std::cout << "Stack is full\n";
          return;
        }
        nums[top] = num;
      }

      void pop() {
        if(top == -1) {
          std::cout << "Stack is empty\n";
          return;
        }
        top --;
        // std::cout << "top element is " << nums[top] << "\n";
      }

      bool isEmpty() {
        if(top == -1) {
          return true;
        }
        return false;
      }

      void printElements() {
        for(int i = 0; i <= top; i++) {
          std::cout << nums[i] << " ";
        }
        std::cout << "\n";
      }
};

int main() {
  StackAlg stack;
  stack.push(1);
  stack.push(5);
  stack.push(8);
  stack.push(2);
  stack.push(3);
  std::cout << stack.isEmpty() << "\n";
  stack.printElements();
  stack.pop();
  stack.printElements();
  stack.pop();
    stack.printElements();
  stack.pop();
    stack.printElements();
  stack.pop();
    stack.printElements();

  return 0;
}