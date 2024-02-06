#include <iostream>
#include <queue>

using namespace std;

int N, K;
bool	vi[100001];

int	bfs(int start, int goal)
{
	queue<pair<int, int> >	que;

	que.push(make_pair(start, 0));
	while (1)
	{
		pair<int, int> tmp = que.front();
		que.pop();
		if (tmp.first < 0 || 100000 < tmp.first || vi[tmp.first])
			continue;
		if (tmp.first == goal)
			return tmp.second;
		vi[tmp.first] = true;
		que.push(make_pair(tmp.first + 1, tmp.second + 1));
		que.push(make_pair(tmp.first - 1, tmp.second + 1));
		que.push(make_pair(tmp.first * 2, tmp.second + 1));
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;
	cout << bfs(N, K)<< "\n";
}