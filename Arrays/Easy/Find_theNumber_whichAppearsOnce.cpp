#include<iostream>
#include<vector>
using namespace std;
int appearOnce(vector<int>& nums) {
    int XOR = 0;
    for(int i = 0; i < nums.size(); i++) {
        XOR = XOR ^ nums[i];
    }
    return XOR;
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
    int result = appearOnce(nums);
    cout<<"The number that appears once is: "<<result<<endl;
    return 0;
}