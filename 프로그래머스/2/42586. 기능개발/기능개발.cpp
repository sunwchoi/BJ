#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int start = 0;
    size_t N = progresses.size();

    while (start != N)
    {
        for (int i = start; i < N; i++)
        {
            progresses[i] += speeds[i];
        }
        int new_start = start;
        for (int i = start; i < N && progresses[i] >= 100; i++)
            new_start++;
        if (new_start != start)
        {
            answer.push_back(new_start - start);
            start = new_start;
        }           
    }
    return answer;
}