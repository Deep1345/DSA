#include<iostream>
#include<vector>
using namespace std;
void moveZeroes(vector<int>& nums) {
    int n = nums.size();
    int j = -1;
    for(int i = 0; i<n;i++){
        if(nums[i]==0){
            j = i;
            break;
        }
    }//O(d) where d is first index of zero
    if(j==n-1 || j==-1){
        return;
    }
    for(int i = j+1;i<n;i++){
        if(nums[i]!=0){
            swap(nums[i],nums[j]);
            j++;
        }
    }//O(n-d)
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
    moveZeroes(nums);
    cout<<"Array after moving zeroes to the end:\n";
    for(int i=0; i<n; i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    return 0;
}

//Time Complexity: O(n) where n is the size of the input array.
//Space Complexity: O(1) as we are modifying the array in place without using any additional data structures.