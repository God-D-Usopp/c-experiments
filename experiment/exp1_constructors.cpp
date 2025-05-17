#include <iostream>
using namespace std;
class VolumeCuboid{
public:
int l, b, h, volume;

VolumeCuboid (int a, int d, int c){
l=a;
b=d;
h=c;
}
int volCub(){
volume = l*b*h;
return volume;
}
};

int main (){
int a,b,c, vol;

cout << "Enter the value of l, b, h" <<endl;

cin>>a>>b>>c;

VolumeCuboid obj(a, b, c); 

vol = obj.volCub();

cout << "The volume of cuboid is "<<vol;

return 0;
}