#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<string> dic;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string input;
    cin >> input;
    while (input != "-")
    {
        dic.push_back(input);
        cin >> input;
    }

    constexpr int A = 'Z' - 'A' + 1;

    string puz;
    cin >> puz;
    while (puz != "#")
    {
        vector<int> puzAlpha(A);
        vector<int> ansAlpha(A);
        for (int i = 0; i < puz.size(); i++)
            puzAlpha[puz[i] - 'A']++;

        int n = dic.size();
        for (int i = 0; i < dic.size(); i++)
        {
            vector<int> dicAlpha(A);
            for (int j = 0; j < dic[i].size(); j++)
                dicAlpha[dic[i][j] - 'A']++;

            bool impossible = false;
            for (int i = 0; i < A; i++)
            {
                if (puzAlpha[i] < dicAlpha[i])
                {
                    impossible = true;
                    break;
                }
            }

            if (impossible)
            {
                n--;
                continue;
            }

            for (int i = 0; i < A; i++)
            {
                if (puzAlpha[i] != 0 && dicAlpha[i] == 0)
                    ansAlpha[i]++;
            }
        }

        string minStr, maxStr;
        int minNum = INT_MAX;
        int maxNum = 0;
        for (int i = 0; i < A; i++)
        {
            if (puzAlpha[i] == 0)
                continue;

            int tmp = n - ansAlpha[i];
            
            if (minNum > tmp)
            {
                minNum = tmp;
                minStr = i + 'A';
            }
            else if (minNum == tmp)
                minStr += i + 'A';

            if (maxNum < tmp)
            {
                maxNum = tmp;
                maxStr = i + 'A';
            }
            else if (maxNum == tmp)
                maxStr += i + 'A';
        }
        cout << minStr << " " << minNum << " " << maxStr << " " << maxNum << "\n";
        cin >> puz;
    }
}