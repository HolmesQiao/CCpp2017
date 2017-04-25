#include <iostream>
#include <vector>

using namespace std;

const int rowSize(65);

class Point{
	public:
		double x, y;
		Point(double x = 0, double y = 0);
};

Point :: Point(double x, double y){
	Point :: x = x, Point :: y = y;
}

class Circle: public Point{
	public:
		double R;
		Circle(double R = 0, double x = 0, double y = 0);
};

Circle :: Circle(double R, double x, double y){
	Circle :: R = R;
	Circle :: x = x;
	Circle :: y = y;
}

class Rect{
	public:
		double h, w;
		Rect(double h = 0, double w = 0);
};

Rect :: Rect(double h, double w){
	Rect :: h = h, Rect :: w = w;
}

class Shape: public Circle, public Rect{
	public:
		void add();
		void dispAll();
		void dispCircle();
		void dispRect();
		vector<Circle> circle;
		vector<Rect> rect;
};

void Shape :: add(void){
	string shape;
	cout << "Enter the shape you want to add:(circle/rect) ";
	cin >> shape;
	if (shape == "circle"){
		double r, x, y;
		cout << "Enter the R and center of circle:(r/ x/ y) ";
		cin >> r >> x >> y;
		Circle c(r, x, y);
		Shape :: circle.push_back(c);
	}	
	else if (shape == "rect"){
		double h, w;
		cout << "Enter the height and width of rect(h/ w): ";
		cin >> h >> w;
		Rect r(h, w);
		Shape :: rect.push_back(r);
	}
	else
		cout << "Illegal shape, please input cicle or rect" << endl;
}

void Shape :: dispAll(void){
	dispCircle();
	dispRect();
}

void Shape :: dispCircle(void){
	vector<Circle> :: size_type len(circle.size());

	cout << endl;
	if (len == 0){
		cout << "There is no circle" << endl;
		return;
	}
	else{
		for (vector<Circle> :: size_type ix = 0; ix != len; ix++){
			cout << "Circle" << ix << ":" <<  " R: " << circle[ix].R << " x: " << circle[ix].x << " y: " << circle[ix].y << endl; 
		}
	}
}

void Shape :: dispRect(void){
	vector<Rect> :: size_type len(rect.size());

	cout << endl;
	if (len == 0){
		cout << "There is no rect" << endl;
		return;
	}
	else{
		for (vector<Rect> :: size_type ix = 0; ix < len; ix++){
			cout << "Rect" << ix << ":" << " Height: " << rect[ix].h << " Width: " << rect[ix].w << endl; 
		}
	}
}

int main(void)
{
	Shape Canvas;

	for (;;){
		string cmd;

		cout << endl;
		for (int i = 0; i < rowSize; i++)
			cout << "*";
		cout << "\n*Command list: 'add', 'dispall', 'dispcircle', disprect', 'quit'*" << endl;
		for (int i = 0; i < rowSize; i++)
			cout << "*";
		cout << "\nEnter the operator: ";
		cin >> cmd;
		if (cmd == "add")
			Canvas.add();
		else if (cmd == "dispall")
			Canvas.dispAll();
		else if (cmd == "dispcircle")
			Canvas.dispCircle();
		else if (cmd == "disprect")
			Canvas.dispRect();
		else if (cmd == "quit")
			return 0;
		else
			cout << "Illegal command, try again!" << endl;
	}
}
