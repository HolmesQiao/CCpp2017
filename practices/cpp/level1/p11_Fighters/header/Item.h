#ifndef windowX
#define windowX 1000.f
#endif
#ifndef windowY
#define windowY 700.f
#endif
#ifndef DIRECTION
#define DIRECTION
enum direction{up, down, left, right};
#endif

const float step(30.f);
bool isMovingRight, isMovingLeft, isMovingUp, isMovingDown;
int rank(0);
sf :: RenderWindow window(sf :: VideoMode(windowX, windowY), "game");

/*****************************Item*Class********************************/
class Item{
	public:
		Item (): position(450.f, 380.f), status(0), inEdge(true) {}

		sf :: Sprite sprite;
		sf :: Vector2f position;
		direction dir;
		int status;
		bool inEdge;
		float edgeX, edgeY;

		void update(bool shouldBack);
		void move();
		void handleInput(bool shouldBack);
};

void Item :: handleInput(bool shouldBack){
	if (sf :: Keyboard :: isKeyPressed (sf :: Keyboard :: W))
		isMovingUp = true;
	else isMovingUp = false;
	if (sf :: Keyboard :: isKeyPressed (sf :: Keyboard :: S))
		isMovingDown = true;
	else isMovingDown = false;
	if (sf :: Keyboard :: isKeyPressed (sf :: Keyboard :: A))
		isMovingLeft = true;
	else isMovingLeft = false;
	if (sf :: Keyboard :: isKeyPressed (sf :: Keyboard :: D))
		isMovingRight = true;
	else isMovingRight = false;
	update(shouldBack);
}

void Item :: update(bool shouldBack){
	std :: cout << "begain";
	if (isMovingUp){
		if (!shouldBack){
			position.x += step;
			position.y += step;
		}
		dir = up;
	}
	if (isMovingDown){
		if (!shouldBack){
			position.x -= step;
			position.y -= step;
		}
		dir = down;
	}
	if (isMovingLeft){
		if (!shouldBack){
			position.x += step;
			position.y -= step;
	       }
	       	dir = left; 
	}
	if (isMovingRight){
		if (!shouldBack){
			position.x -= step;
			position.y += step;
		}
		dir = right;
	}
	inEdge = position.x > -edgeX && position.y > -edgeY && position.x <= -step && position.y <= -step;
	if (!inEdge){
		if (isMovingUp){
			position.x -= step;
			position.y -= step;
		}
		if (isMovingDown){
			position.x += step;
			position.y += step;
		}
		if (isMovingLeft){
			position.x -= step;
			position.y += step;
		}
		if (isMovingRight){
			position.x += step;
			position.y -= step;
		}
	}
	std :: cout << "x" << position.x << std :: endl << "y" << position.y << std :: endl;
	std :: cout << "shouldBack: " << shouldBack << std :: endl;
	std :: cout << "inEdge: " << inEdge << std :: endl;
	move();
}

void Item :: move(){
	window.clear();

	sprite.setPosition(position);
	window.draw(sprite);
	//window.display();
}
