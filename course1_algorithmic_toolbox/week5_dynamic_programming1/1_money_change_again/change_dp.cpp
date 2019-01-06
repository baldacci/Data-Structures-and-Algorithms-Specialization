#include <iostream>
#include <vector>
#include <array>

int get_change(int money) {
  
  std::vector<int>    minNumCoins(money + 1, 0);
  std::array <int, 3> coins = {1, 3, 4};
  
  for(int m = 1; m < minNumCoins.size(); ++m)
  {
    minNumCoins[m] = 999999;
    for(int i = 0; i < 3; ++i)
    {
        if(m >= coins[i])
        {
            int numCoins = minNumCoins[m - coins[i]] + 1;
            if(numCoins < minNumCoins[m])
            {
                minNumCoins[m] = numCoins;
            }
        }
    }
  }
  
  return minNumCoins[money];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
