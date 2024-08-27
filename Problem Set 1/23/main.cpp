#include <climits>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

long long max_profit(long long n, long long k, vector<long long>& nums) {
    long long profit = 0, min_buy_price = INT_MAX;
    for (long long i = k; i < n; ++i) {
        
        min_buy_price = min(min_buy_price, nums[i - k]);

        profit = max(profit, nums[i] - min_buy_price);
    }

    return profit;
}   

void solve(long long testcase) {
    long long n, k; cin >> n >> k;
    vector<long long> nums(n);

    for (long long i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    cout << max_profit(n, k, nums) << "\n";
}


int main() {
    ifstream in("input/input_file");
    cin.rdbuf(in.rdbuf());

    long long testcases;
    cin >> testcases;
    
    for (long long tc = 1; tc <= testcases; ++tc) {
        solve(tc);
    }

    return 0;
}       