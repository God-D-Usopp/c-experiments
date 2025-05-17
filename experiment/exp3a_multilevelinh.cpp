#include <iostream>
using namespace std;

class cone
{
public:
    double radius;
};

class SurfaceArea : public cone
{
public:
    double Surface_area()
    {
        return 3.14 * (radius * radius);
    }
};

class Volume : public SurfaceArea
{
public:
    double height;
    double calculateVolume()
    {
        return (1.0 / 3) * Surface_area() * height;
    }
};

int main()
{
    double r, h;
    Volume vol;
    cout << "Enter the radius and height:" << endl;
    cin >> r >> h;
    vol.radius = r;
    vol.height = h;
    cout << "The surface area of the cone is: " << vol.Surface_area() << endl;
    cout << "The volume of the cone is: " << vol.calculateVolume() << endl;
    return 0;
}