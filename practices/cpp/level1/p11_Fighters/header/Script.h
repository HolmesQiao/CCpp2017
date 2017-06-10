#include "data.h"

void playMagic(int magicIndex, sf :: Vector2f ogjePosition, sf :: Vector2f edge, direction dir, int magicStatus);
bool changeScene(int sceneRank, const Friend hero);
void priData();
void talk(int rank, Scene *sceneN);

void Script(){
	sf :: Vector2f shouldMove;
	int magicStatus(0);
	double outX = sceneScene[0].outX, outY = sceneScene[0].outY;
	bool alreadyDie(true); playBeginVideo(); priData(); while (window.isOpen()){ sf :: Event event;
		while (window.pollEvent(event)){
			if (event.type == sf :: Event :: Closed)
			       window.close();
		}
		if (changeScene(sceneRank, characterFriend[friendRank]) && alreadyDie){
			sceneScene[sceneRank].stop();
			sceneRank++;
			sceneScene[sceneRank].playMusic();
			characterEnemy[enemyRank].onScreen = true;
			alreadyDie = false;
			if (sceneRank >= 5){
				characterFriend[friendRank].onScreen = false;
				characterEnemy[enemyRank].onScreen = false;
				friendRank++;
				characterFriend[friendRank].onScreen = true;
				alreadyDie = true;
			}
			talk(sceneRank, &sceneScene[sceneRank]);
		}
		sf :: Vector2f objPosition = characterFriend[friendRank].position;
		sf :: Vector2f edge;
		edge.x = characterFriend[friendRank].edgeX;
		edge.y = characterFriend[friendRank].edgeY;
		if (characterFriend[friendRank].onScreen){
			if (sf :: Keyboard :: isKeyPressed(sf :: Keyboard :: J)){
				characterFriend[friendRank].playFightMedia(&sceneScene[sceneRank]);
				characterEnemy[enemyRank].live -= 5;
			}
			if (sf :: Keyboard :: isKeyPressed(sf :: Keyboard :: K)){
				superMagic.move(0, objPosition, edge, characterFriend[0].dir, 0);
				if (!alreadyDie)
					characterEnemy[enemyRank].live -= 5;
			}
			if (sf :: Keyboard :: isKeyPressed(sf :: Keyboard :: U)){
				superMagic.move(1, objPosition, edge, characterFriend[0].dir, 0);
				if (!alreadyDie)
					characterEnemy[enemyRank].live -= 5;
			}
			if (sf :: Keyboard :: isKeyPressed(sf :: Keyboard :: L)){
				superMagic.move(2, objPosition, edge, characterFriend[0].dir, 0);
				if (!alreadyDie)
					characterEnemy[enemyRank].live -= 5;
			}
			if (sf :: Keyboard :: isKeyPressed(sf :: Keyboard :: I)){
				superMagic.move(3, objPosition, edge, characterFriend[0].dir, 0);
				if (!alreadyDie)
					characterEnemy[enemyRank].live -= 5; 
			}
			if (!alreadyDie && characterEnemy[enemyRank].live <= 0){ 
				characterEnemy[enemyRank].onScreen = false;
				characterEnemy[enemyRank++].playDieMedia(&sceneScene[sceneRank]);
				alreadyDie = true;
			}
			shouldMove = sceneScene[sceneRank].handleInput(!sceneScene[sceneRank].inEdge);
			if (characterEnemy[enemyRank].onScreen){
				//std :: cout << "live: ==========================" << characterEnemy[0].live << std :: endl;
				characterEnemy[enemyRank].moveToFriend(characterFriend[friendRank].position, shouldMove);
				if (characterEnemy[enemyRank].attackFriend(&characterFriend[friendRank])){
					magicStatus = (magicStatus + 1) % 5;
					edge.x = characterFriend[friendRank].edgeX;
					edge.y = characterFriend[friendRank].edgeY;
					superMagic.move(4, characterEnemy[enemyRank].position, edge, characterEnemy[enemyRank].dir, magicStatus);
					if (characterFriend[friendRank].isDie(superMagic.position, 100, 100, 5))//superMagic.edgeX, superMagic.edgeY, 20)) 
						characterFriend[friendRank].onScreen = false;
				}
			}
			characterFriend[friendRank].change(&sceneScene[sceneRank]);
		}
		if (sceneRank == 5){
			sf :: Sprite sp;
			sf :: Texture te;
			te.loadFromFile("end/1.png");
			sp.setTexture(te);
			sp.setPosition(0, 500);
			window.draw(sp);
		}
		if (!characterFriend[friendRank].onScreen){
			characterFriend[friendRank].playDieMedia(&sceneScene[sceneRank]);
			endSprite.setPosition(0, 300);
			window.draw(endSprite);
			window.display();
		}
		if (sceneRank == 6)
			window.draw(sceneScene[sceneRank].sprite);
		window.display();
		sf :: Clock clock;
		for (sf :: Time time = clock.getElapsedTime(); time.asSeconds() <= 0.025f; time = clock.getElapsedTime());
	}
}

