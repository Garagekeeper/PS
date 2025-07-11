class Solution {
public:
    string orderlyQueue(string s, int k) {
        if (k > 1)
        {
            sort(s.begin(), s.end());
        }   
        else
        {
            string smallest = s;
            for (int i=0; i<s.size(); i++)
            {
                string rotated = s.substr(i) + s.substr(0,i);
                if (rotated < smallest)
                    smallest = rotated;
            }
            return smallest;
        }
        return s;
    }
};