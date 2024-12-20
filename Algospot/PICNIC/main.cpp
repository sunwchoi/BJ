#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int C, n, m;
int answer;

void f(int idx, unordered_set<int>& selected, vector<vector<bool> >& isFriend)
{
	selected.insert(idx);
	for (int i = idx + 1; i < n; i++)
	{
		if (isFriend[idx][i] && selected.find(i) == selected.end())
		{
			selected.insert(i);
			if (selected.size() == n)
				answer++;
			else
			{
				for (int j = 0; j < n; j++)
				{
					if (selected.find(j) == selected.end())
					{
						f(j, selected, isFriend);
						break ;
					}
				}
			}
			selected.erase(i);
		}
	}
	selected.erase(idx);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> C;
	for (int i = 0; i < C; i++)
	{
		cin >> n >> m;
		vector<vector<bool> > isFriend(n, vector<bool>(n));
		for (int j = 0; j < m; j++)
		{
			int a, b;
			cin >> a >> b;

			isFriend[a][b] = true;
			isFriend[b][a] = true;
		}
		answer = 0;
		unordered_set<int> selected;
		f(0, selected, isFriend);
		cout << answer << "\n";
	}
}
