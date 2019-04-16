class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> hashset;
        int result = 0;
        for(int i = 0; i < s.length(); i++)
        {
            hashset.clear();
            for(int j = i; j < s.length(); j++)
            {
                if(hashset.find(s.at(j)) == hashset.end())
                {
                    hashset.insert(s.at(j));
                }
                else
                {
                    break;
                }
            }
            result = hashset.size() > result ? hashset.size() : result;
        }
        return result;
    }
};