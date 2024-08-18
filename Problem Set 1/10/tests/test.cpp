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

long long find_max_balanced_substring_brute(long long n, string& binary_string) {
    long long max_length = 0;
    for (long long i = 0; i < n; ++i) {
        long long sum = 0;
        for (long long j = i; j < n; ++j) {
            sum += binary_string[j] == '1' ? 1 : -1;

            if(sum == 0) max_length = max(max_length, j - i + 1);
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

        long long expected_output = find_max_balanced_substring_brute(n, binary_string);
        long long actual_output = find_max_balanced_substring(n, binary_string);

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