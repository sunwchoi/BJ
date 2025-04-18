#include <iostream>
#include <unordered_map>

using namespace std;

int N, M, K;
long long arr[50];
unordered_map<long long, int> table;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    string input;
    for (int i = 0; i < N; i++)
    {
        cin >> input;
        for (int j = 0; j < M; j++)
            arr[i] = (arr[i] << 1) | (input[j] - '0');
    }
    
    cin >> K;

    for (int i = 0; i < N; i++)
    {
        long long zero = M - __builtin_popcountll(arr[i]);
        if (zero <= K && K % 2 == zero % 2)
            table[arr[i]]++;
    }

    int answer = 0;
    for (auto it = table.begin(); it != table.end(); it++)
        answer = max(answer, it->second);

    cout << answer << "\n";
}