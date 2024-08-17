#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<long long>> multiply(vector<vector<long long>>& a, vector<vector<long long>>& b, long long m) {
    vector<vector<long long>> c{{0, 0}, {0, 0}};    

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                c[i][j] = (c[i][j] + (a[i][k] * b[k][j]) % m) % m;
            }
        }
    }

    return c;
}

long long find_mod(string n, long long m) {
    long long remainder = 0;

    for (long long i = 0; i < n.size(); ++i) {
        long long digit = n[i] - '0';
        remainder = (remainder * 10 + digit) % m;
    }

    return remainder;
}

long long find_nth_fibonacci(long long n, long long m) {
    vector<vector<long long>> I{{1, 0}, {0, 1}};
    vector<vector<long long>> M{{1, 1}, {1, 0}};

    while (n) {
        if(n & 1) I = multiply(I, M, m);
        M = multiply(M, M, m);
        n >>= 1;
    }

    return I[0][1];
}

long long find_pisano_period(long long m) {
    long long f1 = 0, f2 = 1;
    for (long long period = 1, temp; period <= 6 * m; ++period) {
        temp = (f1 + f2) % m;
        f1 = f2;
        f2 = temp;

        if(f1 == 0 and f2 == 1)
            return period;
    }
    
    // Error
    return -1;
}

void solve(long long testcase) {
    string n;
    long long m;
    cin >> n >> m;

    long long pisano_period = find_pisano_period(m);

    long long equivalent_n = find_mod(n, pisano_period);

    long long answer = find_nth_fibonacci(equivalent_n, m);

    cout << answer << "\n";
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