#include <fstream>
#include <iostream>

using namespace std;

long long find_balancing_index(long long n, string& binary_string) {
    long long k = -1;

    for (long long i = 0; i < n; i++) {
        k += binary_string[i] == '1';
    }

    return k;
}

void solve(long long testcase) {
    long long n;
    string binary_string;

    cin >> n >> binary_string;

    cout << find_balancing_index(n, binary_string) << "\n";
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