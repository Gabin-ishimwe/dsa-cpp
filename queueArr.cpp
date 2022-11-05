#include <iostream>

class Queue {
  private:
      int arr[5];
      int front = -1;
      int rear = -1;
  
  public:
      void enQueue(int n) {
        // if(rear == 5-1) { // size of array is full
        if((rear + 1) % 5 == front) { // using circural array
            // 0 == 0 : all space will be full
            std::cout << "queue is full\n";
            return;
        }
        else if(isEmpty()) { // list is empty
          front = 0;
          rear = 0;
          arr[rear] = n;
        }
        else {
          rear += (rear + 1) % 5;
          arr[rear] = n;
        }
      }

      void dequeue() {
        if(front == -1) {
          std::cout << "queue is empty\n";
          return;
        }
        else if(front == rear) {
          front = -1;
          rear = -1;
        }
        else {
          front += 1;
        }
      }

      void printQueue() {
        // int iterations = rear - front;
        for(int i = front ; i <= rear; i++) {
          std::cout << arr[i] << " ";
        }
        std::cout << "\n";
      }

      bool isEmpty() {
        if(front == -1 && rear == -1) {
          return true;
        }
        return false;
      }

};

int main() {
  Queue q;
  q.enQueue(1);
  q.enQueue(2);
  q.enQueue(4);
  q.enQueue(8);
  q.enQueue(81);
  q.enQueue(82);
  q.enQueue(84);
  q.printQueue();
  // q.dequeue();
  // q.printQueue();
  // q.dequeue();
  // q.dequeue();
  // q.dequeue();
  // q.printQueue();
  // q.dequeue();
  // q.printQueue();
  // q.dequeue();

  return 0;
}