#include <iostream>

using namespace std;

int N, M;
int r, c, d;
int table[50][50];
int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> r >> c >> d;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cin >> table[i][j];
	}

	int ans = 0;
	while (1)
	{
		// cout << r << " " << c << " " << d << "\n";
		// for (int i = 0; i < N; i++)
		// {
		// 	for (int j = 0; j < M; j++)
		// 		cout << table[i][j];
		// 	cout << "\n";
		// }

		if (table[r][c] == 0)
		{
			table[r][c] = 2;
			ans++;
		}

		bool isClean = true;
		for (int i = 0; i <= 4; i++)
		{
			int nR = r + dir[(d + i) % 4][0];
			int nC = c + dir[(d + i) % 4][1];

			if (table[nR][nC] == 0)
			{
				isClean = false;
				break;
			}
		}

		if (isClean)
		{
			r += -dir[d][0];
			c += -dir[d][1];

			if (table[r][c] == 1)
				break;
		}
		else
		{
			--d;
			if (d < 0)
				d = 3;

			int nR = r + dir[d][0];
			int nC = c + dir[d][1];
			if (table[nR][nC] == 0)
			{
				r = nR;
				c = nC;
			}
		}
	}

	cout << ans << "\n";
}
