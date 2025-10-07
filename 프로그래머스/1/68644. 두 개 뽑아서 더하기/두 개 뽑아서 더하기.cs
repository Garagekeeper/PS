using System;
using System.Collections.Generic;
using System.Linq;

public class Solution {
    public int[] solution(int[] numbers) {
        int[] answer = new int[] {};
        List<int> list = new List<int>();
        for (int i=0; i<numbers.Length; i++)
        {
            for (int j=i+1; j<numbers.Length; j++)
            {
                list.Add(numbers[i] + numbers[j]);
            }
        }
        

        answer = list.Distinct().OrderBy(x => x).ToArray();
        return answer;
    }
}