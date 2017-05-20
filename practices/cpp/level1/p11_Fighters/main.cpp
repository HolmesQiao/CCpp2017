#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Audio.hpp>
#include "header/Script.h"

using namespace std;

int main(){
	cout << "******************main*1******************" << endl;
	loadDataFile();
	cout << "******************main*2******************" << endl;
	addItem();
	cout << "******************main*3******************" << endl;
	exitDataFile();
	superMagic.loadMagic();
	cout << "******************main*4******************" << endl;
	Script();
		return 0;
}
