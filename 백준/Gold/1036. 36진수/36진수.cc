#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, K;

class Num36
{
public:
    Num36() {}
    Num36(const string& num) : _num(num) {}

    static char convertC2N(char c)
    {
        if (isalpha(c))
            c = c - 'A' + 10;
        else
            c -= '0';

        return c;
    }

    static char convertN2C(char c)
    {
        if (0 <= c && c < 10)
            c += '0';
        else
            c = c - 10 + 'A';

        return c;
    }

    Num36 operator+(const string& r)
    {
        string ret;

        int i = 0;
        size_t rSize = r.size();
        size_t lSize = _num.size();

        char u = 0;
        for (i = 0; i < rSize && i < lSize; i++)
        {
            char rc = convertC2N(r[rSize - 1 - i]);
            char lc =  convertC2N(_num[lSize - 1 - i]);
            char c = lc + rc + u;

            u = c / 36;
            c = c % 36;

            ret = convertN2C(c) + ret;
        }

        for (; i < rSize; i++)
        {
            char rc = convertC2N(r[rSize - 1 - i]);
            char c = rc + u;

            u = c / 36;
            c = c % 36;

            ret = convertN2C(c) + ret;
        }

        for (; i < lSize; i++)
        {
            char lc = convertC2N(_num[lSize - 1 - i]);
            char c = lc + u;

            u = c / 36;
            c = c % 36;

            ret = convertN2C(c) + ret;
        }

        if (u)
            ret = convertN2C(u) + ret;

        return ret;
    }

    string _num;
};

bool compare(string& l, string& r)
{
    if (l.size() != r.size())
        return l.size() > r.size();
    return l > r;
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    Num36 sum;
    vector<string> convertSum(36);

    for (int i = 0; i < N; i++)
    {
        string input;
        cin >> input;
        sum = sum + input;

        string tmp;
        for (int j = input.size() - 1; j >= 0; j--)
        {
            if (input[j] != 'Z')
            {
                char c = Num36::convertC2N(input[j]);
                convertSum[c] = (Num36(convertSum[c]) + (Num36::convertN2C(35 - c) + tmp))._num;
            }

            tmp = tmp + '0';
        }
    }


    sort(convertSum.begin(), convertSum.end(), compare);

    cin >> K;
    for (int i = 0; i < K; i++)
        sum = sum + convertSum[i];

    cout << sum._num << "\n";
}
