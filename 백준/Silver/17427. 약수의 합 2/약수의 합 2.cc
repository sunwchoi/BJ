#include <iostream>

using namespace std;

int N;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    unsigned long long answer = 0;
    cin >> N;
    for (int i = 1; i <= N; i++)
        answer += (N / i) * i;

    cout << answer << "\n";
}