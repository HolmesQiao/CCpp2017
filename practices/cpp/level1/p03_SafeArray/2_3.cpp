#include <iostream>
#include <cstdio>

template <class Type> class safeArray{
	public:
		safeArray(int len){this->len = len; array = new Type[len];}
		~safeArray(){delete []array;}
		Type &operator[] (int idx){if (isSafe(idx)) return *(array + idx); return tmp = '\0';}
		bool isSafe(int index);
	private:
		Type *array;
		Type tmp;
		int len;
};

template <class Type>
bool safeArray<Type>::isSafe(int index){
	if (index + 1 > len){
		std::cout << "Out of bound of array, try again!" << std::endl;
		return false;
	}
	return true;
}

int main(void){
	int len;
	std::cout << "Enter the size of array: ";
	std::cin >> len;
	safeArray<char> a(len);
	for (int i = 0; i < len + 5; i++)
		a[i] = 'a'; 
	for (int i = 0; i < len + 5; i++)
		std::cout << a[i] << std::endl;;

	return 0;
}
