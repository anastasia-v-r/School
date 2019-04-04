#include <iostream>
using namespace std;
//_________________________________________________________________________
// This program declares a class for a circle that will have 
// member functions that set the center, find the area, find
// the circumference and display these attributes.
// The program as written does not allow the user to input data, but
// rather has the radii and center coordinates of the circles (spheres in the program) 
// initialized  at declaration or set by a function.

//class declaration section   (header file)

class Circles
{
public:
	double findArea();
	double findCircumference();
	void printCircleStats(); // This outputs the radius and center of the circle. 
	Circles(float r, int cen_x, int cen_y);
	Circles(int cen_x, int cen_y);
	Circles(float r);       // Constructor
	Circles();               // Default constructor
	~Circles();
private:
	float  radius;
	int    center_x;
	int    center_y;
};


const double PI = 3.14;

//Client section   

int main()
{
	Circles sphere(8);
	Circles sphere1(2);
	Circles sphere2;
	Circles sphere3(15.0, 16.0);

	sphere.printCircleStats();
	cout << "The area of the circle is " << sphere.findArea() << endl;
	cout << "The circumference of the circle is "
		<< sphere.findCircumference() << endl;
	sphere1.printCircleStats();
	sphere2.printCircleStats();
	sphere3.printCircleStats();

	return 0;
}

//___________________________________________________________________________
//Implementation section     Member function implementation

Circles::Circles()
{
	radius = 1;
	center_x = 0;
	center_y = 0;
}
// Fill in the code to implement the non-default constructor
Circles::Circles(float r)
{
	radius = r;
	center_x = 0;
	center_y = 0;
}

Circles::Circles(float r, int cen_x, int cen_y)
{
	radius = r;
	center_x = cen_x;
	center_y = cen_y;
}

Circles::Circles(int cen_x, int cen_y)
{
	radius = 1;
	center_x = cen_x;
	center_y = cen_y;
}
// Fill in the code to implement the findArea member function
double Circles::findArea()
{
	return PI * (radius * radius);
}
// Fill in the code to implement the findCircumference member function
double Circles::findCircumference()
{
	return 2 * PI * radius;
}

void Circles::printCircleStats()
// This procedure prints out the radius and center coordinates of the circle
// object that calls it.

{
	cout << "The radius of the circle is " << radius << endl;
	cout << "The center of the circle is (" << center_x
		<< "," << center_y << ")" << endl;
}

Circles::~Circles()
{
	cout << "This concludes the Circles class.\n";
}