#include <iostream>
#include <vector>
using namespace std;

int N, E, K;
vector<long long> song;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> E;
    song.resize(N + 1);
    for (int i = 0; i < E; i++)
    {
        cin >> K;
        vector<int> people(K);
        bool isSeonYeongHere = false;
        long long songBit = 0;
        for (int j = 0; j < K; j++)
        {
            cin >> people[j];

            songBit |= song[people[j]];
            song[people[j]] |= (long long)1 << i;
            if (people[j] == 1)
                isSeonYeongHere = true;
        }

        if (isSeonYeongHere)
            continue;

        for (int j = 0; j < K; j++)
            song[people[j]] |= songBit;
    }

    for (int i = 1; i <= N; i++)
    {
        if ((song[i] & song[1]) == song[1])
            cout << i << "\n";
    }
}