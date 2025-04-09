#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> table;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 

    cin >> N;
    table.resize(N);
    for (int i = 0; i < N; i++)
        cin >> table[i];

    int answer = 0;
    int sell = table[N - 1];
    for (int i = N - 2; i >= 0; i--)
    {
        if (table[i] > sell)
            sell = table[i];
        else
            answer += sell - table[i];
    }
    
    cout << answer << "\n";
}