#include <iostream>

using namespace std;

int C, N, L;
int cost[1001];
double answer;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout.precision(11);

	cin >> C;
	for (int i = 0; i < C; i++)
	{
		answer = 101;

		cin >> N >> L;
		cin >> cost[1];
		for (int j = 2; j <= N; j++)
		{
			cin >> cost[j];
			cost[j] += cost[j - 1];
		}
		for (int j = L; j <= N; j++)
		{
			for (int k = 0; j + k <= N; k++)
			{
				answer = min(answer, double(cost[j + k] - cost[k]) / double(j));	
			}
		}
		cout << answer << "\n";
	}
	
}
