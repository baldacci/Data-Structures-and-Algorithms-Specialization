#include <iostream>
#include <algorithm> 
#include <string>
#include <vector>

using std::string;

enum class move
{
	  LEFT = 0
	, DOWN = 1
	, DIAG = 2
};

class Matrix
{

public:

	Matrix(const int _w, const int _h)
		:w(_w)
		,h(_h)
	{
		m.resize(w * h);
	}

	const int& operator()(const int r, const int c) const
	{
		return m[r * h + c];
	}

	int& operator()(const int r, const int c)
	{
		return m[r * h + c];
	}

protected:

	int w;
	int h;
	std::vector<int> m;
};

inline int min(int x, int y, int z)
{
	return std::min(std::min(x, y), z);
}

int edit_distance(const string &str1, const string &str2) {

	const int l1 = str1.length();
	const int l2 = str2.length();

	const int n = l1 + 1;
	const int m = l2 + 1;

	Matrix D  (n, m);
	Matrix ptr(n, m);

	for (int i = 0; i < n; ++i)
	{
		D(i,0) = i;
	}
	for (int j = 0; j < m; ++j)
	{
		D(0,j) = j;
	}

	for (int i = 1; i < n; ++i)
	{
		for (int j = 1; j < m; ++j)
		{
			if (str1[i - 1] == str2[j - 1])
			{
				D  (i, j) = D(i - 1, j - 1);
				ptr(i, j) = int(move::DIAG);
			}
			else
			{
				const int left = D(i - 1, j    );
				const int down = D(i    , j - 1);
				const int diag = D(i - 1, j - 1);
				const int Dij  = min(left, down, diag);

				if (Dij == left)
				{
					D  (i, j) = left + 1;
					ptr(i, j) = int(move::LEFT);
				}
				else if (Dij == down)
				{
					D  (i, j) = down + 1;
					ptr(i, j) = int(move::DOWN);
				}
				else if (Dij == diag)
				{
					D  (i, j) = diag + 1;
					ptr(i, j) = int(move::DIAG);
				}
			}
		}
	}

	//for (int i = 0; i < n; ++i)
	//{
	//	for (int j = 0; j < m; ++j)
	//	{
	//		std::cout << D(i, j) << " ";
	//	}
	//	std::cout << "\n";
	//}

	return D(l1, l2);
}

int main() {
	string str1;
	string str2;
	std::cin >> str1 >> str2;
	std::cout << edit_distance(str1, str2) << std::endl;
	return 0;
}
