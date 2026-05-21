#include<iostream>
#include<vector>
using namespace std;
int findMissingNumber(vector<int>& nums, int n) {
    // Sum of numbers from 1 to n using long long to prevent integer overflow
    long long totalSum = ((long long)n * (n + 1)) / 2; 
    long long arraySum = 0;
    
    for(int i = 0; i < nums.size(); i++) {
        arraySum += nums[i];
    }
    return totalSum - arraySum;
}
int findMissingNumberXOR(vector<int>& nums, int n) {
    int xor1 = 0;
    int xor2 = 0;
    for(int i = 0; i < nums.size(); i++) {
        xor2 = xor2 ^ nums[i];// XOR all elements present in the array
        xor1 = xor1 ^ (i + 1); // XOR with numbers from 1 to n-1
    }
    xor1 = xor1 ^ n; // XOR with n to include the full range
    
    
    return xor1 ^ xor2; 
}

int main(){
    vector<int> nums;
    int n;
    cout << "Enter the value of n (the range of numbers is from 1 to n): ";
    cin >> n;
    
    int m = n - 1;
    cout << "Enter the " << m << " elements:\n";
    for(int i = 0; i < m; i++){
        int element;
        cin >> element;
        nums.push_back(element);
    }
    
    // Pass 'n' explicitly so the functions know the exact range bound
    int missingNumber = findMissingNumber(nums, n);
    cout << "The missing number is: " << missingNumber << endl;

    int missingNumberXOR = findMissingNumberXOR(nums, n);
    cout << "The missing number (using XOR) is: " << missingNumberXOR << endl;

    return 0;
}


//Note: The XOR method is more better because sometimes for sum it may exceed the integer limit and cause overflow, while XOR will not have this issue.