#include <iostream>

class QueueLinkedList {
  private:
      struct Node {
        int data;
        Node* next;
      };
      Node* top = NULL;
      Node* rear = NULL;
  public:
      void enQueue(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = NULL;
        if(top == NULL && rear == NULL) {
          top = rear = newNode;
          return;
        }
        rear->next = newNode;
        rear = newNode;
      }

      void dequeue() {
        Node* temp = top;
        if(top == NULL && rear == NULL) {
          std::cout << "queue is empty\n";
          return;
        }
        else if (top == rear) {
          top = rear = NULL;
          delete temp;
        }
        else {
          top = top->next;
          delete temp;
        }
      }

      void print() {
        Node* traversal = top;
        while(traversal != NULL) {
          std::cout << traversal->data << " ";
          traversal = traversal->next;
        }
        std::cout << "\n";
      }

      void atTop() {
        std::cout << top->data << "\n";
      }
};

int main() {
  QueueLinkedList q;
  q.enQueue(4);
  q.enQueue(5);
  q.enQueue(6);
  q.enQueue(8);
  q.print();
  q.dequeue();
  q.atTop();
  q.dequeue();
  q.print();
  q.atTop();
  return 0;
}