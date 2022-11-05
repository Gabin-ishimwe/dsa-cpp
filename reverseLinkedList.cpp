#include <iostream>

struct Node
{
  /* data */
  int data;
  Node* next;
};

void insertNode(int data, int n, Node** head);
void printNodes(Node** head);
Node* reverseList(Node* head);
void printRecursion(Node* head);
Node* reverseListRecursion(Node* head);

// Node* head;
int main() {
  Node* head = NULL;
  insertNode(2, 1, &head);
  insertNode(4, 2, &head);
  insertNode(5, 3, &head);
  insertNode(7, 4, &head);
  printNodes(&head);
  // head = reverseList(head);
  head = reverseListRecursion(head);
  // printNodes();
  printRecursion(head); // takes in a copy of head

  return 0;
}

void insertNode(int data, int n, Node** head) {
  Node* temp = new Node();
  temp->data = data;
  temp->next = NULL;
  if(n == 1) {
    temp->next = *head;
    *head = temp;
    return;
  }

  Node* temp1 = *head;
  for(int i = 0; i < n-2; i++) {
    temp1 = temp1->next;
  }

  temp->next = temp1->next;
  temp1->next = temp;
  // return head;
}

void printNodes(Node** head) {
  Node* traversal = *head;
  while (traversal != NULL)
  {
    /* code */
    std::cout << traversal->data << " ";
    traversal = traversal->next;
  }
  std::cout << "\n";
  
}

Node* reverseList(Node* head) {
  Node *current, *prev, *next;
  current = head;
  prev = NULL;
  while (current != NULL)
  {
    /* code */
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  head = prev;

  return head;
  
}

void printRecursion(Node* head) {
  if(head == NULL) return;
  printRecursion(head->next);
  std::cout << head->data << " ";
}

Node* reverseListRecursion(Node* traversalNode) {
  if(traversalNode->next == NULL) {
    return traversalNode;
  }
  reverseListRecursion(traversalNode->next);
  Node* temp = traversalNode->next;
  temp->next = traversalNode;
  traversalNode->next = NULL;
}