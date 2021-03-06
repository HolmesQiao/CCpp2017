#include <iostream>
#include <cstdio>
#include <cstdlib>

#define STACK_SIZE 100

using namespace std;

class IntStack{
	public:
		void append(int value);
		void pop();
		bool isEmpty();
		bool isFull();
		IntStack(): top(-1) {}
	private:
		int top;
		int stack[STACK_SIZE];
};

void IntStack :: append(int value)
{
	if (isFull()){
		char cmd;

		cout << "\nThe stack is full,if you still wanner store this value,you must pop the top value,store it?(y / n): ";
		cin >> cmd;
		if (cmd == 'y'){
			pop();
			top++;
			stack[top] = value;
		}
		return;
	}
	top++;
	stack[top] = value;
}

void IntStack :: pop()
{
	if (isEmpty()){
		cout << "\nThe stack is empty, there is no data to pop!" << endl;
		return;
	}
	cout << "The value is: " << stack[top] << endl;
	top--;
}

bool IntStack :: isEmpty()
{
	if (top == -1)
		return true;
	return false;
}

bool IntStack :: isFull()
{
	if (top == STACK_SIZE - 1)
		return true;
	return false;
}

int main(void)
{
	IntStack cIntStack;
	
	for (;;){
		char cmd;

		cout << "\n'a':(append), 'p':(pop), 'e':(is empty?), 'f':(is full?), 'q':(quit)" << endl;
		cout << "Input oprator to the int stack: " << endl;
		cin >> cmd;
		switch (cmd){
			case 'a' :
				int value;
				cout << "\nEnter the value you wanner store: ";
				cin >> value;
				cIntStack.append(value);
				break;
			case 'p' :
				cIntStack.pop();
				break;
			case 'e' :
				if (cIntStack.isEmpty()){
					cout << "\nThe stack is empty" << endl;
					break;
				}
				cout << "\nThe stack is not empty" << endl;
				break;
			case 'f' :
				if (cIntStack.isFull()){
					cout << "\nThe stack is full" << endl;
					break;
				}
				cout << "\nThe stack is not full" << endl;
				break;
			case 'q' :
				return 0;
		}
	}
}
