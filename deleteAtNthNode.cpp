#include <iostream>

struct Node
{
  /* data */
  int data;
  Node* pNext;
};

void insertNode(int data, int n);
void printNodes();
void deleteNode(int n);
void insertLast(int data);

Node* head;
int main() {
  head = NULL;
  // insertNode(2, 1);
  // insertNode(4, 2);
  // insertNode(8, 3);
  // insertNode(9, 4);
  insertLast(2);
  insertLast(4);
  insertLast(8);
  insertLast(9);
  insertLast(10);
  insertLast(12);
  insertLast(14);
  printNodes();
  // int n;
  // std::cout << "Enter position: ";
  // std::cin >> n;
  // deleteNode(n);
  // printNodes();
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
  Node* temp1 = head;
  while (temp1 != NULL)
  {
    /* code */
    std::cout << temp1->data << " ";
    temp1 = temp1->pNext;
  }
  std::cout << "\n";
  
}

void deleteNode(int n) {
  Node* temp = head;
  if(n == 1) {
    head = temp->pNext;
    delete temp;
    return;
  }

  for(int i = 0; i < n-2; i++) {
    temp = temp->pNext;
  }
  Node* nodeToDelete = temp->pNext;
  temp->pNext = nodeToDelete->pNext;
  delete nodeToDelete;
}

void insertLast(int data) {
  Node* temp = new Node();
  temp->data = data;
  temp->pNext = NULL;

  if(head == NULL) {
    head = temp;
    return;
  }
  Node* traversal = head;
  while (traversal->pNext != NULL)
  {
    /* code */
    traversal = traversal->pNext;
  }
  traversal->pNext = temp;
  // std::cout << traversal->data << " ";
  
}