#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    //ab x bc 면 ac의 행렬 생성
    answer.resize(arr1.size(), vector<int>(arr2[0].size()));
    
    for (int i=0; i < arr1.size(); i++)
    {
        for (int j=0; j < arr2[0].size(); j++)
        {
            int res = 0;
            for (int k=0; k < arr1[0].size(); k++)
                res += arr1[i][k] * arr2[k][j];
            answer[i][j] = res;
        }
    }
    return answer;
}