#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <iostream>

using namespace std;

const long long UPPER_LIMIT = 1e5; 
int main() {
    ofstream out("input_file");
    if (!out.is_open()) {
        cerr << "Error: Could not open the file for writing." << endl;
        return 1;
    }

    srand(static_cast<unsigned>(time(0)));

    long long t = 1000; 
    out << t << "\n";

    for (long long tc = 1; tc <= t; ++tc) {
        long long n, m;
        n = 65432;
        m = rand() % UPPER_LIMIT + 1;

        out << n << " " << m << "\n"; 
    }

    out.close();

    return 0;
}
