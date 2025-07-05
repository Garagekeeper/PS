#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.second == b.second)
        return a.first < b.first;
    else
        return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    // 장르의 총 재생횟수를 담는 맵
    unordered_map<string, int> totalCount;
    // 위 변수를 정렬하기 위한 벡터
    vector<pair<string, int>> totalCountVec;
    // 각 장르의 노래목록을 저장하는 맵
    unordered_map<string, vector<pair<int, int>>> songListInGenres;
    
    // 장르별 총 재생횟수
    // 장르별 노래 목록 저장
    for (int i = 0 ; i < genres.size(); i++)
    {
        totalCount[genres[i]] += plays[i];
        songListInGenres[genres[i]].push_back(make_pair(i, plays[i]));
    }
    
    // 정렬을 위해 벡터에 삽입
    totalCountVec = vector<pair<string,int>>(totalCount.begin(), totalCount.end());
    
    // 정렬
    sort(totalCountVec.begin(), totalCountVec.end(), [](pair<string, int> a, pair<string, int> b){
        return a.second > b.second;
    });
    
    // 많이 재생된 장르부터 순회
    for (auto it = totalCountVec.begin(); it != totalCountVec.end() ; ++it)
    {
        // 장르 추출 후 곡 리스트 정렬 (재생수기준 내림, 동일하면 낮은 고유번호 순)
        string genres = it->first;
        sort(songListInGenres[genres].begin(), songListInGenres[genres].end() ,cmp);
        // 2개씩 뽑음
        for (int i=0; i<2; i++)
        {
            // 1개 밖에 없는 경우 체크해서 종료
            if (i == songListInGenres[genres].size()) break;
            // 정답 배열에 곡의 고유번호를 넣음
            answer.push_back(songListInGenres[genres][i].first);
        }
    }
    
    return answer;
}