#include<iostream>
#include<vector>
using namespace std;
vector<int> unionOfSortedArrays(vector<int>& arr1, vector<int>& arr2) {
    vector<int> result;
    int i = 0, j = 0;
    while(i < arr1.size() && j < arr2.size()) {
        //case 1: arr1[i] < arr2[j]
        if(arr1[i] < arr2[j]) {
            if(result.empty() || result.back() != arr1[i]) {
                result.push_back(arr1[i]);
            }
            i++;

        }
        //case 2: arr1[i] > arr2[j]
        else if(arr1[i] > arr2[j]) {
            if(result.empty() || result.back() != arr2[j]) {
                result.push_back(arr2[j]);
            }
            j++;
        }
        //case 3: arr1[i] == arr2[j] 
        else {
            if(result.empty() || result.back() != arr1[i]) {
                result.push_back(arr1[i]);//we can also push arr2[j] as they are equal
            }
            i++;
            j++;
        }
    }
    //if there are remaining elements in arr1
    while(i < arr1.size()) {
        if(result.empty() || result.back() != arr1[i]) {
            result.push_back(arr1[i]);
        }
        i++;
    }
    //if there are remaining elements in arr2
    while(j < arr2.size()) {
        if(result.empty() || result.back() != arr2[j]) {
            result.push_back(arr2[j]);
        }
        j++;
    }
    return result;
}
vector<int> intersectionOfSortedArrays(vector<int>& arr1, vector<int>& arr2){
    vector<int> result;
    int i = 0, j = 0;
    while(i < arr1.size() && j < arr2.size()) {
        if(arr1[i] < arr2[j]) {
            i++;
        } else if(arr1[i] > arr2[j]) {
            j++;
        } else {
            if(result.empty() || result.back() != arr1[i]) {
                result.push_back(arr1[i]);
            }
            i++;
            j++;
        }
    }
    return result;
}
int main(){
    vector<int> arr1, arr2;
    int n1, n2;
    cout<<"Enter the number of elements in the first array: ";
    cin>>n1;
    cout<<"Enter the elements of the first array:\n";
    for(int i=0; i<n1; i++) {
        int element;
        cin>>element;
        arr1.push_back(element);
    }
    cout<<"Enter the number of elements in the second array: ";
    cin>>n2;
    cout<<"Enter the elements of the second array:\n";
    for(int i=0; i<n2; i++) {
        int element;
        cin>>element;
        arr2.push_back(element);
    }
    vector<int> unionResult = unionOfSortedArrays(arr1, arr2);
    vector<int> intersectionResult = intersectionOfSortedArrays(arr1, arr2);
    cout<<"Union of the two arrays:\n";
    for(int num : unionResult) {
        cout<<num<<" ";
    }
    cout<<"\nIntersection of the two arrays:\n";
    for(int num : intersectionResult) {
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;
}


//Time Complexity: O(n1 + n2) where n1 and n2 are the sizes of the two input arrays.
//Space Complexity: O(n1 + n2) in the worst case when all elements are unique and present in both arrays, resulting in the union containing all elements and the intersection containing all elements as well.