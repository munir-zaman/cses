#include<bits/stdc++.h>
#define ll long long

int main() {
    std::string s;
    std::cin >> s;
    int n = s.size();
    
    // frequency array
    std::vector<int> freq(26, 0);
    for (const char &x: s) {
        freq[x-'A']++;
    }

    int i = 0;
    int odd_index = -1;
    int odd_count = 0;
    for (int j=0; j<26; j++) {
        // count odd frequencies
        if (freq[j]%2 != 0) {
            odd_count++;
            odd_index = j;
        }

        if (odd_count > 1) break;

        while (freq[j] > 1) {
            s[i] = s[n-i-1] = j + 'A';
            i++;
            freq[j] -= 2;
        }
    }

    if (odd_count > 1) {
        printf("NO SOLUTION\n");
    } else {
        if (odd_count == 1) s[i] = odd_index + 'A';
        std::cout << s << std::endl;
    }
}