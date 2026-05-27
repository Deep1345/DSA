#include<iostream>
#include<vector>
using namespace std;
int maxProfit(vector<int>& prices) {
    int maxProfit = 0;
    int mini = prices[0];
    for(int i = 1; i < prices.size(); i++){
        int profit = prices[i] - mini;
        maxProfit = max(maxProfit, profit);
        mini = min(mini, prices[i]);
    }
    return maxProfit;
}
// Time Complexity: O(n) as we are traversing the array once
// Space Complexity: O(1) as we are using only constant extra space
int main(){
    vector<int> prices;
    int n;
    cout << "Enter the number of days: ";
    cin >> n;
    cout << "Enter the stock prices for each day:\n";
    for(int i = 0; i < n; i++){
        int price;
        cin >> price;
        prices.push_back(price);
    }
    int result = maxProfit(prices);
    cout << "The maximum profit that can be achieved is: " << result << endl;
    return 0;
}