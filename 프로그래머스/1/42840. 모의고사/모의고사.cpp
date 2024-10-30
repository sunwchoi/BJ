#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> one = {1, 2, 3, 4, 5};
    vector<int> two = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> three = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    vector<int> ret(3);
    vector<int> answer;
    
    for (int i = 0; i < answers.size(); i++)
    {
        if (answers[i] == one[i % one.size()])
            ret[0]++;
        if (answers[i] == two[i % two.size()])
            ret[1]++;
        if (answers[i] == three[i % three.size()])
            ret[2]++;
    }
    
    int mx = 0;
    for (int i = 0; i < 3; i++)
        mx = max(mx, ret[i]);
    for (int i = 0; i < 3; i++)
        if (mx == ret[i])
            answer.push_back(i + 1);
    return answer;
}