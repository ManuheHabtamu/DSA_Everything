#include <iostream>
#include <vector>
using namespace std;
    
    vector<int> twosum(vector<int>& nums, int target){
    vector <int> s;
    vector<int> d;
    for (int i=0; i<nums.size(); i++){
        for (int j=0; j<nums.size(); j++){
            if (target== nums[i]+nums[j]){
                s.push_back(i);
                s.push_back(j);
                return s;
            }
        }
    }
    return d; 
}
int main(){
    vector <int> arr;
    arr.push_back(6);
    arr.push_back(7);
    arr.push_back(8);
    vector<int> p=twosum(arr,15);
    cout<<p[0]<<" "<<p[1];
    return  0;
}