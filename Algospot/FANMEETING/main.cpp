#include <iostream>
#include <bitset>

using namespace std;

int C, answer;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> C;
	string mStr, fStr;

	for (int i = 0; i < C; i++)
	{
		cin >> mStr>> fStr;
		answer = 0;
		const size_t mLen = mStr.length();
		const size_t fLen = fStr.length();

		if (mLen > fLen)
		{
			cout << answer << "\n";
		}
		else
		{
			bitset<200000> mBit;
			bitset<200000> fBit;
			for (int j = 0; j < mLen; j++)
			{
				mBit <<= 1;
				if (mStr[j] == 'M')
					mBit |= 1;

				fBit <<= 1;
				if (fStr[j] == 'M')
					fBit |= 1;
			}
			if ((fBit&mBit) == 0)
				answer++;
			for (int j = mLen; j < fLen; j++)
			{
				fBit <<= 1;
				if (fStr[j] == 'M')
					fBit |= 1;
				if ((fBit&mBit) == 0)
					answer++;
			}
			cout << answer << "\n";
		}
	}
}
