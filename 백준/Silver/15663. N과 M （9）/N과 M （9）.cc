#include <iostream>
#include <map>
#include <vector>

using namespace std;

int N, M;
vector<pair<int, int> > arr;
int ret[8];

void    f(int m)
{
    if (m == M)
    {
        for (int i = 0; i < M; i++)
            cout << ret[i] << " ";
        cout << "\n";
        return ;
    }
    for (int i = 0; i < arr.size(); i++)
    {
        if (!arr[i].second)
            continue ;
        arr[i].second--;
        ret[m] = arr[i].first;
        f(m + 1);
        arr[i].second++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    map<int, int> mp;
    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        mp[tmp]++;
    }
    for (auto it = mp.begin(); it != mp.end(); it++)
        arr.push_back(make_pair(it->first, it->second));
    f(0);
}