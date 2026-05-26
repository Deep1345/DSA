#include<iostream>
#include<vector>
#include<map>
using namespace std;
vector<int> twoSum(vector<int>& arr, int target){
    map <int, int> mpp;
    int n = arr.size();
    for(int i = 0; i < n; i++){
        int num = arr[i];
        int rem = target - num;
        if(mpp.find(rem) != mpp.end()){
            return {mpp[rem], i}; // Found a pair that sums to target
        }
        mpp[num] = i; // Store the index of the current number in the map
    }
    return {-1,-1}; // No pair found that sums to target
}
// Time Complexity: O(n) as we traverse the array once
// Space Complexity: O(n) in the worst case if all elements are unique and stored in the map
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
    vector<int> result = twoSum(arr, target);
    if(result[0] != -1){
        cout << "A pair exists at indices: " << result[0] << " and " << result[1] << "." << endl;
    }
    else{
        cout << "No pair exists that sums to the target." << endl;
    }
    return 0;
}
