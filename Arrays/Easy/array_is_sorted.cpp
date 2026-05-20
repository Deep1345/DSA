#include<iostream>
#include<vector>
using namespace std;
bool isSorted(vector<int>& nums){
    for(int i=1;i<nums.size();i++){
        if(nums[i]<nums[i-1]){
            return false;
        }
    }
    return true;
}
int main(){
    vector<int> nums;
    int n;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;
    cout<<"Enter the elements:\n";
    for(int i=0;i<n;i++){
        int element;
        cin>>element;
        nums.push_back(element);
    }
    if(isSorted(nums)){
        cout<<"The array is sorted in non-decreasing order."<<endl;
    }else{
        cout<<"The array is not sorted in non-decreasing order."<<endl;
    }
    return 0;
}
