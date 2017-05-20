#include <cstdlib>
#include <ctime>

class Fighting : public Character{
	public:
		Fighting();
		void playFightMedia(Scene *scene/*, direction Dir*/);
	//	void attack(sf :: Keyboard :: Key key, bool isPressed); 
		void loadFightingData(std :: string path);
		bool judgeFighting(sf :: Vector2f otherPosition, float otherEdgeX, float otherEdgeY);
	private:
		float live;
		float maxLive;
		float strength;
		float defence;
		int numMagic;
		int eachImage;
		std :: vector<float> hurtNumber;
};

Fighting :: Fighting(){
	live = 100.f;
	maxLive = 100.f;
	strength = 10.f;
	defence = 5.f; 
	numMagic = 1;
	eachImage = 6;
}

void Fighting :: loadFightingData(std :: string path){
	loadCharacter(path);
	std :: cout << "===========loadFightingdata==========\n";
	std :: string dataPath = path + "/fight/data";
	const char *dataP = dataPath.c_str();
	FILE *fightData = fopen(dataP, "r");
	std :: cout << "fight data" << dataP << "\n"; 
	fscanf(fightData, "%f%f%f%d", &maxLive, &strength, &defence, &numMagic);
	eachImage = numFight / numMagic;
	for (int i = 0; i < numMagic; i++){
		float hurt;
		fscanf(fightData, "%f", &hurt);
		hurtNumber.push_back(hurt);
	}
	fclose(fightData);
	path = path + "/fight/";
	path = path + "music.wav";
	loadMusic(path);
}

bool Fighting :: judgeFighting(sf :: Vector2f otherPosition, float otherEdgeX, float otherEdgeY){
	return (otherPosition.x >= position.x && otherPosition.y >= position.y && otherPosition.x <= position.x + edgeX && otherPosition.y <= position.y + edgeY);
}

void Fighting :: playFightMedia(Scene *scene/*, direction Dir*/){
	direction Dir = scene->dir;
	srand((unsigned) time(NULL));
	std :: cout << "attack" << std :: endl;
	std :: cout << "eachImage: " << eachImage << std :: endl;
	int magic = rand() % numMagic;
	for (int i = 0; i < eachImage; i++){
		window.clear();
		scene->sprite.setPosition(scene->position);
		window.draw(scene->sprite);
		switch (Dir){
			case up:
				s[numRun + i].setPosition(position.x - fightSizeX + edgeX - 80, position.y - fightSizeY + edgeY - 60); 
				break;
			case down:
				s[numRun + i].setPosition(position.x - fightSizeX, position.y - fightSizeY);
				//s[numRun + i].setRotation(180);
				break;
			case left:
				s[numRun + i].setPosition(position.x - fightSizeX, position.y - fightSizeY);
				//s[numRun + i].setRotation(270);
				break;
			case right:
				s[numRun + i].setPosition(position.x - fightSizeX, position.y - fightSizeY);
				//s[numRun + i].setRotation(90);
				break;
		}
		window.draw(s[numRun + i]);
		window.display();
		sf :: Clock clock;
		for (sf :: Time time = clock.getElapsedTime(); time.asSeconds() <= 0.1f;)
			time = clock.getElapsedTime();
		}
	//isMovingUp = isMovingDown = isMovingLeft = isMovingDown = false;
}
