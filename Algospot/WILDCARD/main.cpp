#include <iostream>
#include <set>
#include <vector>

using namespace std;

int C, N;
string wildcard, filename;
set<string> answer;
vector<vector<bool> > vi;


bool match(int wIdx, int fIdx)
{
	if (vi[wIdx][fIdx] == true)
		return false;
	vi[wIdx][fIdx] = true;
	while (wIdx < wildcard.length() && fIdx < filename.length()
			&& (wildcard[wIdx] == filename[fIdx] || wildcard[wIdx] == '?'))
	{
		wIdx++; fIdx++;
	}

	if (wIdx == wildcard.length() && fIdx == filename.length())
		return true;
	if (wildcard[wIdx] == '*')
	{
		for (int i = fIdx; i <= filename.length(); i++)
		{
			if (match(wIdx + 1, i))
				return true;
		}
	}
	return false ;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> C;
	for (int i = 0; i < C; i++)
	{
		cin >> wildcard;
		cin >> N;
		answer.erase(answer.begin(), answer.end());
		for (int j = 0; j < N; j++)
		{
			cin >> filename;
			vi = vector<vector<bool> >(wildcard.length() + 1, vector<bool>(filename.length() + 1));
			if (match(0, 0))
				answer.insert(filename);
		}
		for (auto it = answer.begin(); it != answer.end(); it++)
			cout << *it << "\n";
	}

}
