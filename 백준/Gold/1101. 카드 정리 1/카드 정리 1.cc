#include <iostream>

using namespace std;

int N, M;
int mix;
int notMix[50];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	constexpr int invalidKey = 51;
	for (int i = 0; i < N; i++)
	{
		int key = -1;
		for (int j = 0; j < M; j++)
		{
			int n;
			cin >> n;

			if (key == invalidKey)
				continue;

			if (n > 0)
				key = key < 0 ? j : invalidKey;
			
		}

		if (key == invalidKey)
			mix++;
		else
			notMix[key]++;
	}

	int answer = 0;
	for (int i = 0; i < M; i++)
	{
		if (notMix[i])
			answer += notMix[i] - 1;
	}
	answer += mix - 1;

	cout << (answer < 0 ? 0 : answer) << "\n";
	
}