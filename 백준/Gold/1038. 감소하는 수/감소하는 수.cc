#include <iostream>
#include <vector>

using namespace std;

int N;
int n;

void f(int pre, unsigned long long number, int size)
{
    if (size == 0)
    {
        if (n++ == N)
        {
            cout << number << "\n";
            exit(0);
        }

        return;
    }

    for (int i = size - 1; i < pre; i++)
        f(i, number * 10 + i, size - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= 10; i++)
    {
        for (int j = i - 1; j < 10; j++)
            f(j, j, i - 1);
    }

    cout << "-1\n";
}