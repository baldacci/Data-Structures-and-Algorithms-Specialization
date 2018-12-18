#include <iostream>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

size_t gcd_fast(size_t a, size_t b) {
	if(b == 0) return a;
	return gcd_fast(b, a % b);
}


size_t lcm_fast(int a, int b) {
  return size_t(a) * (size_t(b) / gcd_fast(a,b));
}


int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_fast(a, b) << std::endl;
  return 0;
}
