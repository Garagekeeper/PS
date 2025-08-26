#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<string> solution(vector<string> s) 
{
    vector<string> answer;
    for (int i=0; i<s.size(); i++)
    {
        string str;
        int cnt=0;
        for (auto& c : s[i])
        {
            str.push_back(c);
            // 스태의 크기가 3보다 크고 가장 최근에 110이 삽입된 상태라면
            if (str.size() >= 3 && str.substr(str.size()-3) == "110")
            {
                // 110개수를 늘리고 110 지우기
                cnt++;
                for (int i=0; i<3; i++)
                    str.pop_back();
            }
            
        }
        
        // 가장 마지막 0의 뒤 (연속된 1의 앞)
        int index = 0;
        for(int i=str.size()-1; i>=0; i--)
        {
            if (str[i] == '0')
            {
                index = i+1;
                break;
            }
        }

        // 해당 위치에 110들 삽입
        while(cnt)
        {
            str.insert(index, "110");
            cnt--;
        }
        answer.push_back(str);
    }
    return answer;
}