void playMagic(int magicIndex, sf :: Vector2f ogjePosition, sf :: Vector2f edge, direction dir, int magicStatus){
	superMagic.move(magicIndex, ogjePosition, edge, dir, magicStatus);
}

void priData(){
	sceneScene[0].playMusic();
	characterFriend[0].onScreen = true;
	talk(0, &sceneScene[0]);
}

void talk(int rank, Scene *sceneN){
	sf :: Texture te;
	sf :: Sprite sp;
	std :: string path = "talk/";

	
	switch (rank){
		case 0:
			for (int i = 1; i <= 7; i++){
				window.clear();
				int hun = i / 100 + '0', ten = i % 100 / 10 + '0', dig = i % 10 + '0';
				char q[4] = {hun, ten, dig, '\0'};
				std :: string Image = q; Image += ".png"; 
				te.loadFromFile(path + Image);
				sp.setTexture(te);
				sp.setPosition(0, 300);
				window.draw(sceneN->sprite);
				window.draw(sp);
				window.display();
				sf :: Event event;
				while (window.pollEvent(event))
					if (event.type == sf :: Event :: Closed)
					       window.close();
				sf :: Clock clock;
				for (sf :: Time time = clock.getElapsedTime(); time.asSeconds() <= 2; time = clock.getElapsedTime());
			}
			break;
		case 1:
			for (int i = 8; i <= 9; i++){
				window.clear();
				int hun = i / 100 + '0', ten = i % 100 / 10 + '0', dig = i % 10 + '0';
				char q[4] = {hun, ten , dig, '\0'};
				std :: string Image = q; Image += ".png"; 
				te.loadFromFile(path + Image);
				sp.setTexture(te);
				sp.setPosition(0, 300);
				window.draw(sceneN->sprite);
				window.draw(sp);
				window.display();
				sf :: Event event;
				while (window.pollEvent(event))
					if (event.type == sf :: Event :: Closed)
					       window.close();

				sf :: Clock clock;
				for (sf :: Time time = clock.getElapsedTime(); time.asSeconds() <= 2; time = clock.getElapsedTime());
			}
			break;
		case 5: 
			for (int i = 10; i <= 11; i++){
				window.clear();
				int hun = i / 100 + '0', ten = i % 100 / 10 + '0', dig = i % 10 + '0';
				char q[4] = {hun, ten , dig, '\0'};
				std :: string Image = q; Image += ".png"; 
				te.loadFromFile(path + Image);
				sp.setTexture(te);
				sp.setPosition(0, 300);
				window.draw(sceneN->sprite);
				window.draw(sp);
				window.display();
				sf :: Event event;
				while (window.pollEvent(event))
					if (event.type == sf :: Event :: Closed)
					       window.close();

				sf :: Clock clock;
				for (sf :: Time time = clock.getElapsedTime(); time.asSeconds() <= 2; time = clock.getElapsedTime());
			}
			break;

	}
}
