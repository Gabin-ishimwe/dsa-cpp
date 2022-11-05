#include <iostream>

struct Node
{
  /* data */
  int data;
  Node* pNext;
};

void insertNode(int data, int n);
void printNodes();

Node* head; // global head node
int main() {
  head = NULL;
  insertNode(2, 1);
  insertNode(5, 2);
  insertNode(7, 3);
  insertNode(9, 4);
  insertNode(3, 1);
  printNodes();

  return 0;
}

void insertNode(int data, int n) {
  Node* temp1 = new Node();
  temp1->data = data;
  temp1->pNext = NULL;
  if(n == 1) {  // inserting at the begining
  temp1->pNext = head;
  head = temp1;
  return;
  }
  // traversal to n-1th position
  Node* temp2 = head;
  // n-2 with the head node added
  for(int i = 0; i < n-2; i++) {
    temp2 = temp2->pNext;
  }
  temp1->pNext = temp2->pNext;
  temp2->pNext = temp1;
}

void printNodes() {
  Node* temp = head;
  while(temp != NULL) {
    std::cout << temp->data << " ";
    temp = temp->pNext;
  }
  std::cout << "\n";
}