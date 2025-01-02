#include <iostream>

using namespace std;

int C, N;
long long tileCnt[100];

long long getTileCount(int n)
{
	if (tileCnt[n - 1])
		return tileCnt[n - 1];
	return tileCnt[n - 1] = (getTileCount(n - 1) + getTileCount(n - 2)) % 1000000007;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> C;
	tileCnt[0] = 1;
	tileCnt[1] = 2;
	for (int i = 0; i < C; i++)
	{
		cin >> N;
		cout << getTileCount(N) << "\n";
	}
}
