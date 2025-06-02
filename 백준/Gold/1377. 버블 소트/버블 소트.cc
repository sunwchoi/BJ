#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> N;

    vector<pair<int, int>> input(N);

    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        input[i] = make_pair(tmp, i);
    }

    sort(input.begin(), input.end());

    int ans = 0;
    for (int i = 0; i < N; i++)
        ans = max(ans, input[i].second - i);

    cout << ans + 1;
}