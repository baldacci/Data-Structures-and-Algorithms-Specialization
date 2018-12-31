#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

vector<int> optimal_sequence(int n) {
	std::vector<int> sequence;
	while (n >= 1) {
		sequence.push_back(n);
		if (n % 3 == 0) {
			n /= 3;
		}
		else if (n % 2 == 0) {
			n /= 2;
		}
		else {
			n = n - 1;
		}
	}
	reverse(sequence.begin(), sequence.end());
	return sequence;
}

int idx(int i)
{
	return i - 1;
}

std::vector<int> optimal_sequence_dp(int n) {

	std::vector<int> ops(n, 99999);
	std::vector<int> ptr(n, -1);

	ops[idx(1)] = 0;
	ptr[idx(1)] = -1;

	for (int x = 2; x <= n; ++x)
	{
		int& minNumOps = ops[idx(x)];
		int& parent    = ptr[idx(x)];

		if (x % 3 == 0) {
			int numOps = 1 + ops[idx(x / 3)];
			if (numOps < minNumOps) {
				minNumOps = numOps;
				parent    = x / 3;
			}
		}
		if (x % 2 == 0) {
			int numOps = 1 + ops[idx(x / 2)];
			if (numOps < minNumOps) {
				minNumOps = numOps;
				parent = x / 2;
			}
		}
		if ( x - 1 > 0 )
		{
			int numOps = 1 + ops[idx(x - 1)];
			if (numOps < minNumOps) {
				minNumOps = numOps;
				parent = x - 1;
			}
		}
	}

	std::vector<int> sequence;
	sequence.push_back(n);
	int i = n;
	while (true)
	{
		int next = ptr[idx(i)];
		if (next == -1) break;
		sequence.push_back(next);
		i = next;
	}

	std::reverse(sequence.begin(), sequence.end());

	return sequence;
}

int main() {
	int n;
	std::cin >> n;
	vector<int> sequence = optimal_sequence_dp(n);
	std::cout << sequence.size() - 1 << std::endl;
	for (size_t i = 0; i < sequence.size(); ++i) {
		std::cout << sequence[i] << " ";
	}
}