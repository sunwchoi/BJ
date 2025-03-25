#include <iostream>

using namespace std;

int N;
int fire[10] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; i + j < 100; j++)
        {
            if (fire[i / 10] + fire[i % 10] + fire[j / 10] + fire[j % 10] + fire[(i + j) / 10] + fire[(i + j) % 10] == N - 4)
            {
                cout << i / 10 << i % 10 << "+" << j / 10 << j % 10 << "=" << (i + j) / 10 << (i + j) % 10 << "\n";
                return 0;
            }
        }
    }

    cout << "impossible\n";
}