#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

long long find_max_balanced_substring(long long n, string& binary_string) {
    long long max_length = 0, r_sum = n;
    vector<long long> prefix(2*n + 1, -1);

    for (long long i = 0; i < n; ++i) {
        r_sum += binary_string[i] == '1' ? 1 : -1;

        if(prefix[r_sum] == -1) prefix[r_sum] = i;

        if(r_sum == n) {
            max_length = i + 1;
            continue;
        }

        max_length = max(
            max_length,
            i - prefix[r_sum]
        );
    }
    return max_length;
}

void solve(long long testcase) {
    long long n;
    string binary_string;

    cin >> n >> binary_string;

    cout << find_max_balanced_substring(n, binary_string) << "\n";
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