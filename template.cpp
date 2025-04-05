#include <iostream>
using namespace std;
//template
template <typename Man,typename bet, typename set>
Man add (Man x,bet y, set z){
   return z+x+y;
};
int main(){
    cout<<add(5,4,5.0)<<endl;
    cout<<add(5,4.5,3)<<endl;
}
