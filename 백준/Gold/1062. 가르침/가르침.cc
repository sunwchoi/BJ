#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<pair<int, int>> mp;

void f(char c, int k, int bit)
{
    if ((bit | (1 << (c - 'a'))) == bit)
    {
        f(c + 1, k, bit);
        return;
    }

    if (k == K)
    {
        mp.push_back({bit, 0});
        return;
    }

    if (c > 'z')
        return;

    f(c + 1, k + 1, bit | (1 << (c - 'a')));
    f(c + 1, k, bit);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    int bit = 0;
    bit |= (1 << ('a' - 'a'));
    bit |= (1 << ('n' - 'a'));
    bit |= (1 << ('t' - 'a'));
    bit |= (1 << ('i' - 'a'));
    bit |= (1 << ('c' - 'a'));
    f('a', 5, bit);

    string input;
    for (int i = 0; i < N; i++)
    {
        cin >> input;
        
        int st = 0;
        for (int j = 0; j < input.size(); j++)
            st |= (1 << (input[j] - 'a'));

        for (int j = 0; j < mp.size(); j++)
        {
            if ((mp[j].first & st) == st)
                mp[j].second++;
        }
    }

    int answer = 0;
    for (int i = 0; i < mp.size(); i++)
        answer = max(answer, mp[i].second);

    cout << answer;
}
