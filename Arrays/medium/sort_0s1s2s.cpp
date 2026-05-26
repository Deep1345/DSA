//Dutch national flag algorithm
#include<iostream>
#include<vector>
using namespace std;
void sort012(vector<int>& arr){
    int low = 0;
    int mid = 0;
    int high = arr.size() - 1;
    while(mid <= high){
        if(arr[mid] == 0){
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid] == 1){
            mid++;
        }
        else{
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}
// Time Complexity: O(n) as we are traversing the array once
// Space Complexity: O(1) as we are using only constant extra space
int main(){
    vector<int> arr;
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    cout << "Enter the elements (0s, 1s, and 2s only):\n";
    for(int i = 0; i < n; i++){
        int element;
        cin >> element;
        arr.push_back(element);
    }
    sort012(arr);
    cout << "Sorted array:\n";
    for(int num : arr){
        cout << num << " ";
    }
    cout << endl;
    return 0;
}