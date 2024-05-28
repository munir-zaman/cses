#include<bits/stdc++.h>
#define ll long long

int main() {

    std::string s;
    std::cin >> s;

    std::vector<int> freq(26,0);
    for (const char &x: s) {
        freq[(int)(x-'A')]++;
    }

    std::string p;
    int odd_count = 0;
    int odd_char = 0;
    for (int c=0; c<26; c++) {
        if (freq[c]%2==0) {
            for (int k=0; k<freq[c]/2; k++) {
                p.push_back((char)(c+'A'));
            }
        }
        else {
            odd_count++;
            odd_char = c;   
        }
    }

    p.push_back((char)(odd_char+'A'));
    if (odd_count > 1) std::cout << "NO SOLUTION\n";
    else {
        std::string temp_p = p;
        for (int i=temp_p.size()-1-odd_count; i>=0; i--) p.push_back(temp_p[i]);
        std::cout << p << "\n";
    }
}