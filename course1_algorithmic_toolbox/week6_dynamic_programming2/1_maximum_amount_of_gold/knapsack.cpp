// ConsoleApplication3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

class Matrix
{

public:

	Matrix(const int _w, const int _h, const int _v)
		: w(_w)
		, h(_h)
	{
		m.resize(w * h, _v);
	}

	const int& operator()(const int r, const int c) const
	{
		return this->m[r * h + c];
	}

	int& operator()(const int r, const int c)
	{
		return this->m[r * h + c];
	}

	int rows(void) const
	{
		return this->h;
	}

	int cols(void) const
	{
		return this->w;
	}

protected:

	int w;
	int h;
	std::vector<int> m;
};

int optimal_weight(int W, const vector<int> &w)
{
	const int n = w.size();
	Matrix V(n + 1, W + 1, 0);
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= W; ++j)
		{
			V(i, j) = V(i - 1, j);
			const int vi = w[i - 1];
			const int wi = w[i - 1];
			if (wi <= j)
			{
				V(i, j) = std::max(V(i - 1, j), V(i - 1, j - wi) + vi);
			}
		}
	}

	return V(n, W);
}

int main()
{
	int n, W;
	std::cin >> W >> n;
	vector<int> w(n);
	for (int i = 0; i < n; ++i)
	{
		std::cin >> w[i];
	}
	std::cout << optimal_weight(W, w) << '\n';
}
