#include<iostream>
#include<vector>
#include<algorithm>   // Required for sort()
using namespace std;
int twoSum(vector<int>& arr, int target){
    sort(arr.begin(), arr.end()); // Sort the array to apply two-pointer technique
    int n = arr.size();
    int l = 0;
    int r = n - 1;
    while(l < r){
        int sum = arr[l] + arr[r];
        if(sum == target){
            return 1; // Found a pair that sums to target
        }
        else if(sum < target){
            l++; // Move left pointer to increase sum
        }
        else{
            r--; // Move right pointer to decrease sum
        }
    }
    return 0; // No pair found that sums to target
}

// Time Complexity: Sorting → O(nlogn) Two pointer traversal → O(n) Overall → O(nlogn)
// Space Complexity:
// O(logn) due to internal stack usage in sorting
// (often written as O(1) in interviews if extra data structure isn't counted)
int main(){
    vector<int> arr;
    int n, target;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    cout << "Enter the elements:\n";
    for(int i = 0; i < n; i++){
        int element;
        cin >> element;
        arr.push_back(element);
    }
    cout << "Enter the target sum: ";
    cin >> target;
    int result = twoSum(arr, target);
    if(result == 1){
        cout << "A pair exists that sums to the target." << endl;
    }
    else{
        cout << "No pair exists that sums to the target." << endl;
    }
    return 0;
}