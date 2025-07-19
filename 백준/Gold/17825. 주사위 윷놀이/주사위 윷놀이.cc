#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <unordered_map>
#include <climits>

using namespace std;
vector<int> diceVec;
vector<int> pawnVec(4, 0);
//i번째 칸에서 갈 수 있는 칸
vector <int> nextMAP[33] = { 
	{1}, {2}, {3}, {4}, {5},				// 0 ~ 4
	{6, 21}, {7}, {8}, {9}, {10},			// 5 ~ 9
	{11,25}, {12}, {13}, {14}, {15},		// 10 ~ 14
	{16, 27}, {17}, {18}, {19}, {20},		// 15 ~ 19
	{32}, {22}, {23}, {24}, {30},			// 20 ~ 24
	{26}, {24}, {28}, {29}, {24},			// 25 ~ 29
	{31}, {20}, {32}						// 30 ~ 32
};

int scoreMAP[33]{
	0, 2, 4, 6, 8,				// 0~4
	10, 12, 14, 16, 18,			// 5~9
	20, 22, 24, 26, 28,			// 10 ~ 14
	30, 32, 34, 36, 38,			// 15 ~ 19
	40, 13, 16, 19, 25,			// 20 ~ 24
	22, 24, 28, 27, 26,			// 25 ~ 29
	30, 35, 0					// 30 ~ 32
};

int answer = 0;

void dfs(int sum, int depth)
{
    if (depth == 10)
    {
        answer = max(answer, sum);
        return;
    }

    for (int i=0; i<4; i++)
    {
        // 말 4개중에 하나 선택
        int iPawnCurPos = pawnVec[i];
        int nextCell;

        // 시작칸에 파란색 화살표가 있는지 확인
        if (nextMAP[iPawnCurPos].size() == 2)
        {
            nextCell = nextMAP[iPawnCurPos][1];
        }
        else
        {
            nextCell = nextMAP[iPawnCurPos][0];
        }

        // 주사위 눈 만큼 이동
        for (int j=1; j<diceVec[depth]; j++)
        {
            nextCell = nextMAP[nextCell][0];
        }


        // 이동할 칸에 이미 말이 있으면 끝
        bool found = false;
        for (int j=0; j<4; j++)
        {
            if (i==j) continue;
            if (pawnVec[j] == nextCell && nextCell!=32) found = true;
        }
        if (!found || nextCell == 32)
        {
            pawnVec[i] = nextCell;
            dfs(sum + scoreMAP[nextCell], depth+1);
            pawnVec[i] = iPawnCurPos;
        }
    }
}

int main()
{
    for (int i=0; i<10; i++)
    {
        int num;
        cin >> num;
        diceVec.push_back(num);
    }

    dfs(0,0);

    cout << answer << endl;
    return 0;
}