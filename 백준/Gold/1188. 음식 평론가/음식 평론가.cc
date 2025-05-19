#include <iostream>

using namespace std;

int N, M;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	
	int n = N; int d = M;

	int cnt = 0;
	while (n != N * M)
	{
		if (n % d != 0)
			cnt++;
		n += N;
	}

	cout << cnt << "\n";
}