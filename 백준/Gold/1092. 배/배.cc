#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> crain;
int box[1000001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    crain = vector<int>(N);
    for (int i = 0; i < N; i++)
        cin >> crain[i];

    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int weight;
        cin >> weight;

        box[weight]++;
    }

    int minute = 1;
    int endCrain = 0;
    while (1)
    {
        for (int i = 0; i < N; i++)
        {
            if (crain[i] < 0)
                continue;

            while (crain[i] >= 0 && box[crain[i]] == 0)
                crain[i]--;

            if (crain[i] >= 0)
            {
                box[crain[i]]--;
                if (--M == 0)
                {
                    cout << minute << "\n";
                    exit(0);
                }
            }
            else
                endCrain++;
            
        }

        if (endCrain == N)
            break;
        minute++;
    }

    cout << "-1\n";
}