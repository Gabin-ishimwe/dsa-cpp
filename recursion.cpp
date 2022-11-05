#include <iostream>

// return the sum of the first n natural numbers
// use recursion !!!

int sum(int num);


int main() {

  std::cout << sum(5) << "\n";

  return 0;
}

int sum(int num) {
  if(num <= 1) {
    return num;
  }
  return num += sum(num-1);
};