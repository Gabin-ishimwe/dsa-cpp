#include <iostream>

struct Node
{
  /* data */
  int data;
  Node *pLink;  // link to next node
};


int main() {
  Node* pHead = nullptr; // starting node (head node)
 
  // creating a memory block to start with
  // Node* pTemp = (Node*) malloc(sizeof(Node));
  // or
  Node* pTemp =  new Node();
  (*pTemp).data = 2; // or temp-> data = 2
  (*pTemp).pLink = NULL; // or temp -> pLink = NULL

  pHead = pTemp;

  pTemp = new Node();
  pTemp->data = 4;
  pTemp->pLink = NULL;

  Node* traversal = pHead;
  while (traversal->pLink != NULL)
  {
  std::cout << traversal->data << "\n";
  traversal = traversal->pLink;
  }
  traversal->pLink = pTemp;  
   
  // while (traversal->pLink != NULL)
  // {
  //   /* code */
  //   std::cout << traversal->data << "\n";
  //   traversal = traversal->pLink;

  // }
  
  return 0 ;
}