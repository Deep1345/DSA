#include<iostream>
#include<vector>
using namespace std;
int findConsecutiveOnes(vector<int>& nums){
    int maxi = 0;
    int cnt = 0;
    for(int i=0; i<nums.size(); i++){
        if(nums[i] == 1){
            cnt++;
        }else{
            maxi = max(maxi, cnt);
            cnt = 0;
        }
    }
    return max(maxi, cnt);
}
int main(){
    vector<int> nums;
    int n;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;
    cout<<"Enter the elements:\n";
    for(int i=0; i<n; i++){
        int element;
        cin>>element;
        nums.push_back(element);
    }
    int result = findConsecutiveOnes(nums);
    cout<<"The maximum number of consecutive 1's is: "<<result<<endl;
    return 0;
}


//Time Complexity: O(n) where n is the size of the input array.
//Space Complexity: O(1) as we are using only a constant amount of extra space to keep track of the count and maximum count of consecutive 1's.