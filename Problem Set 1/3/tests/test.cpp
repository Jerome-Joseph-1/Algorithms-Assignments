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
    vector<vector<long long>> c(4, vector<long long>(4, 0));    

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < 4; ++k) {
                c[i][j] = (c[i][j] + (a[i][k] * b[k][j]) % m) % m;
            }
        }
    }

    return c;
}

vector<vector<long long>> matrix_exoponentiate(vector<vector<long long>> matrix, long long b, long long m) {
    vector<vector<long long>> I(4, vector<long long>(4, 0));

    for (int i = 0; i < 4; ++i) {
        I[i][i] = 1;
    }

    while (b) {
        if(b & 1) I = multiply(I, matrix, m);
        matrix = multiply(matrix, matrix, m);
        b >>= 1;
    }

    return I;
}

long long find_nth_value(string n, long long m) {
    vector<vector<long long>> matrix{
        {1, 1, 1, 1},
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 0, 1}
    };
    vector<vector<long long>> A = matrix;

    for (long long i = 0; i < n.size(); ++i) {
        int digit = n[i] - '0';
        if(i > 0)
            matrix = matrix_exoponentiate(matrix, 10, m);

        vector<vector<long long>> temp = matrix_exoponentiate(A, digit, m);

        if(i > 0)
            matrix = multiply(matrix, temp, m);
        else
            matrix = temp;
    }

    return (matrix[2][0] * 2 + matrix[2][1] + matrix[2][3]) % m;
}

long long find_nth_value_linear(long long n, long long m) {
    if(n <= 2) return n;

    vector<long long> values{0, 1, 2};

    for (long long i = 3; i <= n; ++i) {
        long long temp = (values[0] + values[1] + values[2] + 1) % m;
        values[0] = values[1];
        values[1] = values[2];
        values[2] = temp;
    }

    return values[2];
}

int main() {
    ifstream in("../input/input_file");
    cin.rdbuf(in.rdbuf());

    long long t;
    cin >> t;

    long long passed_tc = 0;
    for (long long tc = 1; tc <= t; ++tc) {
        string n; long long m;
        cin >> n >> m;
    
        long long expected_output = find_nth_value_linear(stoi(n), m);
        long long output = find_nth_value(n, m);

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