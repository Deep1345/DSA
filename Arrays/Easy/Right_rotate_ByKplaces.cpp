#include<iostream>
#include<vector>
using namespace std;
void reverse(vector<int>& arr, int start, int end) {
    while(start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}
void rightRotateByKPlaces(vector<int>& arr, int k) {
    int n = arr.size();
    if(n == 0) return;
    k = k % n;
    reverse(arr, 0, n - 1);
    reverse(arr, 0, k - 1);
    reverse(arr, k, n - 1);
}
int main() {
    vector<int> arr;
    int n, k;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;
    cout<<"Enter the elements:\n";
    for(int i=0; i<n; i++) {
        int element;
        cin>>element;                       
        arr.push_back(element);
    }
    cout<<"Enter the number of places to rotate: ";
    cin>>k;
    rightRotateByKPlaces(arr, k);
    cout<<"Array after right rotation by "<<k<<" places:\n";
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}   