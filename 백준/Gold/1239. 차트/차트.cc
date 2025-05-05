#include <iostream>
#include <vector>

using namespace std;

int N;
int input[8];
int arr[8];
int ans;

void f(int idx)
{
    if (idx == N)
    {
        int sum = 0;
        int curAns = 0;
        int start = 0;
        for (int i = 0; i < N; i++)
        {
            sum += arr[i];
            
            if (sum == 50)
                curAns++;

            if (sum >= 50)
                sum -= arr[start++];
        }

        ans = max(ans, curAns);
        return;
    }

    for (int i = 0; i < N; i++)
    {
        if (input[i] > 0)
        {
            arr[idx] = input[i];
            input[i] *= -1;
            f(idx + 1);
            input[i] *= -1;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> input[i];

    for (int i = 0; i < N; i++)
        f(0);

    cout << (ans == 0 ? 0 : ans - 1) << "\n";
}