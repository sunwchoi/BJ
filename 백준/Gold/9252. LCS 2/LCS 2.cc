#include <iostream>

using namespace std;

string s1, s2;
int lcs[1001][1001];

void f(int i, int j)
{
    if (lcs[i][j] == 0)
        return;

    if (s1[i - 1] == s2[j - 1])
    {
        f(i - 1, j - 1);
        cout << s1[i - 1];
        return;
    }

    if (lcs[i - 1][j] > lcs[i][j - 1])
        f(i - 1, j);
    else
        f(i, j - 1);
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s1 >> s2;
    for (int i = 0; i < s1.length(); i++)
    {
        for (int j = 0; j < s2.length(); j++)
            lcs[i + 1][j + 1] = (s1[i] == s2[j]) ? lcs[i][j] + 1: max(lcs[i + 1][j], lcs[i][j + 1]);
    }

    cout << lcs[s1.length()][s2.length()] << "\n";
    f(s1.length(), s2.length());
    cout << "\n";
}