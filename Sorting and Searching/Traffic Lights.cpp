#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

template <typename T>
void print_vec(vector<T> v) {
	for (const auto &a : v) {cout << a << ", ";}
	cout << endl;
}

struct street_sec {
    ll start;
    ll end;
};

bool comp(street_sec a, street_sec b) {
    if (abs(a.start - a.end + 1) > abs(b.start - b.end + 1)) {
        return true;
    }
    else return false;
}

vector<ll> solve(ll x, ll n, vector<ll> lights) {
    vector<ll> ans;
    return ans;
}

int main() {
    ll  x, n;
    cin >> x >> n;

    vector<ll> lights(n);
    for (int i = 0; i < n; i++) {
        cin >> lights[i];
    }

    vector<ll> ans = solve(x, n, lights);
    print_vec(ans);
}