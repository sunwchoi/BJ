#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int sum = 0;
    int mul = 0;
    
    sum = brown / 2 + 2;
    
    for (int i = 1; i < sum; i++)
    {
        if (brown + yellow == i * (sum - i))
            return {sum - i, i};
    }

    return answer;
}