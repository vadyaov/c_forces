#include <iostream>

int t;
int n;
std::string s;

int main() {
  std::cin >> t;
    while (t--) {
        std::cin >> n;
        std::cin >> s;
        int sm = 0;
        for (int i = 0; i < n; i++) {
            sm += s[i] == '+' ? 1 : -1;
        }
        std::cout << abs(sm) << '\n';
    }
}
