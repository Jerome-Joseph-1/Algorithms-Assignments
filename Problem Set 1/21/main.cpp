#include <climits>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

long long max_profit(long long n, vector<long long>& nums) {
    long long profit = 0;

    for (long long i = 0, minFound = INT_MAX; i < n; ++i) {
        minFound = min(nums[i], minFound);

        profit = max(profit, nums[i] - minFound);
    }

    return profit;
}

void solve(long long testcase) {
    long long n; cin >> n;
    vector<long long> nums(n);

    for (long long i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    cout << max_profit(n, nums) << "\n";
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