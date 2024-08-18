#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

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

void solve(long long testcase) {
    long long n;
    cin >> n;
    string binary_string;
    cin >> binary_string;

    vector<long long> prefix(n);

    prefix[0] = binary_string[0] == '1'? 1 : -1;

    for (long long i = 1; i < n; ++i) {
        prefix[i] = prefix[i - 1] + (binary_string[i] == '1' ? 1 : -1);
    }

    // The number of substrings which are dense can be found by calculating the
    // number of pairs (ai, aj) such that ai < aj and i < j 

    long long total_dense_substrings = merge_sort(prefix, 0, n - 1);

    cout << total_dense_substrings << "\n";
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