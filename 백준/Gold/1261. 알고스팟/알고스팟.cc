#include <iostream>
#include <queue>

using namespace std;

int N, M;
int arr[100][100];
bool vi[100][100];
int	dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

bool isValid(int x, int y)
{
	return (0 <= x && x < N && 0 <= y && y < M);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	string input;
	for (int i = 0; i < M; i++)
	{
		cin >> input;
		for (int j = 0; j < N; j++)
			arr[i][j] = input[j] - '0';
	}

	priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
	pq.push({ 0, 0, 0 });

	while (1)
	{
		int n = pq.top()[0];
		int y = pq.top()[1];
		int x = pq.top()[2];

		if (y == M - 1 && x == N - 1)
		{
			cout << n << "\n";
			return 0;
		}

		pq.pop();
		if (vi[y][x])
			continue;

		vi[y][x] = true;
		for (int i = 0; i < 4; i++)
		{
			int nextY = y + dir[i][0];
			int nextX = x + dir[i][1];

			if (isValid(nextX, nextY) && vi[nextY][nextX] == false)
				pq.push({ n + arr[nextY][nextX], nextY, nextX });
		}
	}
}