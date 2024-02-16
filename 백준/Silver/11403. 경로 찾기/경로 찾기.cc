#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<int> > M;
vector<vector<bool> > R;
vector<bool> vi;

void    f(int org, int nde)
{
    vi[nde] = true;
    R[org][nde] = true;
    for (int i = 0; i < M[nde].size(); i++)
        if (!vi[M[nde][i]])
            f(org, M[nde][i]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    M = vector<vector<int> >(N);
    R = vector<vector<bool> >(N, vector<bool>(N));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            int tmp;
            cin >> tmp;
            if (tmp == 1)
                M[i].push_back(j);
        }
    
    for (int i = 0; i < N; i++)
    {
        vi = vector<bool>(N);
        for (int j = 0; j < M[i].size(); j++)
            f(i, M[i][j]);
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << (int)R[i][j] << " ";
        cout << "\n";
    }
}