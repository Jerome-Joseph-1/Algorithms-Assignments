#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

long long find_max_length_dense_substring(long long n, string& binary_string) {
    // unordered_map<long long, long long> smallest_index_for_sum;
    vector<long long> smallest_index_for_sum(2*n + 1, -1);

    long long sum = 0, max_length_dense_substring = 0;
    for (long long i = 0; i < n; ++i) {
        sum += binary_string[i] == '1' ? 1 : -1;

        if(smallest_index_for_sum[sum] == -1)
            smallest_index_for_sum[sum] = i;

        if(sum > 0) {
            max_length_dense_substring = i + 1;
            continue;
        }

        if(smallest_index_for_sum[sum - 1] != -1)
            max_length_dense_substring = max(
                max_length_dense_substring,
                i - smallest_index_for_sum[sum - 1]
            );
    }

    return max_length_dense_substring;
}


void solve(long long testcase) {
    long long n;
    string binary_string;

    cin >> n >> binary_string;

    cout << find_max_length_dense_substring(n, binary_string) << "\n";
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