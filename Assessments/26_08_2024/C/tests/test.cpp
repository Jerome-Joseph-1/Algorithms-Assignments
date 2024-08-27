#include <algorithm>
#include <cassert>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

string GREEN = "\033[32m";
string RED = "\033[31m";
string WHITE = "\033[37m";

long long INF = 1e9 + 7;

bool is_possible(long long k, vector<long long>& k_max_windows, long long max_days, long long required_bouquets) {
    for (long long i = 0; i < k_max_windows.size() and required_bouquets > 0; ++i) {
        if(max_days >= k_max_windows[i]) {
            // greedily pick this 
            i += k - 1; // should be incremented by 'k', but the loop will increment 'i' by 1, so its k - 1
            required_bouquets--;
        }
    }

    return required_bouquets == 0;
}

long long efficient(long long n, long long k, long long m, vector<long long>& daysToBloom) {
    if(k*m > n) {
        return -1;
    }

    vector<long long> k_max_windows;
    multiset<long long> ms; // you could use a max-heap or deque for this 

    for (long long i = 0; i < n; ++i) {
        ms.insert(daysToBloom[i]);

        if(i >= k - 1) {
            k_max_windows.push_back(*ms.rbegin());
            ms.erase(ms.find(daysToBloom[i - k + 1]));
        }
    }

    // for (auto it: k_max_windows) {
    //     cout << it <<" ";
    // }
    // cout << "\n";

    long long lower_limit = 0, upper_limit = 1e9 + 7;

    while (lower_limit <= upper_limit) {
        long long no_of_days_to_wait = lower_limit + (upper_limit - lower_limit) / 2;

        // cout << no_of_days_to_wait << " " << is_possible(k, k_max_windows, no_of_days_to_wait, m) << "\n";
        if(!is_possible(k, k_max_windows, no_of_days_to_wait, m)) {
            // then increase the no of days to wait 
            lower_limit = no_of_days_to_wait + 1;
        } else {
            upper_limit = no_of_days_to_wait - 1;
        }
    }

    return lower_limit;

}

long long brute_helper(long long index, vector<long long>& k_max_windows, long long k, long long m) {
    if(m == 0) {
        return 0;
    }

    if(index >= k_max_windows.size()) return INF;

    long long pick = max(k_max_windows[index], brute_helper(index + k, k_max_windows, k, m - 1));
    long long dont_pick = brute_helper(index + 1, k_max_windows, k, m);

    return min(pick, dont_pick);
}

long long brute(long long n, long long k, long long m, vector<long long>& daysToBloom) {
    long long ans = 1e9 + 7;

    if(k*m > n) {
        return -1;
    }

    vector<long long> k_max_windows;
    multiset<long long> ms; // you could use a max-heap or deque for this 

    for (long long i = 0; i < n; ++i) {
        ms.insert(daysToBloom[i]);

        if(i >= k - 1) {
            k_max_windows.push_back(*ms.rbegin());
            ms.erase(ms.find(daysToBloom[i - k + 1]));
        }
    }

    ans = brute_helper(0, k_max_windows, k, m);

    return ans;
}

int main() {
    ifstream in("../input/input_file");
    cin.rdbuf(in.rdbuf());

    long long t;
    cin >> t;

    long long passed_tc = 0;

    for (long long tc = 1; tc <= t; ++tc) {
        long long n, k, m;
        cin >> n >> k >> m;

        vector<long long> daysToBloom(n);

        for (long long i = 0; i < n; ++i) {
            cin >> daysToBloom[i];
        }

        long long expected = brute(n, k, m, daysToBloom);
        long long actual = efficient(n, k, m, daysToBloom);

        if(expected == actual) {
            ++passed_tc;
            cout << "Test case: " << tc << " " << GREEN << "Passed" << "\n";
        } else {
            cout << "Test case: " << tc << " " << RED << "Failed " << expected << " " << actual << "\n";
        }
        cout << WHITE;
    }   

    cout << (passed_tc == t ? GREEN : RED)
              << ("Passed")
              << " (" 
              << (passed_tc == t ? GREEN : RED)
              << passed_tc << " / " << t 
              << WHITE << ")" << endl;  
    return 0;
}