#include "Fighting.h"
#include <vector>
#include <cstdlib>
#include <ctime>

//#ifndef DIRECTION
//#define DIRECTION
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
//#endif

/*************************Friend Class**************************/
class Friend : public Fighting{
};

/**************************Enemy Class**************************/
class Enemy : public Fighting{
	public:
		Enemy();
		bool judgeDistence(Friend *hero);
		void moveToFriend(sf :: Vector2f heroPosition);
		void attack(Friend *hero);
	private:
		float live, maxLive;
};

Enemy :: Enemy(){
	live = 0;
	position.x = -100;
	position.y = -100;
}

bool Enemy :: judgeDistence(Friend *hero){
}

void Enemy :: moveToFriend(sf :: Vector2f heroPosition){
	float fX = heroPosition.x;
	float fY = heroPosition.y;
	if (fX <= position.x && fY <= position.y) 
		dir = up;
	else if (fX >= position.x && fY >= position.y)
		dir = down; 
	else if (fX <= position.x && fY >= position.y)
		dir = left; 
	else if (fX >= position.x && fY <= position.y)
		dir = right;
	std :: cout << "-----------------" << dir << "--------------------\n";
	switch (dir){
		case up:
			position.x -= position.x - step / 4 >= 0 ? step / 4 : 0;
			position.y -= position.y - step / 4 >= 0 ? step / 4 : 0;
			s[status].setPosition(position);
			window.draw(s[status]);
			break;
		case down:
			position.x += position.x + step / 4 + edgeX<= windowX ? step / 4 : 0;
			position.y += position.y + step / 4 + edgeY<= windowY ? step / 4 : 0;
			s[status + numRun / 4].setPosition(position);
			window.draw(s[status + numRun / 4]);
			break;
		case left:
			position.x -= position.x - step / 4 >= 0 ? step / 4 : 0;
			position.y += position.y + step / 4 + edgeY<= windowY ? step / 4 : 0;
			s[status + numRun / 2].setPosition(position);
			window.draw(s[status + numRun / 2]);
			break;
		case right:
			position.x += position.x + step / 4 + edgeX <= windowX ? step / 4 : 0;
			position.y -= position.y - step / 4 >= 0 ? step / 4 : 0;
			s[status + numRun / 4 * 3].setPosition(position);
			window.draw(s[status + numRun / 4 * 3]);
			break;
	}
	sf :: Clock clock;
	for (sf :: Time time = clock.getElapsedTime(); time.asSeconds() <= 0.05f; )
		time = clock.getElapsedTime();
}

void Enemy :: attack(Friend *hero){
}

/**************************Magic Class***************************/
class Magic{
	public:
		Magic();
		void createMagic(Friend *magicFromCharacter);
		void move(int magicIndex, Friend*);
		void isAttacking();
		void hurtFriend(Friend fri);
		void hurtEnemy(Enemy ene);
		void loadMagic();
	private:
		sf :: Sprite magic[300][10];
		std :: vector<int> numEachMagic;
		std :: vector<Music> magicMusic;
		std :: vector<int> numEachMusic;
		std :: vector<std :: vector<direction> > eachMagicDir;
		sf :: Vector2f position;
		sf :: Texture tex[100];
		sf :: Sprite sprite;
		bool onScreen;
		int numMagic;
}superMagic;

Magic :: Magic(){
	onScreen = false;
	numMagic = 0;
}

void Magic :: createMagic(Friend *magicFromCharacter){
	onScreen = false;
	Magic :: position = (*magicFromCharacter).position;
}

void Magic :: loadMagic(){
	std :: string path = "Magic/";
	std :: string magicDataPath = path + "data";
	const char *magicDataFile = magicDataPath.c_str();
	std :: cout << "magicDataFile: " <<  magicDataFile << std :: endl;
	FILE *data = fopen(magicDataFile, "r");
	fscanf(data, "%d", &numMagic);
	std :: cout << "numMagic: " << numMagic << std :: endl;
	for (int i = 0; i < numMagic; i++){
		int numiMagic;
		int numMusic;
		fscanf(data, "%d%d", &numiMagic, &numMusic);
		numEachMagic.push_back(numiMagic);
		std :: cout << "numEachmagic: " << numEachMagic[i] << std :: endl;
		//numEachMusic.push_back(numMusic);
	}
	fclose(data);
	for (int i = 0; i < numMagic; i++){
		char magicIndex[2] = {i + '0', '\0'};
		std :: cout << "\n\nmagicIndex:" << magicIndex[i] << std :: endl;
		std :: string MagicPath; 
		std :: cout << MagicPath;
		MagicPath = path + magicIndex + "/"; 
		std :: cout << "magicPath : " << MagicPath << std :: endl;
		for (int j = 0; j < numEachMagic[i]; j++){
			char eachMagic[2] = {j + '0', '\0'};
			std :: string pictureFile = eachMagic;
			pictureFile = pictureFile + ".png";
			std :: string eachPath = MagicPath + pictureFile; 
			std :: cout << "eachPath :" << eachPath << std :: endl;
			tex[i * numEachMagic[i] + j].loadFromFile(eachPath);
			magic[i][j].setTexture(tex[i * numEachMagic[i] + j]);
		}	
	}	
}


void Magic :: move(int magicIndex, Friend* magicFromCharacter){
		for (std :: vector<int> :: size_type i = 0; i < numEachMagic[magicIndex]; i++){
			position = magicFromCharacter->position;
			switch (magicFromCharacter->dir){
				case up:
					position.x -= magicFromCharacter->edgeX + 260;
					position.y -= magicFromCharacter->edgeY + 130;
					break;
				case left:
					position.x -= /*magicFromCharacter->edgeX + */260;
					position.y += /*magicFromCharacter->edgeY + */80;
					break;
				case right: position.x += /*magicFromCharacter->edgeX + */100;
					position.y -= /*magicFromCharacter->edgeY + */200;
					break;
			}
			magic[magicIndex][i].setPosition(position);
			window.draw(magic[magicIndex][i]);
			window.display();
			sf :: Clock clock;
			for (sf :: Time time = clock.getElapsedTime(); time.asSeconds() <= 0.04; time = clock.getElapsedTime());
		}
}
