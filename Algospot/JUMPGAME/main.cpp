#include <iostream>
#include <vector>

using namespace std;

int C, n;
vector<vector<int> > mp;
vector<vector<bool> > vi;

inline bool isValid(int x)
{
	return 0 <= x && x < n;
}

bool jump(int x, int y)
{
	if (!isValid(x) || !isValid(y))
		return false;
	if (vi[y][x])
		return false;
	if (x == n - 1 && y == n - 1)
		return true;

	vi[y][x] = true;
	int d = mp[y][x];
	return jump(x + d, y) || jump(x, y + d);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> C;
	for (int i = 0; i < C; i++)
	{
		cin >> n;
		mp = vector<vector<int> >(n, vector<int>(n));
		vi = vector<vector<bool> >(n, vector<bool>(n));
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				cin >> mp[j][k];
			}
		}
		if (jump(0, 0))
			cout << "YES" << "\n";
		else
			cout << "NO" << "\n";
	}
}
