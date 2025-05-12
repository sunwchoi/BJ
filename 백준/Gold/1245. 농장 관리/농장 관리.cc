#include <iostream>
#include <vector>

using namespace std;

int N, M;
int arr[100][70];
int vi[100][70];
int ans;
int dir[8][2] = { {0, 1} , {0, -1}, {1, 0}, {-1, 0} , {-1, -1}, {-1, 1}, {1, -1}, {1, 1} };
bool check(int idx, int jdx)
{
	vi[idx][jdx] = true;

	for (int i = 0; i < 8; i++)
	{
		int nextIdx = idx + dir[i][0];
		int nextJdx = jdx + dir[i][1];

		if (0 <= nextIdx && nextIdx < N && 0 <= nextJdx && nextJdx < M)
		{
			if ((arr[nextIdx][nextJdx] == arr[idx][jdx] && vi[nextIdx][nextJdx] == false && check(nextIdx, nextJdx) == false)
				|| (arr[nextIdx][nextJdx] > arr[idx][jdx]))
			{
				vi[idx][jdx] = false;
				return false;
			}
		}
	}



	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cin >> arr[i][j];
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (vi[i][j] == false && check(i, j))
					ans++;
		}
	}

	cout << ans << '\n';
}