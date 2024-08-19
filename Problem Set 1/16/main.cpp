#include <deque>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

vector<long long> find_k_max_windows(long long n, long long k, vector<long long>& nums) {
    deque<long long> q;
    vector<long long> k_max_windows;    

    for (long long i = 0; i < n; i++) {

        while(!q.empty() and q.front() <= i - k) q.pop_front();

        while(!q.empty() and nums[q.back()] < nums[i]) q.pop_back();

        q.push_back(i);

        if(i >= k - 1) k_max_windows.push_back(nums[q.front()]);    
    }

    return k_max_windows;
}

void solve(long long testcase) {
    long long n, k;
    cin >> n >> k;
    vector<long long> nums(n);

    for (long long i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    vector<long long> k_max_windows = find_k_max_windows(n, k, nums);

    for (auto it: k_max_windows) {
        cout << it << " ";
    }
    cout << "\n";
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