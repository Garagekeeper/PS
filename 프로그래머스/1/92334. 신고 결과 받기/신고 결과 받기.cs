using System;
using System.Collections.Generic;

public class Solution {
    public int[] solution(string[] id_list, string[] report, int k) {
        // 중복 신고 제거
        HashSet<string> reportSet = new HashSet<string>(report);
        
        Dictionary<string, List<string>> reportLog = new Dictionary<string, List<string>>();
        Dictionary<string, int> User = new Dictionary<string, int>();
        List<int> ansList = new List<int>();

        // 신고 로그 기록
        foreach (var str in reportSet)
        {
            string[] temp = str.Split(' ');
            string from = temp[0];
            string to = temp[1];

            if (!reportLog.ContainsKey(to))
            {
                reportLog[to] = new List<string>();
            }
            reportLog[to].Add(from);
        }

        // 정지된 사람의 신고자에게 메일 수 카운트
        foreach (var user in id_list)
        {
            if (reportLog.ContainsKey(user) && reportLog[user].Count >= k)
            {
                foreach (var from in reportLog[user])
                {
                    if (User.ContainsKey(from))
                    {
                        User[from]++;
                    }
                    else
                    {
                        User[from] = 1;
                    }
                }
            }
        }

        // 결과 배열 만들기
        foreach (var user in id_list)
        {
            if (User.ContainsKey(user))
            {
                ansList.Add(User[user]);
            }
            else
            {
                ansList.Add(0);
            }
        }

        return ansList.ToArray();
    }
}