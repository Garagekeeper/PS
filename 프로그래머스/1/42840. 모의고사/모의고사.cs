using System;
using System.Linq;
using System.Collections.Generic;

public class Solution {
    public int[] solution(int[] answers) {
        List<int> answer = new List<int>();
        int[] array1 = {1, 2, 3, 4, 5};
        int[] array2 = {2, 1, 2, 3, 2, 4, 2, 5};
        int[] array3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
        int[] correctCount = new int[3];
        
        for (int i=0; i<answers.Length; i++)
        {
            if (array1[i % array1.Length] == answers[i]) correctCount[0]++;
            if (array2[i % array2.Length] == answers[i]) correctCount[1]++;
            if (array3[i % array3.Length] == answers[i]) correctCount[2]++;
        }
        
        int max = correctCount.Max();
        
        for (int i=0; i<correctCount.Length; i++)
        {
            if (max == correctCount[i])
                answer.Add(i+1);
        }
        
        return answer.ToArray();
    }
}