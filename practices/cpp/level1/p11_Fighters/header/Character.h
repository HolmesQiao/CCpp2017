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
		int numRun, numFight;
		bool shouldBack;
		float fightSizeX, fightSizeY;
		sf :: Sprite *s;
	private:
		sf :: Texture *tex;
	};

Character :: Character(){
	position.x = 500.f;
	position.y = 380.f;
	sprite.setPosition(position);
	shouldBack = false;
}

void Character :: loadCharacter(std :: string path){
	std :: cout << "==============loadCharacter===========\n";
	std :: cout << "path" << path << "\n";
	std :: string data = path + "data";
	const char *cData = data.c_str();
	FILE *imageFile = fopen(cData, "r");
	fscanf(imageFile, "%d%d%f%f%f%f", &numRun, &numFight, &edgeX, &edgeY, &fightSizeX, &fightSizeY);
	fclose(imageFile);
	tex = new sf :: Texture[numRun + numFight];
	s = new sf :: Sprite[numRun + numFight];
	for (int i = 0; i < numRun + numFight; i++){
		char p[1] = {i % 9 + '1'};
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
		else
			tex[i].loadFromFile(path + "fight/" + Image);
		s[i].setTexture(tex[i]);
	}
	for (int i = 0; i < numRun + numFight; i++)
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
	sf :: Clock clock;
	for (sf :: Time time = clock.getElapsedTime(); time.asSeconds() <= 0.05f; )
		time = clock.getElapsedTime();
	//window.display();
	if (position.x == 500 && position.y == 380) shouldBack = false; 
	status++;
}
