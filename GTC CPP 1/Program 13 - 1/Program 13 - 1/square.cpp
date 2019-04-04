#include <iostream>
using namespace std;

// FILL IN THE CODE TO DECLARE A CLASS CALLED Square.  TO DO THIS SEE
// THE IMPLEMENTATION SECTION.

class Square
{
public:
	Square();
	Square(int);
	~Square();
	void setSide(float);
	float findPerimeter();
	float findArea();
private:
	float side;
};

Square::Square()
{
	side = 1;
}

Square::Square(int a)
{
	side = a;
}

Square::~Square()
{
}

int main()
{
	Square  box;          // box is defined as an object of the Square class
	float   size;         // size contains the length of a side of the square 
	Square box1(9);

   // FILL IN THE CLIENT CODE THAT WILL ASK THE USER FOR THE LENGTH OF THE SIDE 
   // OF THE SQUARE.  (This is stored in size)
	cout << "Enter the length of the side of the square.\n";
	cin >> size;
   // FILL IN THE CODE THAT CALLS SetSide.
	box.setSide(size);
   // FILL IN THE CODE THAT WILL RETURN THE AREA FROM A CALL TO A FUNCTION
   // AND PRINT OUT THE AREA TO THE SCREEN 
	cout << "Area of box : " << box.findArea() << "\n";
   // FILL IN THE CODE THAT WILL RETURN THE PERIMETER FROM A CALL TO A 
   // FUNCTION AND PRINT OUT THAT VALUE TO THE SCREEN 
	cout << "Perimeter of box : " << box.findPerimeter() << "\n";
	cout << "Area of box1 : " << box1.findArea() << "\n";
	cout << "Perimeter of box1 : " << box1.findPerimeter() << "\n";
	system("pause");
	return 0;
}

//__________________________________________________________________
//Implementation section     Member function implementation

//**************************************************
//                  setSide
//
// task:    This procedure takes the length of a side and
//          places it in the appropriate member data
// data in: length of a side
//***************************************************

void Square::setSide(float length)

{
	side = length;
}
//**************************************************
//                 findArea
//
// task:    This finds the area of a square
// data in: none (uses value of data member side)
// data returned:  area of square
//***************************************************

float Square::findArea()
{
	return side * side;
}
//**************************************************
//                 findPerimeter
//
// task:    This finds the perimeter of a square
// data in: none (uses value of data member side)
// data returned:  perimeter of square
//***************************************************	
float Square::findPerimeter()
{
	return 4 * side;
}
