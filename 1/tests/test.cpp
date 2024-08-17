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
    vector<vector<long>> a{{1, 1}, {1, 0}};
    vector<vector<long>> I{{1, 0}, {0, 1}};

    while (b > 0) {
        if(b & 1) I = multiply(I, a, m);
        a = multiply(a, a, m);
        b >>= 1;
    }

    return I[0][1];
}

long long nth_fib_simple(long long n, long long m) {
    long long f1 = 0, f2 = 1;

    while (n-- > 0) {
        long long temp = (f1 + f2) % m;
        f1 = f2;
        f2 = temp;
    }

    return f1;
}

int main() {
    ifstream in("../input/input_file");
    cin.rdbuf(in.rdbuf());

    long long t;
    cin >> t;

    long long passed_tc = 0;

    for (long long tc = 1; tc <= t; ++tc) {
        long long n, m;
        cin >> n >> m;
        long long answer = nth_fib_simple(n, m);
        long long output = nth_fib_using_matrix_exponentiation(n, m);

        cout << "Test Case: " << tc << " ";
        if(answer == output) {
            cout << GREEN << "Passed. " << WHITE;
            passed_tc++;
        } else {
            cout << RED << "Failed. " << WHITE;
        }
        printf("F(%lld) mod %lld. Found %lld, expected %lld\n", n, m, output, answer);
    }   

    cout << (passed_tc == t ? GREEN : RED)
              << ("Passed")
              << " (" 
              << (passed_tc == t ? GREEN : RED)
              << passed_tc << " / " << t 
              << WHITE << ")" << endl;  
}   