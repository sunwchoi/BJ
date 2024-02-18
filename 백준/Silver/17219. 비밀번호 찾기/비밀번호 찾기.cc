#include <iostream>
#include <map>

using namespace std;

int N, M;
map<string, string>    mp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        string tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        mp.insert(make_pair(tmp1, tmp2));
    }
    for (int i = 0; i < M; i++)
    {
        string tmp;
        cin >> tmp;
        cout << mp[tmp] << "\n";
    }
}