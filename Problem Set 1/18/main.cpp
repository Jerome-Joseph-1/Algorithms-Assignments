#include <fstream>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<long long> find_b(long long n, vector<long long>& nums) {
    vector<long long> B(n);
    stack<long long> s;

    for (long long i = n - 1; i > -1; --i) { 
        while(!s.empty() and nums[s.top()] < nums[i]) {
            B[s.top()] = i;
            s.pop();
        }

        s.push(i);
    }

    while(!s.empty()) {
        B[s.top()] = -1;
        s.pop();
    }

    return B;
}

void solve(long long testcase) {
    long long n;
    cin >> n;

    vector<long long> nums(n);

    for (long long i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    vector<long long> B = find_b(n, nums);

    for (auto it: B) {
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