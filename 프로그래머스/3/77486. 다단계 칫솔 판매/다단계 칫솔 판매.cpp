#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<string, string> refMap;
unordered_map<string, int> profitMap;

void setProfit(string member, int amount)
{
    int total = amount * 100;
    int distribution;
    
    do
    {
        if (total <= 9)
        {
            profitMap[member]+=total;
            break;
        }
        else 
        {
            distribution = total / 10;
            profitMap[member]+= total - distribution;
            
            member = refMap[member];
            total = distribution;
        }
    }while(member != "Center");
    
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> ans;
    
    
    // refMap 채우기
    for (int i=0; i<enroll.size(); ++i)
    {
        string ref;
        if (referral[i] == "-")
            ref="Center";
        else
            ref = referral[i];
        
        refMap[enroll[i]]= ref;
    }
    
    // 판매금액을 통한 이익금 처리
    for (int i = 0; i < amount.size(); i++)
    {
        setProfit(seller[i], amount[i]);
    }
    
    for (auto& e : enroll)
    {
        ans.push_back(profitMap[e]);
    }
    
    return ans;
}