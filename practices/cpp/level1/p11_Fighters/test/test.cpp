#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Audio.hpp>
#include "header/data.h"

using namespace std;

int main(){
	//cout << "1" << endl;
	loadDataFile();
	//cout << "2" << endl;
	addItem();
	//cout << "3" << endl;
	sceneScene[0].playMusic();
	exitDataFile();
	while (window.isOpen()){
		sf :: Event event;
		//cout << "AC" << endl;
		while (window.pollEvent(event)){
			if (event.type == sf :: Event :: Closed)
			       window.close();	
			if (event.type == sf :: Event :: KeyPressed){
				sceneScene[0].handleInput(event.key.code, true);
				characterFriend[0].change();
			}
			if (event.type == sf :: Event :: KeyReleased){
				sceneScene[0].handleInput(event.key.code, false);
				characterFriend[0].change();
			}
		}
	}

	return 0;
}
