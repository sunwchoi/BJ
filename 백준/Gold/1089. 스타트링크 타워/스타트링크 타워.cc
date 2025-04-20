#include <iostream>

using namespace std;

int N;
string input[5];

int arr[10][10];
int len[10];

string baseStr[5] = {
    "###...#.###.###.#.#.###.###.###.###.###",
    "#.#...#...#...#.#.#.#...#.....#.#.#.#.#",
    "#.#...#.###.###.###.###.###...#.###.###",
    "#.#...#.#.....#...#...#.#.#...#.#.#...#",
    "###...#.###.###...#.###.###...#.###.###",
};
int baseBit[10];

void convertToBit(const string* str, int idx, int& bit)
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = idx; j < idx + 3; j++)
        {
            if (str[i][j] == '#')
                bit |= (1 << (i * 3 + j - idx));
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 10; i++)
        convertToBit(baseStr, i * 4, baseBit[i]);

    cin >> N;
    for (int i = 0; i < 5; i++)
        cin >> input[i];

    for (int i = 0; i < N; i++)
    {
        int bit = 0;
        convertToBit(input, i * 4, bit);

        for (int j = 0; j < 10; j++)
        {
            if ((baseBit[j] | bit) == baseBit[j])
                arr[i][len[i]++] = j;
        }

        if (len[i] == 0)
        {
            cout << "-1\n";
            exit(0);
        }
    }

    int entireCase = 1;
    long long scale = 1;
    for (int i = 0; i < N; i++)
    {
        entireCase *= len[i];
        scale *= 10;
    }
    scale /= 10;

    long long entireSum = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < len[i]; j++)
            entireSum += arr[i][j] * scale * entireCase / len[i];
        scale /= 10;
    }

    cout << fixed;
    cout.precision(6);

    cout << (double)entireSum / entireCase << "\n";
}
