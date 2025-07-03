#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<string, int> sellmoney; // 멤버 별 판매 금액
unordered_map<string, string> ref; // 멤버 별 추천인

void func(string name, int money) {
    if(name == "-") return; // "-" 추천인이 없을 경우 종료
    int tmp = money * 0.1; // 추천인에게 들어갈 판매 금액의 10%
    sellmoney[name] += (money - tmp); // 판매 금액의 90%만 수익으로 더해줌
    if(money >= 1){ // 추천인에게 줄 판매 금액의 10%가 1 이상일 때만 수행
        func(ref[name], tmp);
    }
    return;
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> ans;
    for(int i=0; i<enroll.size(); i++){
        ref[enroll[i]] = referral[i]; // 추천인 정보 저장
    }
    
    for(int i=0; i<seller.size(); i++){
        func(seller[i], amount[i] * 100); // 판매자들의 판매 금액과 추천인에게 들어갈 금액 업데이트
    }
    
    for(int i=0; i<enroll.size(); i++) {
        ans.push_back(sellmoney[enroll[i]]);
    }
    return ans;
}