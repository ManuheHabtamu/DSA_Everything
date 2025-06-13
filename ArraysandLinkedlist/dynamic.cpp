#include <iostream>
#include <algorithm>
using namespace std;
class DynamicArray{
        private:
            int* arr;
            int size;
            int capacity;

            void resize(){
                capacity *=2;
                int* newArr= new int[capacity];
            for(int i=0; i<size; i++){
                newArr[i]= arr[i];
            } 
            delete[] arr;
            arr= newArr;
            }
        public: 
            DynamicArray():size(0), capacity(1)
            { arr = new int[5];
            }
            ~DynamicArray(){
                delete[] arr;
            }
            void push_back(int value){
                    if(size==capacity){
                        resize();
                    }
                    arr[size]= value;
                    size++;
            }
            int pop_back(int value){
                    if(size>0){
                        size--;
                    };
                    return arr[size];
            }
            int& operator[](int index){
                 return arr[index];
             };
            //DynamicArray& operator+(DynamicArray& other){
                //do the logic here
            //}
            int getSize(){
                return size;
            }
            int getcapacity(){
                return capacity;
            }
    };
    
int main(){
    // create the dynamic array
    DynamicArray arr;
    cout<<arr.getSize()<<endl;
    cout<<arr.getcapacity()<<endl;
    arr.push_back(120);
    cout<<"added 1 element:\n";
    cout<<arr.getSize()<<endl;
    cout<<arr.getcapacity()<<endl;
    cout<<"added 1 element:\n";
    arr.push_back(80);
    cout<<arr.getSize()<<endl;
    cout<<arr.getcapacity()<<endl;
    for (int i=0; i<arr.getSize();i++){
        cout<<arr[i]<<",";
    }

    return 0;
}
//Algorithms 