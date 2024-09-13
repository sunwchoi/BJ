#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int N;

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    vector<vector<int>> min_arr(2, vector<int>(3, 100001));
    vector<vector<int>> max_arr(2, vector<int>(3, -1));

    cin >> max_arr[0][0] >> max_arr[0][1] >> max_arr[0][2];
    min_arr[0] = max_arr[0];

    int x0, x1, x2;
    for (int i = 1; i < N; i++) {
        cin >> x0 >> x1 >> x2;

        min_arr[1][0] = x0 + min(min_arr[0][0], min_arr[0][1]);
        min_arr[1][1] = x1 + min(min(min_arr[0][0], min_arr[0][1]), min_arr[0][2]);
        min_arr[1][2] = x2 + min(min_arr[0][1], min_arr[0][2]);

        max_arr[1][0] = x0 + max(max_arr[0][0], max_arr[0][1]);
        max_arr[1][1] = x1 + max(max(max_arr[0][0], max_arr[0][1]), max_arr[0][2]);
        max_arr[1][2] = x2 + max(max_arr[0][1], max_arr[0][2]);

        min_arr[0] = min_arr[1];
        max_arr[0] = max_arr[1];
    }
    cout << max(max(max_arr[0][0], max_arr[0][1]), max_arr[0][2]) << " "
         << min(min(min_arr[0][0], min_arr[0][1]), min_arr[0][2]) << "\n";
    return 0;
}