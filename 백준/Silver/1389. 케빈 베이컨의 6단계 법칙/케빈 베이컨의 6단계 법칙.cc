#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int	N, M, u, v;
int min = INT_MAX;
int	ret = 0;
vector<int>	vt[101];

int	bfs(int R)
{
	queue<pair<int, int> > que;
	vector<bool>	vi(N);
	int	kb = 0;
	
	que.push(make_pair(R, 0));
	vi[R] = true;

	while (que.size())
	{
		int	n = que.front().first;
		int depth = que.front().second;
		kb += depth;
		
		int	size = vt[n].size();
		for (int i = 0; i < size; i++)
			if (!vi[vt[n][i]])
			{
				que.push(make_pair(vt[n][i], depth + 1));
				vi[vt[n][i]] = true;
			}
		que.pop();
	}
	return kb;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> u >> v;
		vt[u].push_back(v);
		vt[v].push_back(u);
	}
	for (int i = N; i >= 1; i--)
	{
		int kb = bfs(i);
		if (kb <= ::min)
		{
			::min = kb;
			ret = i;
		}
	}
	cout << ret << "\n";

}