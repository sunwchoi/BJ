#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for (int i = 0; i < commands.size(); i++)
    {
        vector<int> new_arr;
        for (int j = commands[i][0] - 1; j < commands[i][1]; j++)
            new_arr.push_back(array[j]);
        sort(new_arr.begin(), new_arr.end());
        answer.push_back(new_arr[commands[i][2] - 1]);
    }
    return answer;
}