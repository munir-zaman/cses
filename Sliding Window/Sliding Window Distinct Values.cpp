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

    vector<long long> windows(n - k + 1, 0);
    map<long long, long long> seen;
    for (long long i = 0; i < k; i++) {
        if (seen[x[i]] == 0) windows[0]++;
        seen[x[i]]++;
    }

    for (long long i = 1; i + k - 1 < n; i++) {
        windows[i] = windows[i - 1];
        if (seen[x[i - 1]] == 1) windows[i]--;
        seen[x[i - 1]]--;
        if (seen[x[i + k - 1]] == 0) windows[i]++;
        seen[x[i + k - 1]]++;
    }

    for (const auto &w : windows) {
        cout << w << " ";
    }
    cout << endl;
}
