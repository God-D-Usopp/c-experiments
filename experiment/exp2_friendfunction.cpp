#include<iostream>
#include<string>
using namespace std;
class Employee{
public:
    int employee_id, basic_pay, da, pf, net_salary;
    string employee_name;
    friend float bonus (Employee& obj1);
};
float bonus (Employee& obj1){

    float bon;

    cout <<"enter employee name: "<<endl;
    getline(cin, obj1.employee_name);
    cout<<"enter id: "<<endl;
    cin>> obj1.employee_id;

    cout << "enter basic pay: "<<endl;
    cin>>obj1.basic_pay;

    cout <<"enter dearness allowance: "<<endl;
    cin>>obj1.da;

    cout << "enter pf amount: "<<endl;
    cin>>obj1.pf;

    obj1.net_salary = obj1.basic_pay + obj1.da- obj1.pf;
    if (obj1.net_salary <= 10000){
        bon = obj1.net_salary*(0.2);
    }
    return bon;
}
int main(){
    float bonus1;
    Employee tot_bonus;
    bonus1 = bonus(tot_bonus);
    cout<<"The bonus for "<<tot_bonus.employee_name<<
        "("<<tot_bonus.employee_id<<")"<<" is "<<bonus1<<endl;
    cout<<"The net salary with bonus is "<< bonus1 + tot_bonus.net_salary;
    return 0;
}

