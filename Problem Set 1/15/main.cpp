#include <fstream>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool is_valid_stack_sequence(long long n, vector<long long>& nums) {
    stack<long long> s;

    for (long long i = 0, pushed_till = 0; i < n; i++) {
        if(s.size() and nums[i] == s.top()) s.pop();
        else if(pushed_till > nums[i]) return false;
        else {
            while(pushed_till < nums[i])
                s.push(++pushed_till);
            s.pop();
        }
    }

    return s.empty();
}

void solve(long long testcase) {
    long long n;
    cin >> n;

    vector<long long> nums(n);
    
    for (long long i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    cout << is_valid_stack_sequence(n, nums) << "\n";
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