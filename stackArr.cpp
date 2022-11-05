#include <iostream>

int nums[5];
int top = -1;

void push(int num);
void pop();
bool isEmpty();

int main() {
  push(1);
  push(2);
  push(3);
  push(4);
  push(5);
  pop();
  pop();
  std::cout << isEmpty() << "\n";
  pop();
  pop();
  pop();
  std::cout << isEmpty() << "\n";
  
  return 0;
}

void push(int num) {
  top ++;
  if(top == 5) {
    std::cout << "stack is arleady full \n";
    return;
  }
  nums[top] = num;
}


void pop() {
  top --;
  if(top == -1) {
    std::cout << "stack is empty \n";
    return;
  }
  std::cout << "top element is " <<  nums[top] << "\n";
}


bool isEmpty() {
  if (top == -1)
  {
    /* code */
    return true;
  }
  return false;
  
}