#include <cassert>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

string GREEN = "\033[32m";
string RED = "\033[31m";
string WHITE = "\033[37m";

long long UPPER_LIMIT = 1e5;

long long find_max_length_dense_substring(long long n, string& binary_string) {
    unordered_map<long long, long long> smallest_index_for_sum;

    long long sum = 0, max_length_dense_substring = 0;
    for (long long i = 0; i < n; ++i) {
        sum += binary_string[i] == '1' ? 1 : -1;

        if(smallest_index_for_sum.find(sum) == smallest_index_for_sum.end())
            smallest_index_for_sum[sum] = i;

        if(sum > 0) {
            max_length_dense_substring = i + 1;
            continue;
        }

        max_length_dense_substring = max(
            max_length_dense_substring,
            smallest_index_for_sum.find(sum - 1) == smallest_index_for_sum.end() ? 0 : i - smallest_index_for_sum[sum - 1]
        );
    }

    return max_length_dense_substring;
}

long long find_max_length_dense_substring_brute(long long n, string& binary_string) {
    long long max_length = 0;

    for (long long i = 0; i < n; ++i) {
        long long sum = 0;
        for (long long j = i; j < n; ++j) {
            sum += binary_string[j] == '1' ? 1: -1;

            if(sum > 0) max_length = max(j - i + 1, max_length);
        }
    }

    return max_length;
}

int main() {
    ifstream in("../input/input_file");
    cin.rdbuf(in.rdbuf());

    long long t;
    cin >> t;

    long long passed_tc = 0;

    for (long long tc = 1; tc <= t; ++tc) {
        long long n;
        string binary_string;

        cin >> n >> binary_string;

        long long expected_output = find_max_length_dense_substring_brute(n, binary_string);
        long long actual_output = find_max_length_dense_substring(n, binary_string);

        cout << "Test Case: " << tc << " ";
        if(expected_output == actual_output) {
            passed_tc++;
            cout << GREEN << "Passed. " << WHITE;
        } else {
            cout << RED << "Failed. " << WHITE;
        }

        printf("Found %lld, expected %lld\n", actual_output, expected_output);
    }   

    cout << (passed_tc == t ? GREEN : RED)
              << ("Passed")
              << " (" 
              << (passed_tc == t ? GREEN : RED)
              << passed_tc << " / " << t 
              << WHITE << ")" << endl;  
    return 0;
}   