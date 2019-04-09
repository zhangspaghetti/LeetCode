class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> n;
        int result = 0;
        
        for(int i = 0; i < s.length(); i++)
        {
            n.clear();
            for(int j = i; j < s.length(); j++)
            {
                if(n.find(s.at(j)) == n.end())
                    n[s.at(j)] = j;
                else
                    break;
            }
            
            if(n.size() > result)
            {
                result = n.size();
            }
        }
        return result;
    }
};