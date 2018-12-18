#include <iostream>
#include <vector>

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}

size_t get_fibonacci_last_digit_fibonacci_fast(int n) {
    // write your code here
    std::vector<size_t> fib;
    fib.resize(n + 1, 0);
    fib[0] = 0;
    fib[1] = 1;
    for(int i = 2; i < fib.size(); ++i)
    {
        fib[i] = (fib[i - 1] + fib[i - 2]) % 10;
    }

    return fib.back();
}

int main() {
    int n;
    std::cin >> n;
    int c = get_fibonacci_last_digit_fibonacci_fast(n);
    std::cout << c << '\n';
    }
