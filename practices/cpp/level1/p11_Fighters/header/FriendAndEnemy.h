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
		void moveToFriend(sf :: Vector2f heroPosition, sf :: Vector2f shouldMove);
		bool attackFriend(Friend *hero);
};

/*************************Magic Class***************************/
class Magic{
	public:
		Magic();
		void createMagic(Friend *magicFromCharacter);
		void move(int magicIndex, sf :: Vector2f objPosition, sf :: Vector2f edge, direction Dir, int magicStatus);
		void isAttacking();
		void hurtFriend(Friend fri);
		void hurtEnemy(Enemy ene);
		void loadMagic();
		void playMagicMusic(int magicIndex);
		sf :: Vector2f position;
	private:
		sf :: Sprite magic[30][10];
		sf :: Texture tex[300];
		sf :: SoundBuffer magicSoundBuffer[30];
		sf :: Sound magicSound[30];
		std :: vector<int> numEachMagic;
		std :: vector<std :: vector<direction> > eachMagicDir;
		sf :: Sprite sprite;
		bool onScreen;
		int numMagic;
}superMagic;


/************************Enemy class****************************/
/***************************************************************/
Enemy :: Enemy(){
	live = 0;
	position.x = -100;
	position.y = -100;
}

bool Enemy :: attackFriend(Friend *hero){
	bool shouldAttack = hero->position.x <= position.x+edgeX && hero->position.y <= position.y+edgeY && hero->position.x + hero->edgeX+20 >= position.x && hero->position.y + hero->edgeY+20 >= position.y;
	if (shouldAttack){
		switch(dir){
			case up:
				position.x += step / 2;
				position.y += step / 4;
				break;
			case down:
				position.x -= step / 2;
				position.y -= step / 2;
				break;
			case left:
				position.x += step / 2;
				position.y -= step / 2;
				break;
			case right:
				position.x -= step / 2;
				position.y += step / 2;
		}
		return true;
	}
	return false;
}

void Enemy :: moveToFriend(sf :: Vector2f heroPosition, sf :: Vector2f shouldMove){
	srand((unsigned) time(NULL));
	bool still;
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
	if (rand() % 10 < 1)
		still = true;
	std :: cout << "===================================================\n";
	std :: cout << "-----------------" << dir << "--------------------\n";
	std :: cout << shouldMove.x << std :: endl;
	std :: cout << shouldMove.y << std :: endl;
	position.x += shouldMove.x;
	position.y += shouldMove.y;
	switch (dir){
		case up:
			if (!still){
				position.x -= position.x - step / 2 >= 0 ? step / 2 : 0;
				position.y -= position.y - step / 4 >= 0 ? step / 4 : 0;
			}
			s[status].setPosition(position);
			window.draw(s[status]);
			break;
		case down:
			if (!still){
				position.x += position.x + step / 2 + edgeX<= windowX ? step / 2 : 0;
				position.y += position.y + step / 2 + edgeY<= windowY ? step / 2 : 0;
			}
			s[status + numRun / 4].setPosition(position);
			window.draw(s[status + numRun / 4]);
			break;
		case left:
			if (!still){
				position.x -= position.x - step / 2 >= 0 ? step / 2 : 0;
				position.y += position.y + step / 2 + edgeY<= windowY ? step / 2 : 0;
			}
			s[status + numRun / 2].setPosition(position);
			window.draw(s[status + numRun / 2]);
			break;
		case right:
			if (!still){
				position.x += position.x + step / 2 + edgeX <= windowX ? step / 2 : 0;
				position.y -= position.y - step / 2 >= 0 ? step / 2 : 0;
			}
			s[status + numRun / 4 * 3].setPosition(position);
			window.draw(s[status + numRun / 4 * 3]);
			break;
	}
	//sf :: Clock clock;
	//for (sf :: Time time = clock.getElapsedTime(); time.asSeconds() <= 0.05f; )
		//time = clock.getElapsedTime();
	status = (status + 1) % (numRun / 4);
}

/**************************Magic Class***************************/
/****************************************************************/

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
	}
	fclose(data);
	for (int i = 0; i < numMagic; i++){
		char magicIndex[2] = {i + '0', '\0'};
		std :: cout << "\n\nmagicIndex:" << magicIndex[i] << std :: endl;
		std :: string MagicPath; 
		std :: string MusicPath;
		std :: cout << MagicPath;
		MusicPath = path + magicIndex + "/music.wav";
		magicSoundBuffer[i].loadFromFile(MusicPath);
		magicSound[i].setBuffer(magicSoundBuffer[i]);
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


void Magic :: move(int magicIndex, sf :: Vector2f objPosition, sf :: Vector2f edge, direction Dir, int magicStatus){
	//std :: cout << "play magic---------------" << magicIndex << "=============" << numEachMagic[magicIndex] << "\n";
	if (magicStatus == 0)
		superMagic.playMagicMusic(magicIndex);
	for (std :: vector<int> :: size_type i = 0; i < numEachMagic[magicIndex]; i++){
		position = objPosition;
		switch (Dir){
			case up:
				position.x -= edge.x + 100;
				position.y -= edge.y + 50;
				break;
			case down:
				position.x += edge.x;// + 60;
				position.y += edge.y;// + 17;
				break;
			case left:
				position.x -= 120;
				position.y += 40;
				break;
			case right: 
				position.x += edge.x;
				position.y -= edge.y;
				break;
		}
		std :: cout << "*****************" << magicIndex << "---------" << i << "\n";
		magic[magicIndex][i].setPosition(position);
		window.draw(magic[magicIndex][i]);
		window.display();
		/*sf :: Clock clock;
		for (sf :: Time time = clock.getElapsedTime(); time.asSeconds() <= 0.1; time = clock.getElapsedTime());
		*/
	}
}

void Magic :: playMagicMusic(int magicIndex){
	magicSound[magicIndex].play();
}
