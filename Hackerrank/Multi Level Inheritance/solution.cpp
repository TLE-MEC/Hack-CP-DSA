#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// This class is already given.
class Triangle
{
public:
    void triangle()
    {
        cout << "I am a triangle\n";
    }
};

// This isoscles class which is inherited from Triangle class is also given (we don't have to do anything.)
class Isosceles : public Triangle
{
public:
    void isosceles()
    {
        cout << "I am an isosceles triangle\n";
    }
};

//Write your code here.

// This is the class which we have to create and we are asked to inherit it from Iscocles class.
class Equilateral : public Isosceles
{
public:
    // You can see that inside main function (which also we are given), we are
    //  accessing a public member of Equilateral class.
    void equilateral()
    {
        // From the sample output we can see that this class prints the line
        // "I am an equilateral triangle". Hence we are defining it in that manner.

        cout << "I am an equilateral triangle" << endl;
    }

    // That all we had to do.
};

int main()
{

    Equilateral eqr;
    eqr.equilateral();
    eqr.isosceles();
    eqr.triangle();
    return 0;
}

// Note that object eqr which is an instance of Equilateral class possesses member
// methods isosceles() and triangle() from it's parent class.
