#include <iostream>
#include <queue>

using namespace std;

int	N, M;
string	s[100];
bool	vi[100][100];
queue<pair<pair<int, int>, int> > qu;

bool	isValid(int x, int y)
{
	if (!((0 <= x && x < M) && (0 <= y && y < N)))
		return false;
	if (vi[y][x] || s[y][x] == '0')
		return false;
	return true;
}

void	visit(int x, int y, int n)
{
	qu.push(make_pair(make_pair(x, y), n));
	vi[y][x] = true;
}

int	f()
{
	qu.push(make_pair(make_pair(0, 0), 0));
	vi[0][0] = true;
	while (qu.size())
	{
		int x = qu.front().first.first;
		int y = qu.front().first.second;
		int	n = qu.front().second + 1;

		qu.pop();
		if (x == M - 1 && y == N -1)
			return n;
		if (isValid(x - 1, y))
			visit(x - 1, y, n);
		if (isValid(x + 1, y))
			visit(x + 1, y, n);
		if (isValid(x, y - 1))
			visit(x, y - 1, n);
		if (isValid(x, y + 1))
			visit(x, y + 1, n);
	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> s[i];
	cout << f() << "\n";
}