#include <iostream>
#include <climits>
#include <map>

using namespace std;

int T, N;
map<string, int> mp;

int cnt(map<string, int>::iterator idx, map<string, int>::iterator jdx)
{
    int ret = 0;
    for (int i = 0; i < 4; i++)
        if ((idx->first)[i] != (jdx->first)[i])
            ret++;
    return ret;
}

int f3(map<string, int>::iterator it, map<string, int>::iterator jt)
{
    int ret = INT_MAX;
    for (auto i = mp.begin(); i != mp.end(); i++)
    {
        if (i == it || i == jt)
            continue;
        ret = min(cnt(it, jt) + cnt(jt, i) + cnt(i, it), ret);
    }
    return ret;
}

int f2(map<string, int>::iterator it)
{
    int ret = INT_MAX;
    for (auto i = mp.begin(); i != mp.end(); i++)
    {
        if (i == it)
            continue ;
        if (it->second + i->second >= 3)
            ret = min(cnt(it, i) * 2, ret);
        else
            ret = min(f3(it, i), ret);
    }
    return ret;
}

int f()
{
    int ret = INT_MAX;
    for (auto i = mp.begin(); i != mp.end(); i++)
    {
        if (i->second >= 3)
            return 0;
        ret = min(f2(i), ret);
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> N;
        mp.clear();
        for (int j = 0; j < N; j++)
        {
            string tmp;
            cin >> tmp;
            mp[tmp]++;
        }
        cout << f() << "\n";
    }
}