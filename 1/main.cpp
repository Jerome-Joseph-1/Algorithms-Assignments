#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<long>> multiply(vector<vector<long>>& a, vector<vector<long>>& b, long m) {
    vector<vector<long>> c{{0, 0}, {0, 0}};

    for (long long i = 0; i < 2; ++i) {
        for (long long j = 0; j < 2; ++j) {
            for (long long k = 0; k < 2; ++k) {
                c[i][j] = (c[i][j] + (a[i][k] * b[k][j]) % m)% m;
            }
        }
    }

    return c;
}

long long nth_fib_using_matrix_exponentiation(long long b, long long m) {
    vector<vector<long>> a{{1, 1}, {1, 0    }};
    vector<vector<long>> I{{1, 0}, {0, 1}};

    while (b > 0) {
        if(b & 1) I = multiply(I, a, m);
        a = multiply(a, a, m);
        b >>= 1;
    }

    return I[0][1];
}

void solve(long long testcase) {
    // Find 'N'th fibonacci modulo 'M'
    long long n, m; 
    cin >> n >> m;

    cout << nth_fib_using_matrix_exponentiation(n, m) << "\n";
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