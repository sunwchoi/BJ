#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    size_t row = arr1.size();
    size_t col = arr2[0].size();
    size_t n = arr1[0].size();
    
    vector<vector<int>> answer(row, vector<int>(col));
    
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            for (int k = 0; k < n; k++)
            {
                answer[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
    
    
    
    return answer;
}