#include <iostream>

using namespace std;

long long X, K;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> X >> K;
	
	long long ans = 0;
	for (int i = 1; K; i++)
	{
		long long bit = K & 1;
		K >>= 1;

		if (bit == 0)
			continue;

		for (int j = 0; ; )
		{
			if ((X & bit) == 0)
				j++;

			if (j == i)
				break;

			bit <<= 1;
		}

		ans |= bit;
	}

	cout << ans << "\n";
}