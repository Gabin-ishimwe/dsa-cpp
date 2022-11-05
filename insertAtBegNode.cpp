#include <iostream>

struct Node
{
  /* data */
  int data;
  Node* pNext;
};
void insertNode(int x);
void printNodes();

Node* head; // global node
int main() {
  head = NULL;
  int nums, enter;
  std::cout << "Number of int you want to add ";
  std::cin >> nums;
  std::cout << "\n";
  for(int i = 0; i < nums ; i++) {
    std::cout << "enter a number: ";
    std::cin >> enter;
    insertNode(enter);
    printNodes();
  }
  return 0;
}

void insertNode(int x) {
  Node* tempNode = new Node();
  tempNode->data = x;
  // tempNode->pNext = NULL;
  // if(head != NULL) tempNode->pNext = head;
  tempNode->pNext = head;
  head = tempNode;
}

void printNodes() {
  Node* tempNode = head;
  std::cout << "LIst is \n";
  while (tempNode != NULL)
  {
    /* code */
    std::cout << tempNode->data;
    tempNode = tempNode->pNext;
  }

  std::cout << "\n";
  
}