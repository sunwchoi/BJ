#include <iostream>
#include <vector>

using namespace std;

int C;
int arr[16];
int answer;
vector<vector<int> > swt = {
	{0, 1, 2},
	{3, 7, 9, 11},
	{4, 10, 14, 15},
	{0, 4, 5, 6, 7},
	{6, 7, 8, 10, 12},
	{0, 2, 14, 15},
	{3, 14, 15},
	{4, 5, 7, 14, 15},
	{1, 2, 3, 4, 5},
	{3, 4, 5, 9, 13}
};

void f(int idx, int cnt)
{
	if (idx == 10)
	{
		for (int i = 0; i < 16; i++)
		{
			if (arr[i] % 4 != 3)
				return ;
		}
		answer = answer == -1 ? cnt : min(answer, cnt);
		return ;
	}

	size_t len = swt[idx].size();
	for (int i = 0; i < 4; i++)
	{
		f(idx + 1, cnt + i);
		for (int j = 0; j < len; j++)
		{
			arr[swt[idx][j]] += 1;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> C;
	for (int i = 0; i < C; i++)
	{
		answer = -1;
		for (int j = 0; j < 16; j++)
		{
			cin >> arr[j];
			arr[j] = arr[j] / 3 - 1;
		}
		f(0, 0);
		cout << answer << "\n";
	}
}
