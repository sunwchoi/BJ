#include <iostream>
#include <queue>

using namespace std;

int N;
int input[10][4];
int output[10];

int GCD(int p, int q)
{
    int mod = p % q;
    if (mod == 0)
        return q;

    return GCD(q, mod);
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    queue<int> que;

    for (int i = 0; i < N - 1; i++)
    {
        cin >> input[i][0] >> input[i][1] >> input[i][2] >> input[i][3];

        que.push(i);
    }

    while (que.empty() == false)
    {
        int i = que.front();
        que.pop();

        int a = input[i][0];
        int b = input[i][1];
        int p = input[i][2];
        int q = input[i][3];
        
        if (i != 0 && output[a] == 0 && output[b] == 0)
        {
            que.push(i);
            continue;
        }

        int gcd = GCD(p, q);
        p /= gcd;
        q /= gcd;

        int j = 1, k = 1;
        while ((output[a] != 0 && output[a] * j != p * k) || (output[b] != 0 && output[b] * j != q * k))
        {
            if (output[a] != 0)
            {
                if (output[a] * j < p * k)
                    j++;
                else if (output[a] * j > p * k)
                    k++;
            }

            if (output[b] != 0)
            {
                if (output[b] * j < q * k)
                    j++;
                else if (output[b] * j > q * k)
                    k++;
            }
        }

        for (int i = 0; i < N; i++)
            output[i] *= j;
        
        output[a] = p * k;
        output[b] = q * k;
    }

    for (int i = 0; i < N; i++)
        cout << output[i] << " ";


}
