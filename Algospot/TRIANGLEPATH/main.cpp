#include <iostream>

using namespace std;

int C, n;
int sum[100][100];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> C;
	for (int i = 0; i < C; i++)
	{
		cin >> n;
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < j + 1; k++)
			{
				cin >> sum[j][k];

				if (j !=0)
				{
					if (k != 0)
						sum[j][k] += max(sum[j - 1][k - 1], sum[j - 1][k]);
					else
						sum[j][k] += sum[j - 1][k];
				}
			}
		}

		int answer = 0;
		for (int j = 0; j < n; j++)
		{
			answer = max(answer, sum[n - 1][j]);
		}
		cout << answer << "\n";
	}
}
