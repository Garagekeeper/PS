#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    //a*b x b*c 면 ac의 행렬 생성
    /*
    행렬곱 예시
    {1 2} {1 2 3 } => {(1*1 + 2*4), (1*2 + 2*5), (1*3 + 2*6)} = {9 ,12, 15}
    {3 4} {4 5 6 }    {(3*1 + 4*4), (3*2 + 4*5), (3*3 + 4*6)}   {19,26, 33}
    */
    answer.resize(arr1.size(), vector<int>(arr2[0].size()));
    
    int leftMatrixRowCnt = arr1.size();
    // left col cnt == right row cnt
    int leftMatrixColCnt = arr1[0].size();
    int rightMatrixColCnt = arr2[0].size();
    
    for (int i=0; i < leftMatrixRowCnt; i++)
    {
        for (int j=0; j < rightMatrixColCnt; j++)
        {
            for (int k=0; k < leftMatrixColCnt; k++)
               answer[i][j] += arr1[i][k] * arr2[k][j];
        }
    }
    return answer;
}










    /*
    행렬곱 예시
    {1 2} {1 2 3 } => {(1*1 + 2*4), (1*2 + 2*5), (1*3 + 2*6)} = {9 ,12, 15}
    {3 4} {4 5 6 }    {(3*1 + 4*4), (3*2 + 4*5), (3*3 + 4*6)}   {19,26, 33}
    */