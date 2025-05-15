#include <iostream>
#include <map>

using namespace std;

int N;
string text;
map<int, string> history;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	
	int	t, T;
	char c;
	char cmd[5];
	history[-1] = "";
	history[0] = "";
	for (int i = 0; i < N; i++)
	{
		cin >> cmd;
		if (cmd[0] == 't')
		{
			cin >> c >> T;
			
			history[T] = (text += c);
		}
		else
		{
			cin >> t >> T;

			auto it = history.lower_bound(T - t);
			history[T] = (text = (--it)->second);
		}
	}

	cout << text;
}