#include <bits/stdc++.h>

int main() {
  std::vector<std::string> gray_code = {"0", "1"};
  int n;
  std::cin >> n;

  int i = 1;
  while (n > i) {
    // insert reversed list
    for (int j = 0; j < (1 << i); j++) {
      gray_code.push_back(gray_code[(1 << i) - j - 1]);
    }

    for (int k = 0; k < (1 << i); k++) {
      gray_code[k].push_back('0');
      gray_code[(1 << i) + k].push_back('1');
    }
    i++;
  }
  for (const std::string &s : gray_code)
    std::cout << s << "\n";
}