#include <iostream>
using namespace std;
//struct 
struct Car {
    string name;
    int horsepower;
};
struct Ferrari {
    Car tires;
    int tyre_number;
};
int main(){
    Car Mercedes;
    Car *pt_Mercedes;
    Ferrari superfer;
    pt_Mercedes=&Mercedes;
    Mercedes.name="Benz";
    Mercedes.horsepower= 4000;
    superfer.tires.name = "Horizon";
    superfer.tires.horsepower = 600;
    superfer.tyre_number = 4; 
    cout<<"The tire name is"<<superfer.tires.name<<" and the tire number is "<< superfer.tyre_number<<endl;
    cout<<"Name: "<<Mercedes.name<<endl;
    cout<<"TH mercedes horsepower is: "<<Mercedes.horsepower<<endl;
    cout<<"The id is"<< pt_Mercedes<<endl;
    return 0;
};
