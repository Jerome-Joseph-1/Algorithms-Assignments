#include <cassert>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

string GREEN = "\033[32m";
string RED = "\033[31m";
string WHITE = "\033[37m";

long long UPPER_LIMIT = 1e5;

long long brute_force(long long n, long long k, vector<long long>& a) {
    long long ans = 0;
    for (long long i = 0; i <= k; ++i) {
        for (long long j = k; j < n; ++j) {
            long long min_found = a[i];
            for (long long z = i + 1; z <= j; z++) {
                min_found = min(min_found, a[z]);
            }
            ans = max(ans, min_found * (j - i + 1));
        }
    }

    return ans;
}

long long efficient(long long n, long long k, vector<long long>& a) {
    long long i, j, ans = 0, min_found = a[k];
    i = j = k;

    while(i > -1 and j < n) {
        min_found = min(min_found, min(a[i], a[j]));
        ans = max(ans, min_found * (j - i + 1));

        if(i - 1 > -1 and j + 1 < n) {
            if(a[i-1] < a[j+1])
                j++;
            else 
                i--;
        } else if(i - 1 > -1) i--;
        else j++;
    }

    while(i > -1) {
        min_found = min(min_found, a[i]);
        ans = max(ans, min_found * (j - i));
        i--;
    }

    while(j < n) {
        min_found = min(min_found, a[j]);
        ans = max(ans, min_found * (j - i));
        j++;
    }

    return ans;
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

        vector<long long> a(n);

        for (long long i = 0; i < n; ++i) {
            cin >> a[i];
        }

        long long expected = brute_force(n, k, a);
        long long actual = efficient(n, k, a);

        if(expected == actual) {
            ++passed_tc;
            cout << "Test case: " << tc << " " << GREEN << "Passed" << "\n";
        } else {
            cout << "Test case: " << tc << " " << RED << "Failed" << "\n";
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