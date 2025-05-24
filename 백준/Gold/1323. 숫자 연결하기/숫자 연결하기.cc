#include <iostream>
#include <vector>

using namespace std;

long long N, K;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	vector<bool> vi(K);

	long long d;
	for (d = 1; d <= N; d *= 10) 
		;

	long long preMod = N % K;
	long long sumMod = preMod;

	int ans = 1;
	while (vi[sumMod] == false && sumMod != 0)
	{
		vi[sumMod] = true;
		preMod = (preMod * d) % K;
		sumMod = (sumMod + preMod) % K;
		ans++;
	}

	cout << (sumMod == 0 ? ans : -1) << "\n";
}