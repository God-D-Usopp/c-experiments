//multiple inheritance 
#include<iostream>
using namespace std;
class Circle{
  public:
  float radius,areac;
  float circArea(){
    areac = 3.14*(radius*radius);
    return areac;
  }
};
class Rectangle{
  public:
  float length,breadth,arear;
  float recArea(){
    arear = length * breadth;
    return arear;
  }
  
};
class Area:public Circle,public Rectangle{
  public:
  float area;
  float totArea(){
    area = recArea()+ circArea();
    return area;
  }
};
int main(){
  float r,b,l,total_area;
  Area area1;
  cout<<"enter the radius,length and breadth respectively: "<<endl;
  cin>>r>>l>>b;
  area1.radius = r;
  area1.length = l;
  area1.breadth = b;
  total_area = area1.totArea();
  cout<<"area of circle: "<<area1.circArea()<<endl;
  cout<<"area of rectangle: "<<area1.recArea()<<endl;
  cout<<"the total area covered by circle and the rectangle is "<<total_area<<endl;
  return 0;
}