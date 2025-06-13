#include <iostream>
using namespace std;
/*
accessing of an array- o(1), bc we cant traverse each
int[5]={1,k,k,k,k};
to make itdynamic adding new elt resizing o(n)
amortized
insertion and deletion in the middle- o(n)
ll dont jump
*/
void printarray(const int* arr, int size){
      for (int i=0; i<size; i++){
      cout<< arr[i]<<endl;
      }
    }
int main(){
    int size=10;
    //Array Declaration
    // int nums[size];
    // for (int i=0; i<size;i++){
    //         nums[i]=i;
    // }
    int arr[5]={1,2,3,4,5};
    // int partial[2]={1,2};
    // for (int i=0; i<5;i++){
    //         cout<<partial[i]<<endl;
    // }
    //cout<<sizeof(int)<<endl;
    int* ptr= arr;
    // int sz= sizeof(stds)/sizeof(int);
    // for (int i=0; i<sz; i++){
    //     cout<<*(ptr+i)<<endl;
    // }
    
    // int x [3][4]= {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    // for (int i=0; i<=3; i++){
    //   for(int j=0; j<=4; j++){
    //     cout<<"i = "<<i<<" j = "<<j<</*x[i][j]<<*/endl;
    //   }
    // }
    
    printarray(arr,5);
    printarray(arr,10);
    //sort 
    return 0;
}

//struct Node{
  //  int data;
    //Node* next;

//};