#include<iostream>
#include<vector>
using namespace std;
int longestSubarrayWithSumK(vector<int>& arr, int k) {
    int sum = arr[0];
    int n = arr.size();
    int maxLength = 0;
    int i = 0;
    int j = 0;
    while(j<n){
        //Two pointer approach: we keep adding elements to the sum until it exceeds k, then we move the left pointer to reduce the sum
        while(i<=j && sum > k){//Here two conditions: i should be less than or equal to j to maintain the validity of the window, and sum should be greater than k to ensure we are reducing the sum
            sum = sum -  arr[i];
            i++;
        }
        if(sum == k){
            maxLength = max(maxLength, j - i + 1);
        }
        j++;
        //making sure we don't go out of bounds while adding the next element to the sum
        if(j<n){
            sum = sum + arr[j];
        }
    }
    return maxLength;
}
// Time Complexity: O(n) as we are traversing the array at most twice
// Space Complexity: O(1) as we are using only constant extra space

int main(){
    vector<int> arr;
    int n, k;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;
    cout<<"Enter the elements:\n";
    for(int i=0;i<n;i++){
        int element;
        cin>>element;
        arr.push_back(element);
    }
    cout<<"Enter the value of k: ";
    cin>>k;
    int result = longestSubarrayWithSumK(arr, k);
    cout<<"The length of the longest subarray with sum k is: "<<result<<endl;
    return 0;
}