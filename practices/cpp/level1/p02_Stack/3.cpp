#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

template <class Type> class Stack{
	public:
		void append(Type value);
		void pop();
		bool isEmpty();
		bool isFull();
		Stack(int len=0): top(-1) {this->len = len; stack = new Type[len];}
		~Stack(){delete []stack;}
	private:
		int top;
		Type *stack;
		int len;
};

template <class Type>
void Stack<Type> :: append(Type value)
{
	if (isFull()){
		char cmd;

		cout << "\n******************************************************************************************************" << endl;
		cout << "The stack is full,if you still wanner store this value,you must pop the top value,store it?(y / n): ";
		cout << "******************************************************************************************************" << endl;
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

template <class Type>
void Stack<Type> :: pop()
{
	if (isEmpty()){
		cout << "\n**********************************************" << endl;
		cout << "The stack is empty, there is no data to pop!" << endl;
		cout << "**********************************************" << endl;
		return;
	}
	cout << "\n****************" << endl;
	cout << "The value is: " << stack[top] << endl;
	cout << "****************" << endl;
	top--;
}

template <class Type>
bool Stack<Type> :: isEmpty()
{
	if (top == -1)
		return true;
	return false;
}

template <class Type>
bool Stack<Type> :: isFull()
{
	if (top == len - 1)
		return true;
	return false;
}

int main(void)
{
	int len;
	cout << "Enter the size of stack: ";
	cin >> len;
	Stack<int> intStack(len);
	Stack<char> charStack(len);
	for (;;){
		char type;
		char cmd;
		cout << "Enter the type you wanner operator(i/ c):";
		cin >> type;
		cout << "\n'a':(append), 'p':(pop), 'e':(is empty?), 'f':(is full?), 'q':(quit)" << endl;
		cout << "Input oprator to the int stack: " << endl;
		cin >> cmd;
		switch(type){
			case 'i':
				switch (cmd){
					case 'a' :
						int value;
						cout << "\nEnter the value you wanner store: ";
						cin >> value;
						intStack.append(value);
						break;
					case 'p' :
						intStack.pop();
						break;
					case 'e' :
						if (intStack.isEmpty()){
							cout << "\nThe stack is empty" << endl;
							break;
						}
						cout << "\nThe stack is not empty" << endl;
						break;
					case 'f' :
						if (intStack.isFull()){
							cout << "\nThe stack is full" << endl;
							break;
						}
						cout << "\nThe stack is not full" << endl;
						break;
					case 'q' :
						return 0;
				}
				break;
			case 'c':
				switch (cmd){
					case 'a' :
						int value;
						cout << "\nEnter the value you wanner store: ";
						cin >> value;
						charStack.append(value);
						break;
					case 'p' :
						charStack.pop();
						break;
					case 'e' :
						if (charStack.isEmpty()){
							cout << "\nThe stack is empty" << endl;
							break;
						}
						cout << "\nThe stack is not empty" << endl;
						break;
					case 'f' :
						if (charStack.isFull()){
							cout << "\nThe stack is full" << endl;
							break;
						}
						cout << "\nThe stack is not full" << endl;
						break;
					case 'q' :
						return 0;
				}
				break;
		}
	}

	return 0;
}
