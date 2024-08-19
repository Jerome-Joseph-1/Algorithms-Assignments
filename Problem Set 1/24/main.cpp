#include <climits>
#include <deque>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

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