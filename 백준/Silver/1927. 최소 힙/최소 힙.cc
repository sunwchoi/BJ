#include <iostream>
#include <set>

using namespace std;

int N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	multiset<int>	st;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int	tmp;
		cin >> tmp;
		if (tmp == 0)
		{
			if (st.empty())
				cout << "0\n";
			else
			{
				int les = *(st.begin());
				cout << les << "\n";
				st.erase(st.begin());
			}
		}
		else
			st.insert(tmp);
	}
}