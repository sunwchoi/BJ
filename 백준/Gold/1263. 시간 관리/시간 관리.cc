#include <iostream>
#include <algorithm>

using namespace std;

int N;
pair<int, int> tbl[1000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int S, T;
	
		cin >> T >> S;
		tbl[i] = { S, T };
	}

	sort(tbl, tbl + N);

	int et = tbl[0].first; //end time;
	int bt = et - tbl[0].second; //begin time;

	for (int i = 1; i < N; i++)
	{
		et += tbl[i].second;

		int gap = et - tbl[i].first;
		if (gap > 0)
		{
			bt -= gap;
			et -= gap;
		}

		if (bt < 0)
		{
			cout << "-1\n";
			return 0;
		}
	}

	cout << bt << "\n";
}