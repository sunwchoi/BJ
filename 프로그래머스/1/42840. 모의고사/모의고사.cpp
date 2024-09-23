#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> one = {1, 2, 3, 4, 5};
    vector<int> two = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> three = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    vector<int> ret(3);
    
    for (int i = 0; i < answers.size(); i++)
    {
        if (answers[i] == one[i % one.size()])
            ret[0]++;
        if (answers[i] == two[i % two.size()])
            ret[1]++;
        if (answers[i] == three[i % three.size()])
            ret[2]++;
    }
    
    
    if (ret[0] > ret[1] && ret[0] > ret[2])
        return {1};
    if (ret[1] > ret[2] && ret[1] > ret[0])
        return {2};
    if (ret[2] > ret[1] && ret[2] > ret[0])
        return {3};
    if (ret[0] == ret[1] && ret[0] > ret[2])
        return {1, 2};
    if (ret[0] == ret[2] && ret[0] > ret[1])
        return {1, 3};
    if (ret[1] == ret[2] && ret[1] > ret[0])
        return {2, 3};
    return {1, 2, 3};    
}