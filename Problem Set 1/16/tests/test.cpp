#include <cassert>
#include <deque>
#include <fstream>
#include <iostream>
#include <set>
#include <vector>
#include <string>

using namespace std;

string GREEN = "\033[32m";
string RED = "\033[31m";
string WHITE = "\033[37m";

long long UPPER_LIMIT = 1e5;

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

        vector<long long> k_max_windows = find_k_max_windows(n, k, nums);

        multiset<long long> k_max;

        for (long long i = 0; i < k; ++i) {
            k_max.insert(nums[i]);
        }

        bool passed = *(k_max.rbegin()) == k_max_windows[0];
        for (long long i = k; i < n && passed; ++i) {
            k_max.erase(k_max.find(nums[i - k]  ));
            k_max.insert(nums[i]);
            if(*(k_max.rbegin()) != k_max_windows[i - k + 1]) {
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