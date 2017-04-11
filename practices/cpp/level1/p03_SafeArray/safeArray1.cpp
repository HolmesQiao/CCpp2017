#include <iostream>
#include <cstdio>

using namespace std;

bool isSafe(int *a, int index, int len);
void rArray(int *a, int len);
void wArray(int *a, int len);

int main(void)
{
	int *a, len;

	cout << "Enter the size of array: ";
	//cin >> len;
	cout << len << endl;                //debug
	a = new int[len];
	for (int i = 0; i < len; i++)
		a[i] = 0;
	while (1){
		char cmd;
		cout << "Enter the operator to array:(r/w/e)  ";
		cin >> cmd;
		//cout << cmd << endl;       //debug;
		switch (cmd){
			case 'r':
				rArray(a, len);
				break;
			case 'w':
				wArray(a, len);
				break;
			case 'e':
				delete [] a;
				return 0;
			default:
				cout << "Illegal command, input again!" << endl;
				break;
		}
	}
}

bool isSafe(int *a, int index, int len)
{
	if (index + 1 > len){
		cout << "Out of bound of array, try again!" << endl;
		return false;
	}
	return true;
}

void rArray(int *a, int len)
{
	int index;

	cout << "Enter the index of array that you want to read" << endl;
	cout << "Index is begain to zero." << endl;
	cout << "Input: ";
	cin >> index;
	//cout << index;                //debug
	if (isSafe(a, index, len)){
		cout << "The value of this data is " << a[index] << endl;
	}
}

void wArray(int *a, int len)
{
	int value, index;

	cout << "Enter the value and index (store value to array[index]." << endl;
	cout << "Index is begain to zero" << endl;
	cout << "Input: ";
	cin >> value >> index;
	cout << "value & index:" << value << index;  //debug
	if (isSafe(a, index, len)){
		a[index] = value;
	}
}
