#include <iostream>
#include <cstdio>

using namespace std;

enum direction{UP, DOWN, LEFT, RIGHT, STAY};

class Point{
	public:
		Point(double a = 0, double b = 0);
		double x, y;
};

Point :: Point(double a, double b){
	Point :: x = a;
	Point :: y = b;
}

class Cricle{
	public:
		Cricle(double a = 0, double b = 0, double r = 0);
		void move(enum direction dir);
		void printCricle(void);
	private:
		Point cent;
		double R;
};

Cricle :: Cricle(double a, double b, double r){
	cent.x = a, cent.y = b;
	R = r;
}

void Cricle :: move(enum direction dir){
	switch (dir){
		case UP:	cent.x--;	break;
		case DOWN:	cent.x++;	break;
		case LEFT:	cent.y--;	break;
		case RIGHT: 	cent.y++;	break;
		default :	break;
	}
}

void Cricle :: printCricle(){
	cout << "Central x = " << cent.x << "\nCentral y = " << cent.y << endl;
	cout << "R = " << R << endl << endl; 
}

int main(){
	double cen_x, cen_y, r;
	cout << "Enter the central(x/y) and r: "; 
	cin >> cen_x >> cen_y >> r;
	Cricle c(cen_x, cen_y, r);
	for (;;){
		enum direction dir;
		char d;
		cout << "Enter the direction you want to move: (u/d/l/r)";
		cin >> d;
		switch (d){
			case 'u':	dir = UP;	break;
			case 'd':	dir = DOWN;	break;
			case 'l':	dir = LEFT;	break;
			case 'r':	dir = RIGHT;	break;
			default :	dir = STAY;	break;
		}

		c.move(dir);
		c.printCricle();
	}
	
	return 0;
}
