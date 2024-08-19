#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <iostream>

using namespace std;

const long long UPPER_LIMIT = 1e3; 
int main() {
    ofstream out("input_file");
    if (!out.is_open()) {
        cerr << "Error: Could not open the file for writing." << endl;
        return 1;
    }

    srand(static_cast<unsigned>(time(0)));

    long long t = UPPER_LIMIT; 
    out << t << "\n";

    for (long long tc = 1; tc <= t; ++tc) {
        long long n = rand() % UPPER_LIMIT + 1;

        out << n << "\n";
        for (long long i = 0; i < n; ++i) {
            out << rand() % UPPER_LIMIT << " ";
        }
        out << "\n";   
    }

    out.close();

    return 0;
}
