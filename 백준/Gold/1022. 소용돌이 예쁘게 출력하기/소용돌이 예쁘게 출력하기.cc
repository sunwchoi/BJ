#include <iostream>
#include <vector>

using namespace std;

int r1, c1, r2, c2;
vector<vector<int>> ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> r1 >> c1 >> r2 >> c2;

	int h = r2 - r1 + 1;
	int w = c2 - c1 + 1;

	ans = vector<vector<int>>(h, vector<int>(w));
	int cnt = w * h;
	int x = 0;
	int y = 0;
	int num = 1;
	int n = 1;
	int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
	int cmd[4] = { 0, 0, 0, 1 };
	int dirIdx = 0;

	int mx = 0;
	while (cnt)
	{
		if (c1 <= x && x <= c2 && r1 <= y && y <= r2)
		{
			ans[y - r1][x - c1] = num;
			mx = max(num, mx);
			if (--cnt == 0)
				break;
		}

		while (dirIdx < 4 && cmd[dirIdx] == 0)
			dirIdx++;

		if (dirIdx == 4)
		{
			n += 2;
			cmd[0] = n - 2;
			cmd[1] = (cmd[2] = n - 1);
			cmd[3] = n;
			dirIdx = 0;
		}

		y += dir[dirIdx][0];
		x += dir[dirIdx][1];
		cmd[dirIdx]--;
		num++;
	}

	int l = 0;
	while (mx)
	{
		l++;
		mx /= 10;
	}


	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cout.width(l);
			cout.fill(' ');
			cout << ans[i][j];
			if (j != w - 1)
				cout << " ";
		}
		cout << "\n";
	}
}