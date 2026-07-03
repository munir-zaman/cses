#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    long long n, k;
    cin >> n >> k;

    vector<long long> x(n, 0);
    for (long long i = 0; i < n; i++) {
        cin >> x[i];
    }

    vector<long long> mex_win(n - k + 1, 0);
    set<long long> excluded;
    vector<long long> freq(k + 1, 0);
    for (long long i = 0; i <= k; i++) excluded.insert(i);

    // to get the min of an ordered set
    // just do : min_ex = *excluded.begin();
    for (long long i = 0; i < k; i++) {
        // erase included element
        if (0 <= x[i] && x[i] <= k) {
            excluded.erase(x[i]);
            freq[x[i]]++;
        }
    }
    mex_win[0] = *excluded.begin();

    for (long long i = 1; i + k - 1 < n; i++) {
        if (0 <= x[i - 1] && x[i - 1] <= k) {
            freq[x[i - 1]]--;
            if (freq[x[i - 1]] == 0) excluded.insert(x[i - 1]);
        }
        if (0 <= x[i + k - 1] && x[i + k - 1] <= k) {
            freq[x[i + k - 1]]++;
            excluded.erase(x[i + k - 1]);
        }

        mex_win[i] = *excluded.begin();
    }

    for (const auto &w : mex_win) cout << w << " ";
    cout << endl;
}
