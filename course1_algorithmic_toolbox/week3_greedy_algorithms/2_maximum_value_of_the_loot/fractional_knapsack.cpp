#include <iostream>
#include <vector>
#include <utility>
#include <algorithm> 

using std::vector;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  
  using ItemInfo = std::pair<int, int>;
  using SortInfo = std::pair<double, ItemInfo>;
  
  vector<SortInfo> items;
  for(int i = 0; i < weights.size(); ++i)
  {
    const double unitValue = double(values [i]) / double(weights[i]);
    items.emplace_back(std::make_pair(unitValue, std::make_pair(weights[i], values[i])));
  }
  std::sort(items.begin(), items.end(), std::greater<SortInfo>());
  
  for(int i = 0; i < items.size(); ++i)
  {
    const double uv = items[i].first;
    const int   w  = items[i].second.first;
    const int   x  = std::min(w, capacity);
    capacity -= x;
    value    += uv * double(x);
  }
  
  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
