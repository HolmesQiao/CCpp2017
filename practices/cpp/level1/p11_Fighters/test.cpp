#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

sf :: RenderWindow window(sf :: VideoMode(500, 500), "a");
void play();

int main(){
	while (window.isOpen()){
		sf :: Event event;
		while (window.pollEvent(event)){
			if (event.type == sf :: Event :: Closed)
			       window.close();	
		}
		play();
	}
	return 0;
}

void play(){
	std :: string diePath = "Character/Enemy/sms/die/";
	sf :: Texture t;
	sf :: Sprite sp;
	for (int i = 1; i <= 120; i++){
		window.clear();
		int hun = i / 100 + '0', ten = i % 100 / 10 + '0', dig = i % 10 + '0';
		char q[4] = {hun, ten, dig};
		std :: string Image = q; Image += ".png"; 
		std :: cout << diePath + Image << std :: endl;
		t.loadFromFile(diePath + Image);
		sp.setTexture(t);
		window.draw(sp);
		window.display();
		sf :: Clock clock;
		for (sf :: Time time = clock.getElapsedTime(); time.asSeconds() <= 0.03f; )
			time = clock.getElapsedTime();
	}
}
