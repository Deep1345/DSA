#include<iostream>
#include<vector>
using namespace std;
int removeDuplicates(vector<int>& nums) {
    int i = 0;
    for(int j =1; j < nums.size(); j++){
        if(nums[j] != nums[i]){
            nums[i+1] = nums[j];
            i++;
        }
    }
    return i+1;
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
    int newLength = removeDuplicates(nums);
    cout<<"Total unique elements: "<<newLength<<endl;
    cout<<"The array in place with unique elements is:\n";
    for(int i=0; i<n; i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    return 0;
}