#include <iostream>
#include <vector>

using namespace std;

int t;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<unsigned char> left(9);

    left[1] = 0b00000000;
    left[2] = 0b00101000;
    left[3] = 0b00101000;
    left[4] = 0b00000101;
    left[5] = 0b00000101;
    left[6] = 0b10000000;
    left[7] = 0b10000000;
    left[8] = 0b01010000;

    int testNum = 1;
    string testCase;
    cin >> testCase;
    while (testCase != "0")
    {
        bool valid = true;
        size_t len = testCase.length();

        if (len >= 3 && testCase[0] == '1' && testCase[len - 1] == '2')
        {
            int pre = 1;
            for (int i = 1; i < len; i++)
            {
                int cur = testCase[i] - '0';

                if (left[cur] != ((1 << (pre - 1)) | left[cur]))
                {
                    valid = false;
                    break;
                }
                pre = cur;
            }
        }
        else
            valid = false;

        cout << testNum << ". " << (valid ? "VALID\n" : "NOT\n");
        cin >> testCase;
        testNum++;
    }
}