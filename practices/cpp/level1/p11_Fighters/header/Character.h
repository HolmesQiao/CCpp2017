//#include "FriendAndEnemy.h"
#ifndef windowX
#define windowX 1000.f 
#endif
#ifndef windowY
#define windowY 700.f
#endif

class Character : public Music{
	public:
		Character();
		void loadCharacter(std :: string path);
		void change(Scene *nScene);
		void playDieMedia(Scene *sceneN);
		int numRun, numFight, numDie;
		bool shouldBack;
		bool isDie(sf :: Vector2f magicPosition, float magicEdgeX, float magicEdgeY, float hurt);
		float fightSizeX, fightSizeY;
		sf :: Sprite *s;
		float live, maxLive;
		std :: string characterPath;
	private:
		sf :: Texture *tex;
};

Character :: Character(){
	position.x = 500.f;
	position.y = 380.f;
	sprite.setPosition(position);
	shouldBack = false;
}

void Character :: playDieMedia(Scene *sceneN){
	std :: string diePath = characterPath + "die/";
	loadMusic(diePath + "music.wav");
	playMusic();

	sf :: Texture te;
	sf :: Sprite sp;
	for (int i = 1; i <= numDie; i++){
		window.clear();
		int hun = i / 100 + '0', ten = i % 100 / 10 + '0', dig = i % 10 + '0';
		char q[4] = {hun, ten, dig, '\0'};
		std :: string Image = q; Image += ".png"; 
		te.loadFromFile(diePath + Image);
		sp.setTexture(te);
		sp.setPosition(position);
		window.draw(sceneN->sprite);
		window.draw(sp);
		window.display();
	}
	stop();
}

bool Character :: isDie(sf :: Vector2f magicPosition, float magicEdgeX, float magicEdgeY, float hurt ){
	if (magicPosition.x <= position.x && magicPosition.y <= position.y && magicPosition.x + magicEdgeX > position.x && magicPosition.y + magicEdgeY > position.y)
		live -= hurt;
	return live <= 0;
}

void Character :: loadCharacter(std :: string path){
	std :: cout << "==============loadCharacter===========\n";
	characterPath = path;
	std :: cout << "path" << path << "\n";
	std :: string data = path + "data";
	const char *cData = data.c_str();
	FILE *imageFile = fopen(cData, "r");
	float priX, priY;
	fscanf(imageFile, "%f%f%d%d%d%f%f%f%f%f", &priX, &priY, &numRun, &numFight, &numDie, &edgeX, &edgeY, &fightSizeX, &fightSizeY, &maxLive);
	fclose(imageFile);
	position.x = priX;
	position.y = priY;
	live = maxLive;
	tex = new sf :: Texture[numRun + numFight];
	s = new sf :: Sprite[numRun + numFight];
	for (int i = 0; i < numRun + numFight/* + numDie*/; i++){
		char p[2] = {i % 9 + '1'};
		std :: string Image = p; Image = Image +".png";
		if (i < numRun / 4){
			tex[i].loadFromFile(path + "1/" + Image); 
			//debug
			std :: cout << path + "1/" + Image << "\n";
		}
		else if (i < numRun / 2){
			tex[i].loadFromFile(path + "2/" + Image);
			//debug
			std :: cout << path + "2/" + Image << "\n";
		}
		else if (i < (numRun / 4 * 3)){
			tex[i].loadFromFile(path + "3/" + Image);
			//debug
			std :: cout << path + "3/" + Image << "\n";
		}
		else if (i < numRun){
			tex[i].loadFromFile(path + "4/" + Image);
			//debug
			std :: cout << path + "4/" + Image << "\n";
		}
		else if (i < numRun + numFight){
			tex[i].loadFromFile(path + "fight/" + Image);
		}
		s[i].setTexture(tex[i]);
	}
	for (int i = 0; i < numRun + numFight/* + numDie*/; i++)
		s[i].setPosition(position);
	//debug
	std :: cout << "\n";
}

void Character :: change(Scene *nScene){
	bool inEdge = nScene->inEdge;
	status = status % (numRun / 4);
	dir = nScene->dir;
	if ((!isMovingUp) & (!isMovingDown) & (!isMovingLeft) & (!isMovingRight))
		status = 0;
	switch (dir){
		case up:
			if (!inEdge){
				position.x -= position.x - step / 3 * 2 >= 0 ? step / 3 * 2 : 0;
				position.y -= position.y - step / 3 * 2 >= 0 ? step / 3 * 2 : 0;
			}
			s[status].setPosition(position);
			window.draw(s[status]);
			break;
		case down:
			if (!inEdge){
				position.x += position.x + step / 3 * 2 + edgeX<= windowX ? step / 3 * 2 : 0;
				position.y += position.y + step / 3 * 2 + edgeY<= windowY ? step / 3 * 2 : 0;
			}
			s[status + numRun / 4].setPosition(position);
			window.draw(s[status + numRun / 4]);
			break;
		case left:
			if (!inEdge){
				position.x -= position.x - step / 3 * 2 >= 0 ? step / 3 * 2 : 0;
				position.y += position.y + step / 3 * 2 + edgeY<= windowY ? step / 3 * 2 : 0;
			}
			s[status + numRun / 2].setPosition(position);
			window.draw(s[status + numRun / 2]);
			break;
		case right:
			if (!inEdge){
				position.x += position.x + step / 3 * 2 + edgeX <= windowX ? step / 3 * 2 : 0;
				position.y -= position.y - step / 3 * 2 >= 0 ? step / 3 * 2 : 0;
			}
			s[status + numRun / 4 * 3].setPosition(position);
			window.draw(s[status + numRun / 4 * 3]);
			break;
	}
	//sf :: Clock clock;
	/*for (sf :: Time time = clock.getElapsedTime(); time.asSeconds() <= 0.02f; )
	time = clock.getElapsedTime();
	*/
	//window.display();
	if (position.x == 500 && position.y == 380) shouldBack = false; 
	status++;
}
