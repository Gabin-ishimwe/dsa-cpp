#include <iostream>

struct Node
{
  /* data */
  int data;
  Node* next;
};

void insertNode(int data, int n);
void printRecursion(Node*& head);
void reverseListRecursion(Node*& head);


Node* head;
int main() {
  head = NULL;
  insertNode(2, 1);
  insertNode(4, 2);
  insertNode(5, 3);
  insertNode(7, 4);
  reverseListRecursion(head);
  printRecursion(head);
  return 0;
}

void insertNode(int data, int n) {
  Node* temp = new Node();
  temp->data = data;
  temp->next = NULL;
  if(n == 1) {
    temp->next = head;
    head = temp;
    return;
  }

  Node* temp1 = head;
  for(int i = 0; i < n-2; i++) {
    temp1 = temp1->next;
  }

  temp->next = temp1->next;
  temp1->next = temp;
  // return head;
}

void printRecursion(Node*& head) {
  if(head == NULL) return;
  std::cout << head->data << " ";
  printRecursion(head->next);
}

void reverseListRecursion(Node*& traversalNode) {
  if(traversalNode->next == NULL) {
    head = traversalNode;
    return;
  }
  reverseListRecursion(traversalNode->next);
  Node* temp = traversalNode->next;
  temp->next = traversalNode;
  traversalNode->next = NULL;
}