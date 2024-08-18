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

long long merge_subarrays(vector<long long>& prefix, long long l, long long mid, long long r) {
    long long i = l, j = mid + 1;
    long long count = 0;

    vector<long long> temp(r - l + 1);
    long long temp_ptr = 0;
    while (i <= mid and j <= r) {
        if(prefix[i] < prefix[j]) {
            count += r - j + 1;
            temp[temp_ptr++] = prefix[i++];
        } else 
            temp[temp_ptr++] = prefix[j++];
    }

    long long remaining_start = i <= mid ? i : j, remaining_end = i <= mid ? mid: r;
        
    while (remaining_start <= remaining_end) {
        temp[temp_ptr++] = prefix[remaining_start++];
    }

    for (long long i = l; i <= r; ++i) {
        prefix[i] = temp[i - l];
    }

    return count;
}

long long merge_sort(vector<long long>& prefix, long long l, long long r) {
    long long count = 0;
    if(l < r) {
        long long mid = l + (r - l) / 2;

        long long l1 = merge_sort(prefix, l, mid);
        long long l2 = merge_sort(prefix, mid + 1, r);

        long long l3 = merge_subarrays(prefix, l, mid, r);

        count = l1 + l2 + l3;
    } else if(prefix[l] > 0) count++;
    return count;
}

long long find_valid_substring(long long n, string binary_string) {
    long long count = 0;

    for (long long i = 0; i < n; ++i) {
        long long sum = 0;
        for (long long j = i; j < n; ++j) {
            sum += binary_string[j] == '1' ? 1: -1;
            if(sum > 0) count++;
        }
    }

    return count;
}


int main() {
    ifstream in("../input/input_file");
    cin.rdbuf(in.rdbuf());

    long long t;
    cin >> t;

    long long passed_tc = 0;

    for (long long tc = 1; tc <= t; ++tc) {
        long long n;
        string s;
        cin >> n >> s;

        vector<long long> prefix(n);

        prefix[0] = s[0] == '1' ? 1 : -1;
        for (long long i = 1; i < n; ++i) {
            prefix[i] = prefix[i - 1] + (s[i] == '1' ? 1: -1);
        }

        long long expected_output = find_valid_substring(n, s);
        long long actual_output = merge_sort(prefix, 0, n - 1); 

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