#include <iostream>

class Stack {
  public:
      struct Node {
        int data;
        Node* next;
      };
      Node* head = NULL;

      void push(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = head;
        head = newNode;
      }

      void pop() {
        // Node* starting = head;
        if(head == NULL) {
          std::cout << "the stack is empty...";
          return;
        }
        Node* temp = head;
        head = temp->next;
        delete temp;
      }

      void print() {
        Node* temp = head;
        while(temp != NULL) {
          std::cout << temp->data << " ";
          temp = temp->next;
        }
        std::cout << "\n";
      }
};

int main() {
  Stack stack;
  stack.push(1);
  stack.push(2);
  stack.push(3);
  stack.push(4);
  stack.print();
  stack.pop();
  stack.pop();
  stack.pop();
  stack.pop();
  stack.pop();
  stack.print();

  return 0;
}