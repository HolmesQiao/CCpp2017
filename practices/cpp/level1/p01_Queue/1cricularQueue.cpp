#include <iostream>
#include <cstdio>
#include <cstdlib>

#define QUEUE_SIZE 100

using namespace std;

class Queue{
	public:
		void append(int value);
		int pop();
		bool isEmpty();
		bool isFull();
		Queue(): front(0), rear(0) { }
	private:
		int front, rear;
		int queue[QUEUE_SIZE];
};

void Queue :: append(int value)
{
	if (isFull()){
		char cmd;

		cout << "\nThe queue is full,do you still wanner store this value?(y / n): ";
		cin >> cmd;
		if (cmd == 'y'){
			pop();
			queue[rear] = value;
			rear = (rear + 1) % QUEUE_SIZE;
		}
		return;
	}
	queue[rear] = value;
	rear = (rear + 1) % QUEUE_SIZE;
}

int Queue :: pop()
{
	int frontValue;
	if (isEmpty()){
		cout << "\nThe queue is empty, there is no data to pop!" << endl;
		return 0;
	}
	cout << "The value is: " << queue[front] << endl;
	frontValue = queue[front];
	front = (front + 1) % QUEUE_SIZE;
	
	return frontValue;
}

bool Queue :: isEmpty()
{
	if (front == rear)
		return true;
	return false;
}

bool Queue :: isFull()
{
	if ((rear + 1) % QUEUE_SIZE == (front - 1) % QUEUE_SIZE)
		return true;
	return false;
}

int main(void)
{
	Queue cQueue;
	
	for (;;){
		char cmd;

		cout << "\n'a':(append), 'p':(pop), 'e':(is empty?), 'f':(is full?), 'q':(quit)" << endl;
		cout << "Input oprator to the circular queue: " << endl;
		cin >> cmd;
		switch (cmd){
			case 'a' :
				int value;
				cout << "\nEnter the value you wanner store: ";
				cin >> value;
				cQueue.append(value);
				break;
			case 'p' :
				cQueue.pop();
				break;
			case 'e' :
				if (cQueue.isEmpty()){
					cout << "\nThe queue is empty" << endl;
					break;
				}
				cout << "\nThe queue is not empty" << endl;
				break;
			case 'f' :
				if (cQueue.isFull()){
					cout << "\nThe queue is full" << endl;
					break;
				}
				cout << "\nThe queue is not full" << endl;
				break;
			case 'q' :
				return 0;
		}
	}
}
