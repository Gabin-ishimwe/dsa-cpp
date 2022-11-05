#include <iostream>

struct Node
{
  /* data */
  int data;
  Node* prev;
  Node* next;
};

void insertBegining(int data);
void insertTail(int data);
void printList();
void printReverseList();
void reverseList();

Node* head;
int main() {
  head = NULL;
  // insertBegining(4);
  // insertBegining(6);
  // insertBegining(12);
  // insertBegining(18);
  insertTail(19);
  insertTail(20);
  insertTail(21);
  printList();
  // printReverseList();
  return 0;
}

void insertBegining(int data) {
  Node* newNode = (Node*) malloc(sizeof(Node));
  newNode->data = data;
  newNode->prev = NULL;
  newNode->next = NULL;

  if (head == NULL)
  {
    /* code */
    newNode->next = head;
    head = newNode;
    return;
  }
  newNode->next = head;
  head->prev = newNode;
  head = newNode;
}

void printList() {
  Node* temp = head;
  while (temp != NULL)
  {
    /* code */
    std::cout << temp->data << " ";
    temp = temp->next;
  }
  std::cout << "\n";
}

void printReverseList() {
  Node* temp = head;

  while (temp->next != NULL)
  {
    /* code */
    temp = temp->next;
  }
  // temp = temp->prev;
  // std::cout << temp->data;

  while (temp != NULL)
  {
    /* code */
    std::cout << temp->data << " ";
    temp = temp->prev;
  }
  
  std::cout << "\n";
}

void insertTail(int data) {
  Node* newNode = (Node*) malloc(sizeof(Node));
  (*newNode).data = data;
  (*newNode).prev = NULL;
  (*newNode).next = NULL;

  if(head == NULL) {
    (*newNode).next = head;
    head = newNode;
    return;
  }

  Node* temp = head;
  while (temp->next != NULL)
  {
    /* code */
    temp = temp->next;
  }
  temp->next = newNode;
  (*newNode).prev = temp;
  // (*newNode).next = temp->next;
  
}

