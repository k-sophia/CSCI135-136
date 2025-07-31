/**********
Implement a class Rectangle.

Provide a constructor to construct a rectangle with
a given width and height

Add member functions
-	double get_perimeter();
-	double get_area();
-	void resize(double factor);
	that resizes the rectangle by multiplying the
	width and height by the given float factor
**********/

#include <iostream>
using namespace std;

class Rectangle {
	public:
		Rectangle(double input_w, double input_h);
		double get_perimeter();
		double get_area();
		void resize(double factor);
	private:
		double width;
		double height;
};

Rectangle::Rectangle(double input_w, double input_h) {
    width = input_w;
    height = input_h;
}

double Rectangle::get_perimeter() {
    return 2 * (width + height);
}

double Rectangle::get_area() {
    return width*height;
}

void Rectangle::resize(double factor) {
    width = width*factor;
    height = height*factor;
}

int main() {
    Rectangle rect(3.0, 5.0);
    cout << "Perimeter: " << rect.get_perimeter() << endl;
    cout << "Area: " << rect.get_area() << endl;

    rect.resize(2.0);
    cout << "\nAfter resizing by factor of 2:\n";
    cout << "Perimeter: " << rect.get_perimeter() << endl;
    cout << "Area: " << rect.get_area() << endl;
}
