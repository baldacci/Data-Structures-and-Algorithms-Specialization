#include <iostream>
#include <vector>
#include <algorithm>


int MaxPairwiseProduct(const std::vector<int>& numbers) {
    int max_product = 0;
    int n = numbers.size();

    for (int first = 0; first < n; ++first) {
        for (int second = first + 1; second < n; ++second) {
            max_product = std::max(max_product,
                numbers[first] * numbers[second]);
        }
    }

    return max_product;
}


int MaxPairwiseProductFast(const std::vector<int>& numbers) {
    
    const auto n = numbers.size();
    
    size_t firstIndex =  0;
    int    first      = -1;
    for (size_t i = 0; i < n; ++i)
    {
        if(numbers[i] > first)
        {
            firstIndex = i;
            first      = numbers[i];
        }
    }
    
    size_t secondIndex =  0;
    int    second      = -1;
    for (size_t i = 0; i < n; ++i)
    {
        if(numbers[i] > second && i != firstIndex)
        {
            secondIndex = i;
            second      = numbers[i];
        }
    }

     std::cout << "first "  << first  << "\n";
     std::cout << "second " << second << "\n";

    return first * second;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    int result = MaxPairwiseProductFast(numbers);
    std::cout << result << "\n";
    return 0;
}
