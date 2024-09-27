#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<string> table(9);
vector<vector<bool>> viCol(9, vector<bool>(9));
vector<vector<bool>> viRow(9, vector<bool>(9));
vector<vector<bool>> viSqu(9, vector<bool>(9));

void f(int col, int row) {
    int squ = (row / 3) * 3 + (col / 3);

    if (row == 9)
    {
        for (int i = 0 ; i < 9; i++)
            cout << table[i] << "\n";
        exit(0);
    }

    if (table[row][col] != '0') {
        f((col + 1) % 9, row + (col + 1) / 9);
        return ;
    }

    for (int i = 1; i <= 9; i++) {
        if (!viCol[col][i] && !viRow[row][i] && !viSqu[squ][i]) {
            viCol[col][i] = true;
            viRow[row][i] = true;
            viSqu[squ][i] = true;
            table[row][col] = '0' + i;
            f((col + 1) % 9, row + (col + 1) / 9);
            table[row][col] = '0';
            viCol[col][i] = false;
            viRow[row][i] = false;
            viSqu[squ][i] = false;
        }
    }
}
int main()
{
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 9; i++) {
        cin >> table[i];
        for (int j = 0; j < 9; j++) {
            int num = table[i][j] - '0';
            int col = j;
            int row = i;
            int squ = (row / 3) * 3 + (col / 3);
            viCol[col][num] = true;
            viRow[row][num] = true;
            viSqu[squ][num] = true;
        }
    }

    f(0, 0);



    return 0;
}