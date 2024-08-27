#include <fstream>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

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

void solve(long long testcase) {
    // n: no of elements 
    // k: no of adjacent blooming flowers required to form a bouquet
    // m: no of bouquets rqeuired 
    long long n, k, m;
    cin >> n >> k >> m;

    vector<long long> daysToBloom(n);

    for (long long i = 0; i < n; ++i) {
        cin >> daysToBloom[i];
    }

    if(k*m > n) {
        cout << "-1\n";
        return;
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

    long long lower_limit = 0, upper_limit = 1e9 + 7;

    while (lower_limit <= upper_limit) {
        long long no_of_days_to_wait = lower_limit + (upper_limit - lower_limit) / 2;

        if(!is_possible(k, k_max_windows, no_of_days_to_wait, m)) {
            // then increase the no of days to wait 
            lower_limit = no_of_days_to_wait + 1;
        } else {
            upper_limit = no_of_days_to_wait - 1;
        }
    }

    cout << lower_limit << "\n";
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