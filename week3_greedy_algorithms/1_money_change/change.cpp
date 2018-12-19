#include <iostream>
#include <array>

int get_change(int m) {
  std::array<int, 3> coins = {10, 5, 1};
  int i = 0;
  int n = 0;
  while(m > 0)
  {
    while(m >= coins[i])
    {
        m -= coins[i];
        ++n;
    }
    ++i;
  }
  return n;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
