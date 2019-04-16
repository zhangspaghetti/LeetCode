class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> m;
        int result = 0;
        for(int j = 0, i = 0; j < s.length(); j++)
        {
            if(m.find(s.at(j)) != m.end())
            {
                i = m.find(s.at(j))->second > i ? m.find(s.at(j))->second : i;
            }
            result = j - i + 1 > result ? j - i + 1 : result;
            //记录当前字符下一个的下标
            m[s.at(j)] = j + 1;
        }
        
        return result;
    }
};