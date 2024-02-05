#include <iostream>
#include <vector>

using namespace std;

int	N, M;
vector<bool>	but(10, true);

bool	isValid(int n)
{
	if (n == 0)
		return true;
	if (but[n % 10])
		return isValid(n/10);
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int tmp;
		cin >> tmp;
		but[tmp] = false;
	}

	int ret = abs(N - 100);
	if (but[0])
		ret = min(ret, (N + 1));
	for (int i = 1; i < 1000000; i++)
	{
		if (isValid(i))
			ret = min((unsigned long)ret, (abs(N - i) + to_string(i).size()));
	}
	cout << ret << "\n";
}