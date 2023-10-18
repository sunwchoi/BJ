#include <iostream>
#include <vector>

using namespace std;

int	N;
vector<int>	A(1000);
vector<int>	length(1000);

int	dp(int idx)
{
	if (length[idx])
		return length[idx];
	int max = 0;
	for (int i = idx; i < N; i++)
	{
		if (A[idx] < A[i] && max < dp(i))
			max = length[i];
	}
	length[idx] = max + 1;
	return length[idx];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	int	max = 0;
	for (int i = 0; i < N; i++)
		if (max < dp(i))
			max = length[i];
	cout << max << "\n";
}