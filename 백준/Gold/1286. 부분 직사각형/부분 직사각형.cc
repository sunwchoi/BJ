#include <iostream>

using namespace std;

int N, M;
char input[51];
long long output[26];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> input;
		
		int n = (i + 1) * (2 * N - i) + (i + N + 1) * (N - i);
		for (int j = 0; j < M; j++)
		{
			int m = (j + 1) * (2 * M - j) + (j + M + 1) * (M - j);

			output[input[j] - 'A'] += n * m;
		}
	}

	for (int i = 0; i < 26; i++)
		cout << output[i] << "\n";
}