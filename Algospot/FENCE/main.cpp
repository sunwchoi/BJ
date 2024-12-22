#include <iostream>
#include <map>

using namespace std;

struct index {
	int RealIdx;
	int StartIdx;
};

int C, N, h, answer;
map<int, struct index> mp;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> C;
	for (int i = 0; i < C; i++)
	{
		cin >> N;
		answer = 0;
		for (int j = 0; j < N; j++)
		{
			cin >> h;

			if (mp.find(h) == mp.end())
			{
				auto ite = mp.lower_bound(h);
				int startIdx = -1;
				for (auto it = mp.begin(); it != ite; it++)
				{
					startIdx = max(it->second.RealIdx, startIdx);
				}
				mp[h].StartIdx = startIdx + 1;
			}
			mp[h].RealIdx = j;

			for (auto it = mp.upper_bound(h); it != mp.end();)
			{
				answer = max((j - it->second.StartIdx) * it->first, answer);
				it = mp.erase(it);
			}
		}
		for (auto it = mp.begin(); it != mp.end();)
		{
			answer = max((N - it->second.StartIdx) * it->first, answer);
			it = mp.erase(it);
		}
		cout << answer << "\n";
	}

}
