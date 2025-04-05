#include <iostream>
#include <string>
using namespace std;
// overloading
int add(double x, double y){
    return x+y;
}
int add(int x, int y){
    return x+y;
}
double add(int x, double y, int z){
    return x+y+z;
}
int main(){
    cout<<add(4.5,4.5)<<endl;
    cout<<add(3,2)<<endl;
    cout<<add(5,2.3,6)<<endl;
}



















