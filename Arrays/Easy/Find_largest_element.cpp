#include <iostream>
#include <vector>

using namespace std;
int findLargest(const vector<int>& v)
{

    if (v.empty()) return -1; 

    int largest = v[0];

    for (size_t i = 1; i < v.size(); i++)
    {
        if (v[i] > largest)
        {
            largest = v[i];
        }
    }
    return largest;
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
    
    int l = findLargest(v);
    cout << "The largest element in the array is: " << l << endl;
    
    return 0;
}