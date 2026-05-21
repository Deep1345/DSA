#include<iostream>
#include<vector>
using namespace std;
void leftRotateByOne(vector<int>& arr) {
    if(arr.empty()) return;
    int first = arr[0];
    for(int i = 1; i < arr.size(); i++) {
        arr[i-1] = arr[i];
    }
    arr[arr.size() - 1] = first;
}
int main() {
    vector<int> arr;
    int n;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;
    cout<<"Enter the elements:\n";                              
    for(int i=0; i<n; i++) {
        int element;
        cin>>element;
        arr.push_back(element);
    }
    leftRotateByOne(arr);
    cout<<"Array after left rotation by one:\n";
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}