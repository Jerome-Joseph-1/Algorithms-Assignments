#include <cassert>
#include <fstream>
#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

string GREEN = "\033[32m";
string RED = "\033[31m";
string WHITE = "\033[37m";

long long UPPER_LIMIT = 1e5;

vector<long long> find_b(long long n, vector<long long>& nums) {
    vector<long long> B(n);
    stack<long long> s;

    for (long long i = 0; i < n; ++i) {
        while(!s.empty() and nums[s.top()] > nums[i]) {
            B[s.top()] = i;
            s.pop();
        }

        s.push(i);
    }

    while(!s.empty()) {
        B[s.top()] = n;
        s.pop();
    }

    return B;
}

int main() {
    ifstream in("../input/input_file");
    cin.rdbuf(in.rdbuf());

    long long t;
    cin >> t;

    long long passed_tc = 0;

    for (long long tc = 1; tc <= t; ++tc) {
        long long n;
        cin >> n;

        vector<long long> nums(n);

        for (long long i = 0; i < n; ++i) {
            cin >> nums[i];
        }

        vector<long long> B = find_b(n, nums);

        bool passed = true;

        for (long long i = 0, j; i < n; ++i) {
            for (j = i + 1; j < n; ++j) {
                if(nums[i] > nums[j]) break;
            }

            if(B[i] != j) {
                passed = false;
                break;
            }

        }

        cout << "Test Case: " << tc << " ";
        if(passed) {
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