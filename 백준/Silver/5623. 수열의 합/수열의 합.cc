#include <iostream>
#include <vector>
using namespace std;

int N;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    vector<vector<int>> S(N, vector<int>(N));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cin >> S[i][j];
    }

    if (N == 2)
    {
        cout << 1 << " " << 1 << "\n";
        return 0;
    }

    int A1minusA2 = 0;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i == 0)
                A1minusA2 += S[i][j];
            else
                A1minusA2 -= S[i][j];
        }
    }
    A1minusA2 /= (N - 2);

    int A0 = (S[0][1] + A1minusA2) / 2;

    cout << A0 << " ";
    for (int i = 1; i < N; i++)
        cout << S[0][i] - A0 << " ";
    cout << "\n";
}