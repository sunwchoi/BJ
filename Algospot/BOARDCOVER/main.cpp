#include <iostream>
#include <vector>

using namespace std;

int C, H, W, answer;
vector<vector<bool> > mp;
int dx[] = {0, -1, 0, 1, 0, 1, 1, 1};
int dy[] = {1, 1, 1, 1, 1, 0, 0, 1};

bool isValid(int y, int x)
{
	if (!(0 <= x && x < W))
		return false;
	if (!(0 <= y && y < H))
		return false;
	return !mp[y][x] ; 
}

void fill(int pre_h, int pre_w, int emptyCnt)
{
	int h = -1, w = -1;

	for (int i = pre_h; i < H; i++)
	{
		for (int j = i == pre_h ? pre_w : 0; j < W; j++)
		{
			if (mp[i][j] == false)
			{
				h = i; w = j;
				break ;	
			}
		}	
		if (h != -1)
			break ;
	}

	if (h == -1 && w == -1)
	{
		if (emptyCnt == 0)
		{
			answer++;
		}
		return ;
	}

	mp[h][w] = true;
	for (int i = 0; i < 4; i++)
	{
		int y0 = h + dy[i * 2];
		int y1 = h + dy[i * 2 + 1];

		int x0 = w + dx[i * 2];
		int x1 = w + dx[i * 2 + 1];
		
		if (isValid(y0, x0) && isValid(y1, x1))
		{
			mp[y0][x0] = true;
			mp[y1][x1] = true;

			fill(h, w + 1, emptyCnt - 3);

			mp[y0][x0] = false;
			mp[y1][x1] = false;
		}
	}
	mp[h][w] = false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> C;
	for (int i = 0; i < C; i++)
	{
		cin >> H >> W;

		char c = 0;
		int emptyCnt = 0;
		mp = vector<vector<bool> >(H, vector<bool>(W));
		answer = 0;

		for (int j = 0; j < H; j++)
		{
			for (int k = 0; k < W; k++)
			{
				cin >> c;

				if (c == '#')
					mp[j][k] = true;
				else
					emptyCnt++;
			}
		}
		fill(0, 0, emptyCnt);
		cout << answer << "\n";		
	}
}
