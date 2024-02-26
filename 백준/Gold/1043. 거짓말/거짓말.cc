#include <iostream>
#include <vector>

using namespace std;

int N, M;
bool    p[51];
bool    vi[51];
vector<int> nde[51];
vector<int> party[51];

void    dfs(int n)
{
    if (!(0 < n && n <= N) || vi[n])
        return ;
    vi[n] = true;
    p[n] = true;
    for (int i = 0; i < nde[n].size(); i++)
        dfs(nde[n][i]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    int tmp;
    cin >> tmp;
    for (int i = 0; i < tmp; i++)
    {
        int n;
        cin >> n;
        p[n] = true;
    }
    for (int i = 0; i < M; i++)
    {
        cin >> tmp;
        party[i] = vector<int>(tmp);
        for (int j = 0; j < tmp; j++)
            cin >> party[i][j];
        for (int j = 0; j < tmp; j++)
            for (int k = j + 1; k < tmp; k++)
            {
                nde[party[i][j]].push_back(party[i][k]);
                nde[party[i][k]].push_back(party[i][j]);
            }
    }
    for (int i = 1; i <= N; i++)
        if (p[i])
            dfs(i);
    int cnt = M;
    for (int i = 0; i < M; i++)
        for (int j = 0; j < party[i].size(); j++)
            if (p[party[i][j]] && cnt--)
                break ;
    cout << cnt << "\n";
}