#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    long long n, k;
    cin >> n >> k;
    long long x1, a, b, c;
    cin >> x1 >> a >> b >> c;

    vector<long long> x(n, 0);
    x[0] = x1;
    for (long long i = 0; i < n - 1; i++) {
        x[i + 1] = (a * x[i] + b) % c;
    }

    long long window = 0;
    for (long long i = 0; i < k; i++) window += x[i];
    long long windows_xor = window;
    for (long long i = 1; i + k - 1 < n; i++) {
        window = window - x[i - 1] + x[i + k - 1];
        windows_xor ^= window;
    }
    cout << windows_xor << endl;

}
