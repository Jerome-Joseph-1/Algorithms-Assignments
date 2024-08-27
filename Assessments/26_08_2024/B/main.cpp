#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

void solve(long long testcase) {
    long long n, k;
    cin >> n >> k;

    vector<long long> a(n);

    for (long long i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long i, j, ans = 0, min_found = a[k];
    i = j = k;

    while(i > -1 and j < n) {
        min_found = min(min_found, min(a[i], a[j]));
        ans = max(ans, min_found * (j - i + 1));

        if(i - 1 > -1 and j + 1 < n) {
            if(a[i-1] < a[j+1])
                j++;
            else 
                i--;
        } else if(i - 1 > -1) i--;
        else j++;
    }

    while(i > -1) {
        min_found = min(min_found, a[i]);
        ans = max(ans, min_found * (j - i));
        i--;
    }

    while(j < n) {
        min_found = min(min_found, a[j]);
        ans = max(ans, min_found * (j - i));
        j++;
    }

    cout << ans << "\n";
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