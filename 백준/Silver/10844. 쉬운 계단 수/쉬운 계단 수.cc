#include <iostream>
#include <vector>

using namespace std;

vector<vector<unsigned long long> > arr(101, vector<unsigned long long>(10));

unsigned long long	recur(int n, int start)
{
	if (arr[n][start])
		return arr[n][start];
	if (start != 9)
		arr[n][start] += recur(n - 1, start + 1);
	if (start != 0)
		arr[n][start] += recur(n - 1, start - 1);
	arr[n][start] %= 1000000000;
	return arr[n][start];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int	N;
	cin >> N;
	arr[1] = vector<unsigned long long>(10, 1);
	for (int i = 0; i < 10; i++)
		recur(N, i);
	int	sum = 0;
	for (int i = 1; i < 10; i++)
	{
		sum += arr[N][i];
		sum %= 1000000000;
	}
	cout << sum<< "\n";
}