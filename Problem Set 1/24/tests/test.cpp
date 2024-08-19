#include <cassert>
#include <climits>
#include <deque>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

string GREEN = "\033[32m";
string RED = "\033[31m";
string WHITE = "\033[37m";

long long UPPER_LIMIT = 1e5;

long long max_profit(long long n, long long k, vector<long long>& nums) {
    long long profit = 0;
    deque<long long> q;

    for (long long i = 0; i < n; ++i) {
        while(!q.empty() and q.front() < i - k) q.pop_front();

        while (!q.empty() and nums[q.back()] < nums[i]) q.pop_back();

        q.push_back(i);

        if(i - k >= 0)
            profit = max(nums[q.front()] - nums[i - k], profit);
    }

    return profit;
}

long long max_profit_brute(long long n, long long k, vector<long long>& nums) {
    long long maxProfit = 0;
    for (long long i = 0; i < n - k; ++i) {
        long long  maxSellPrice = INT_MIN;
        for (int j = i + 1; j <= i + k && j < n; ++j) {
            maxSellPrice = max(maxSellPrice, nums[j]);
        }
        if (maxSellPrice != INT_MIN) {
            maxProfit = std::max(maxProfit, maxSellPrice - nums[i]);
        }
    }

    return maxProfit;
}

int main() {
    ifstream in("../input/input_file");
    cin.rdbuf(in.rdbuf());

    long long t;
    cin >> t;

    long long passed_tc = 0;

    for (long long tc = 1; tc <= t; ++tc) {
        long long n, k;
        cin >> n >> k;

        vector<long long> nums(n);

        for (long long i = 0; i < n; ++i) {
            cin >> nums[i];
        }

        long long expected_answer = max_profit_brute(n, k, nums);
        long long actual_answer = max_profit(n, k, nums);

        cout << "Test Case: " << tc << " ";
        if(expected_answer == actual_answer) {
            passed_tc++;
            cout << GREEN << "Passed. " << WHITE;
        } else {
            cout << RED << "Failed. " << WHITE;
        }
        cout << "\n";
    }   

    cout << (passed_tc == t ? GREEN : RED)
              << ("Passed")
              << " (" 
              << (passed_tc == t ? GREEN : RED)
              << passed_tc << " / " << t 
              << WHITE << ")" << endl;  
    return 0;
}   