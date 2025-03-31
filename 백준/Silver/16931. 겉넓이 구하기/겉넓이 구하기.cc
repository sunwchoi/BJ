#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<int>> vec;
int dir[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    vec = vector<vector<int>>(N + 2, vector<int>(M + 2));
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
            cin >> vec[i][j];
    }

    int sum = 2 * N * M;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                int n = vec[i][j] - vec[i + dir[k][0]][j + dir[k][1]];

                sum += n > 0 ? n : 0;
            }
        }
    }

    cout << sum << "\n";
}