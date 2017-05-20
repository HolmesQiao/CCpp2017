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

//declartion
void loadDataFile();
void exitDataFile();
void addItem();

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
