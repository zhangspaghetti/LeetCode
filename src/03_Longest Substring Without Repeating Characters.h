class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> hashset;
        int result = 0;
        int i = 0, j = 0;
        while(i < s.length() && j < s.length())
        {
            if(hashset.find(s.at(j)) == hashset.end())
            {
                hashset.insert(s.at(j++));
                result = hashset.size() > result ? hashset.size() : result;
            }
            else
            {
                hashset.erase(hashset.find(s.at(i++)));
            }
        }
        
        return result;
    }
};