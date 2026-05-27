#include<iostream>
#include<vector>
using namespace std;
//Moore's Voting Algorithm
int majorityElement(vector<int>& nums) {
    int element;
    int count = 0;
    for(int i = 0; i < nums.size(); i++){
        if(count == 0){
            element = nums[i];
            count = 1;
        }
        else if(nums[i] == element){
            count++;
        }
        else{
            count--;
        }
    }
    //If there is a majority element, it will be the candidate at the end of the first loop. However, we need to verify if it is indeed the majority element.
    int flag = 0;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] == element){
            flag++;
        }
    }
    if(flag > nums.size() / 2){
        return element;
    }
    return -1;
}
// Time Complexity: O(n) as we are traversing the array twice
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
    int result = majorityElement(nums);
    if(result != -1){
        cout << "The majority element is: " << result << endl;
    }
    else{
        cout << "No majority element found." << endl;
    }
    return 0;
}