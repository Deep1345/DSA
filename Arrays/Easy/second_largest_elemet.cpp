#include <iostream>
#include <vector>
using namespace std;
int findSecondLargest(const vector<int>& v)
{
    int largest = v[0];
    int secondLargest = -1;
    for (size_t i = 1; i < v.size(); i++)
    {
        if (v[i] > largest)
        {
            secondLargest = largest;
            largest = v[i];
        }
        else if (v[i] > secondLargest && v[i] != largest)
        {
            secondLargest = v[i];
        }
    }
    return secondLargest;
}
int main()
{
    vector<int> v;
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    
    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++)
    {
        int element;
        cin >> element;
        v.push_back(element);
    }
    
    int l = findSecondLargest(v);
    cout << "The second largest element in the array is: " << l << endl;
    
    return 0;
}