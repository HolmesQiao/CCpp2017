#include "Item.h"
#include "Music.h"
#include "Scene.h"
#include "Character.h"
#include "FriendAndEnemy.h"
//#include "Fighting.h"
#include <queue>

int numFriend, numEnemy, numScene;
float windowWidth, windowHeight;
FILE *friendFile, *enemyFile, *sceneFile, *dataFile;
Friend *characterFriend;
Enemy *characterEnemy;
Scene *sceneScene;
std :: queue<std :: string> allFriendPath, allEnemyPath, allScenePath;
sf :: Texture endTexture;
sf :: Sprite endSprite;

//declartion
void loadDataFile();
void exitDataFile();
void addItem();
void playBeginVideo();

void playBeginVideo(){
	std :: string beginPath = "begin/video/";

	sf :: Texture te, te_1;
	sf :: Sprite sp, sp_1;
	sf :: SoundBuffer buffer;
	sf :: Sound sound;
	buffer.loadFromFile("begin/video/music.wav");
	sound.setBuffer(buffer);
	sound.play();
	for (int i = 1; i <= 920; i++){
		sf :: Event event;
		while (window.pollEvent(event))
			if (event.type == sf :: Event :: Closed)
			       window.close();

		window.clear();
		int hun = i / 100 + '0', ten = i % 100 / 10 + '0', dig = i % 10 + '0';
		char q[4] = {hun, ten, dig, '\0'};
		std :: string Image = q; Image += ".png"; 
		te.loadFromFile(beginPath + Image);
		sp.setTexture(te);
		sp.setPosition(0, 60.5f);
		window.draw(sp);
		window.display();
	}
	te_1.loadFromFile("begin/begin.png");
	sp_1.setTexture(te_1);
	sp_1.setPosition(0.0f, 85.0f);
	sf :: Event event;
	window.draw(sp_1);
	window.display();
	sf :: Clock clock;
	for (sf :: Time time = clock.getElapsedTime(); time.asSeconds() <= 3; time = clock.getElapsedTime());
	sound.stop();
}

//definition
void loadDataFile(){
	friendFile = fopen("data/friendFile", "r");
	enemyFile = fopen("data/enemyFile", "r");
	sceneFile = fopen("data/sceneFile", "r");
	dataFile = fopen("data/gameFile", "r");
	fscanf(friendFile, "%d", &numFriend);
	std :: cout << numFriend << std :: endl; //debug
	fscanf(enemyFile, "%d", &numEnemy);
	std :: cout << numEnemy << std :: endl; //debug
	fscanf(sceneFile, "%d", &numScene); 
	std :: cout << numScene << std :: endl; //debug
	characterFriend = new Friend[numFriend];
	std :: cout << "firend build" << std :: endl;//de
	characterEnemy = new Enemy[numEnemy];
	std :: cout << "enemy build" << std :: endl;//de
	sceneScene = new Scene[numScene];
	std :: cout << "scene build" << std :: endl;//de
	for (int i = 0; i < numFriend; i++){
		char path[15];
		fscanf(friendFile, "%s", path);
		allFriendPath.push(path);
		std :: cout << allFriendPath.front() << std :: endl;//debug
	}
	for (int i = 0; i < numEnemy; i++){
		char path[15];
		fscanf(enemyFile, "%s", path);
		allEnemyPath.push(path);
		std :: cout << allEnemyPath.front() << std :: endl; //debug
	}
	for (int i = 0; i < numScene; i++){
		char path[15];
		fscanf(sceneFile, "%s", path);
		allScenePath.push(path);
		std :: cout << allScenePath.front() << std :: endl;
	}
}

void exitDataFile(){
	fclose(friendFile);
	fclose(enemyFile);
	fclose(sceneFile);
	fclose(dataFile);
}

void addItem(){
	endTexture.loadFromFile("data/end.png");
	endSprite.setTexture(endTexture);
	std :: cout << "**********************addItem*1************************\n";
	for (int i = 0; i < numFriend; i++){
		characterFriend[i].loadFightingData(allFriendPath.front());
		allFriendPath.pop();
	}
	std :: cout << "**********************addItem*2***********************\n";
	for (int i = 0; i < numEnemy; i++){
		characterEnemy[i].loadFightingData(allEnemyPath.front());
		allEnemyPath.pop();
	}
	std :: cout << "*********************addItem*3************************\n";
	for (int i = 0; i < numScene; i++){
		sceneScene[i].loadScene(allScenePath.front());
		allScenePath.pop();
	}
}

bool changeScene(int rank, const Friend hero){
	double outX = sceneScene[rank].outX, outY = sceneScene[rank].outY;
	switch (sceneScene[rank].outDir){
		case 1:
			if (hero.position.x < outX && hero.position.y < outY)
				return true;
			else	return false;
		case 2:
			if (hero.position.x + hero.edgeX > outX && hero.position.y < outY)
				return true;
			else 	return false;
		case 3:
			if (hero.position.x < outX && hero.position.y + hero.edgeY > outY)
				return true;
			else 	return false;
		case 4:
			if (hero.position.x + hero.edgeX > outX && hero.position.y + hero.edgeY > outY)
				return true;
			else	return false;
	}
}
