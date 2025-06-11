#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int L, C;
string set;
bool isMo[26];

void f(int idx, string& s, int ja, int mo)
{
    s += set[idx];
    if (isMo[set[idx] - 'a'])
        mo++;
    else
        ja++;

	if (s.size() == L)
	{
        if (mo >= 1 && ja >= 2)
            cout << s << "\n";
        s.pop_back();
        return;
	}

    for (int i = idx + 1; i < C; i++)
        f(i, s, ja, mo);

    if (isMo[set[idx] - 'a'])
        mo--;
    else
        ja--;
    s.pop_back();
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> L >> C;
	for (int i = 0; i < C; i++)
	{
        char c;
        cin >> c;

        set += c;
	}

    isMo['a' - 'a'] = true;
    isMo['e' - 'a'] = true;
    isMo['i' - 'a'] = true;
    isMo['o' - 'a'] = true;
    isMo['u' - 'a'] = true;
    sort(set.begin(), set.end());

    string s;
    for (int i = 0; i < C; i++)
		f(i, s, 0, 0);
}