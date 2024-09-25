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
    int ans = INT_MAX;

    vector<int> vec(N);
    for (int i = 0; i < N; i++) {
        cin >> vec[i];
    }
    int i = 0, j = N - 1;
    int ans_i = 0, ans_j = N - 1;
    while (i < j) {
        if (abs(vec[i] + vec[j]) < abs(vec[ans_i] + vec[ans_j])) {
            ans_i = i;
            ans_j = j;
        }

        if (vec[i] + vec[j] < 0)
            i++;
        else if (vec[i] + vec[j] > 0)
            j--;
        else
            break;
    }

    cout << vec[ans_i] << " " << vec[ans_j] << "\n";

    return 0;
}