#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
using namespace std;
int longestSubarrayWithSumK(vector<int>& arr, int k){
    map<long long, int> prefixSumMap;
    long long prefixSum = 0;
    int length = 0;
    for(int i = 0; i < arr.size(); i++) {
        prefixSum += arr[i];
        if(prefixSum == k) {
            length = max(length, i + 1);
        }
        //reverse calculation to find the required prefix sum that would give us sum k
        long long rem = prefixSum - k;
        if(prefixSumMap.find(rem) != prefixSumMap.end()) {
            int len = i - prefixSumMap[rem];
            length = max(length, len);
        }
        //edge case: where multiple prefix sums are same, we want to store the first occurrence to get the longest length
        if(prefixSumMap.find(prefixSum) == prefixSumMap.end()) {
            prefixSumMap[prefixSum] = i;
        }
    }
    return length;
}
// Time Complexity: O(nlogn) due to map operations
// Space Complexity: O(n) in the worst case for storing prefix sums in the map
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