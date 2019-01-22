/*
Open/closed principle
https://en.wikipedia.org/wiki/Open%E2%80%93closed_principle
Classes should be open for extension, but closed for modification.
The code that doesn’t have to be changed every time the requirements change.
*/
#include <iostream>
#include <string>
#include <vector>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

class Shape {
public:
	string Name;
	Shape(string name) : Name(name) {};
};

class Rectangle : public Shape {
public:
	double Width; // for simplicity: no getters and setters 
	double Height;

	Rectangle(double width, double height) : Width(width), Height(height), Shape("Rectangle") {}
};

class Circle : public Shape {
public:
	double Radius;
	Circle(double radius) : Radius(radius), Shape("Circle") {}
};

class Shapes {
public:
	vector<Shape*> shapes;

	void Add(Shape* shape) {
		shapes.push_back(shape);
	}

	double TotalArea() {
		double area = 0;
		for (auto shape : shapes)
		//Bad: every time a new shape is introduced, this part needs to be modified
			if (shape->Name == "Rectangle")
			{
				Rectangle* rec = (Rectangle*)shape;
				area += rec->Width * rec->Height;
			}
			else if (shape->Name == "Circle")
			{
				Circle* cir = (Circle*)shape;
				area += pow(cir->Radius, 2) * M_PI;
			}
		return area;
	}
};

int main() {
	Shapes shapes;
	shapes.Add(new Rectangle(2, 3));
	shapes.Add(new Rectangle(3, 4));
	shapes.Add(new Rectangle(4, 5));
	shapes.Add(new Circle(4));
	shapes.Add(new Circle(5));

	cout << shapes.TotalArea() << endl;

	system("pause");
	return 0;
}
