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

long long find_nth_fibonacci_helper(string n, long long m) {
    long long pisano_period = find_pisano_period(m);

    long long equivalent_n = find_mod(n, pisano_period);

    long long answer = find_nth_fibonacci(equivalent_n, m);

    return answer;
}

long long find_nth_fibonacci_linear_time(long long n, long long m) {
    long long f1 = 0, f2 = 1;

    for (long long i = 0, temp; i < n; ++i) {
        temp = (f1 + f2) % m;
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
        string n;
        long long m;

        cin >> n >> m;

        // WARNING: WORKS ONLY FOR N <= 9e18
        long long expected_output = find_nth_fibonacci_linear_time(stoi(n), m);

        long long output = find_nth_fibonacci_helper(n, m);

        cout << "Test Case: " << tc << " ";
        if(expected_output == output) {
            cout << GREEN << "Passed. " << WHITE;
            passed_tc++;
        } else {
            cout << RED << "Failed. " << WHITE;
        }
        printf("F(%s) mod %lld. Found %lld, expected %lld\n", n.c_str(), m, output, expected_output);

    }   

    cout << (passed_tc == t ? GREEN : RED)
              << ("Passed")
              << " (" 
              << (passed_tc == t ? GREEN : RED)
              << passed_tc << " / " << t 
              << WHITE << ")" << endl;  
    return 0;
}   