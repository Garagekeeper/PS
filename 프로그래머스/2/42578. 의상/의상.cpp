#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

 unordered_map<string, int> clothesTypeMap;

int solution(vector<vector<string>> clothes) 
{
    int answer = 1;
    for (auto &clothe : clothes) 
    {
        string type = clothe[1];
        clothesTypeMap[type]++;
    }
    
    for (auto& m : clothesTypeMap)
    {
        answer *= (m.second + 1);
    }

    // 전부다 안 입는 경우 빼고
    return answer - 1;
}