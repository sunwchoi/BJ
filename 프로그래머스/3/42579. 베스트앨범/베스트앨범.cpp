#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    size_t N = genres.size();
    vector<int> answer;
    vector<tuple<int, int, int>> arr(N, tuple<int, int, int>());
    unordered_map<string, int> mp;
    
    for (int i = 0; i < N; i++)
    {
        mp[genres[i]] += plays[i];
    }
    
    for (int i = 0; i < N; i++)
    {
        arr[i] = make_tuple(mp[genres[i]], plays[i], N - i);
    }
    sort(arr.begin(), arr.end(), std::greater<tuple<int, int, int>>());
    
    int preGenres = -1;
    int cnt = 0;
    
    for (int i = 0; i < N; i++)
    {
        int curGenres = get<0>(arr[i]);
        if (curGenres == preGenres && cnt >= 2)
                continue;
        if (curGenres != preGenres)
            cnt = 0;
        
        answer.push_back(N - get<2>(arr[i]));
        preGenres = curGenres;
        cnt++;
    }
    
    return answer;
}