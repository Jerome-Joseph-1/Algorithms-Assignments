#include <cassert>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string GREEN = "\033[32m";
string RED = "\033[31m";
string WHITE = "\033[37m";

long long UPPER_LIMIT = 1e5;

long long find_balancing_index(long long n, string& binary_string) {
    long long k = -1;

    for (long long i = 0; i < n; i++) {
        k += binary_string[i] == '1';
    }

    return k;
}

long long find_balancing_index_brute(long long n, string& binary_string) {
    long long k = -1;

    vector<long long> zeros(n), ones(n);
    zeros[0] = binary_string[0] == '0';
    ones[n - 1] = binary_string[n - 1] == '1';

    for(long long i = 1; i < n; i++) {
        if(binary_string[i] == '0') {
            zeros[i] = 1;
        }
        zeros[i] += zeros[i - 1];
    }

    if(ones[n - 1] == zeros[n - 2]) k = n - 2;

    for (long long i = n - 2; i > -1; --i) {
        if(binary_string[i] == '1') {
            ones[i] = 1;
        }

        ones[i] += ones[i + 1];
        if(ones[i] == zeros[i - 1]) k = i - 1;
    }

    if(k == -1 and zeros[n - 1] != n) {
        k = n - 1;
    }

    return k;
}

int main() {
    ifstream in("../input/input_file");
    cin.rdbuf(in.rdbuf());

    long long t;
    cin >> t;

    long long passed_tc = 0;

    for (long long tc = 1; tc <= t; ++tc) {
        long long n; string binary_string;

        cin >> n >> binary_string;

        long long expected_output = find_balancing_index_brute(n, binary_string);
        long long actual_output = find_balancing_index(n, binary_string);

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