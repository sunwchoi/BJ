#include <iostream>
#include <set>

using namespace std;

#define MAX 10000001
int N, T;
bool com[MAX];
set<int> comPrime;

bool isComprime(int n)
{
	for (int i = 100; i <= n; i *= 10)
	{
		for (int j = 1; i * j <= n * 10; j *= 10)
		{
			if (com[(n / j) % i] == true)
				return false;
		}
	}

	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 2; i * i < MAX; i++)
	{
		if (com[i])
			continue;

		for (int j = i * i; j < MAX; j += i)
			com[j] = true;
	}

	for (int i = 100; i < MAX; i++)
	{
		if (i >= 100 && com[i] == true && isComprime(i))
			comPrime.insert(i);
	}

	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> N;

		auto it = comPrime.upper_bound(N);
		cout << (--it == comPrime.end() ? -1 : *it) << "\n";
	}
}