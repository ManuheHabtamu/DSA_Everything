#include <iostream>
using namespace std;
// class 
class x{
    private:
        int password;
    public:
        string name;
        int age;
        string getname(){
            return name;
        }
        int getage(){
            return age;
        }
        string getpassword(){
            cout<<"My password is "<<password<<". Don't tell anyone\n";
        }
        protected:
            string email;


};
int main(){
    x obj; 
    obj.name = "manuhe";
    obj.age = 10;
    cout<<"My name is: "<<obj.getname()<<" and i am "<<obj.getage()<<" years old"<<endl;
    obj.getpassword();
}