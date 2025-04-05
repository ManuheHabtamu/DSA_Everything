#include <iostream>
using namespace std;
//namespace thing
namespace g{
    int x(){
        return 56;
    }
}
using  namespace g;
int main(){
    cout<<"The number is: "<<g::x()<<endl;
}