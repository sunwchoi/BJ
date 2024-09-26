#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int N, S;
vector<int> arr;

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> S;
    arr.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int sum = 0;
    int ans = INT_MAX;

    for (int start = 0, end = 1; end <= N; end++) {
        sum += arr[end - 1];
        if (sum >= S) {
            ans = min(ans, end - start);
            while ((sum - arr[start]) >= S) {
                sum -= arr[start];
                start++;
                ans = min(ans, end - start);
            }
        }
    }

    cout << (ans == INT_MAX ? 0 : ans) << "\n";

    return 0;
}