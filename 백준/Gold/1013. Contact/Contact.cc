#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int T;
string t;

bool test1(int idx);

bool test2(int idx)
{
    if (idx == t.size())
        return true;

    if (idx + 2 <= t.size() 
        && (t[idx] == '0' && t[idx + 1] == '1'))
        return test1(idx + 2) || test2(idx + 2);

    return false;
}

bool test1(int idx)
{
    if (idx == t.size())
        return true;

    if (idx + 4 <= t.size()
        && (t[idx] == '1' && t[idx + 1] == '0' && t[idx + 2] == '0'))
    {
        int i = idx + 3;
        while (i < t.length() && t[i] == '0')
            i++;

        while (i < t.length() && t[i] == '1')
        {
            if (test1(i + 1) || test2(i + 1))
                return true;

            i++;
        }

    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> t;
        cout << ((test1(0) || test2(0)) ? "YES\n" : "NO\n");
    }
}