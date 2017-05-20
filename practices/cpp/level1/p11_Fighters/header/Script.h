#include "data.h"

void Script(){
	sceneScene[0].playMusic();
	while (window.isOpen()){ 
		sf :: Event event;
		while (window.pollEvent(event)){
			if (event.type == sf :: Event :: Closed)
			       window.close();
			//if (judgeFighting)
		}
		if (rank == 0 && characterFriend[0].position.x > 900\
&& characterFriend[0].position.y < 30){
			rank++;
			sceneScene[rank - 1].stop();
			sceneScene[rank].playMusic();
		}
		/*if (!sf :: Keyboard :: isKeyPressed){
			std :: cout << "+++++++++++++Not pressed++++++++++\n";
			characterEnemy[0].moveToFriend(characterFriend[0].position);
		}
		*/
		if (sf :: Keyboard :: isKeyPressed(sf :: Keyboard :: J))
			characterFriend[0].playFightMedia(&sceneScene[rank]);
		if (sf :: Keyboard :: isKeyPressed(sf :: Keyboard :: K))
			superMagic.move(0, &characterFriend[0]);
		if (sf :: Keyboard :: isKeyPressed(sf :: Keyboard :: U))
			superMagic.move(1, &characterFriend[0]);
		if (sf :: Keyboard :: isKeyPressed(sf :: Keyboard :: L))
			superMagic.move(2, &characterFriend[0]);
		if (sf :: Keyboard :: isKeyPressed(sf :: Keyboard :: I))
			superMagic.move(3, &characterFriend[0]);
		sceneScene[rank].handleInput(!sceneScene[rank].inEdge);
		characterEnemy[0].moveToFriend(characterFriend[0].position);
		characterFriend[0].change(&sceneScene[rank]);
		window.display();
	}
}
