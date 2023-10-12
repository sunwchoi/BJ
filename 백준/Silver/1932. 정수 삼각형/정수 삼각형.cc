#include <iostream>
#include <vector>

using namespace std;

int	N;
vector<int>	sum(500);

void	dp(int	stair)
{
	if (stair > N)
		return;
	int	left = -1;
	for (int i = 0; i < stair; i++)
	{
		int right = -1;
		if (i != stair - 1)
			right = sum[i];
		cin >> sum[i];
		(right > left) ? sum[i] += right : sum[i] += left;
		left = right;
	}
	dp(stair + 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	cin >> sum[0];
	dp(2);
	int	max = sum[0];
	for (int i = 1; i < N; i++)
	{
		if (max < sum[i])
			max = sum[i];
	}
	cout << max << "\n";
}