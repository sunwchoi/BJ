#include <iostream>
#include <map>

using namespace std;

multimap<int, int, greater<>> mp;

int N;
int answer[1000000];

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int input;

		cin >> input;

		auto it = mp.insert(make_pair(input, i));
		it++;
		for (; it != mp.end(); it = mp.erase(it))
		{
			answer[it->second] = input;
		}
	}

	for (int i = 0; i < N; i++)
		cout << (answer[i] ? answer[i] : -1)<< " ";
	cout << "\n";
}
