#include<iostream>
#include<vector>
using namespace std;
int maxSubArraySum(vector<int>& nums){
    int maxi = INT_MIN;//minimum possible value of an integer
    int sum = 0;
    for(int i = 0; i < nums.size(); i++){
        sum = sum + nums[i];
        maxi = max(maxi, sum);
        if(sum < 0){ //If the sum becomes negative, we reset it to 0 because a negative sum would decrease the overall sum of any future subarray.
            sum = 0;
        }
    }
    return maxi;
}
// Time Complexity: O(n) as we are traversing the array once
// Space Complexity: O(1) as we are using only constant extra space
int main(){
    vector<int> nums;
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    cout << "Enter the elements:\n";
    for(int i = 0; i < n; i++){
        int element;
        cin >> element;
        nums.push_back(element);
    }
    int result = maxSubArraySum(nums);
    cout << "The maximum subarray sum is: " << result << endl;
    return 0;
}