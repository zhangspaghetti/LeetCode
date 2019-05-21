class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() == 0)
		{
			return "";
		}
        string rs;
        for(string::reverse_iterator rit = s.rbegin(); rit != s.rend(); rit++)
        {
            rs.push_back(*rit);
        }
        
        int len = s.length();
        vector<vector<int> > L(len, vector<int>(len));
        int z = 0;
        vector<string> result;
        for(int i = 0; i < len; i++)
        {
            for(int j = 0; j < len; j++)
            {
                if(s[i] == rs[j])
                {
                    //Update L
                    if(i == 0 || j == 0)
                    {
                        L[i][j] = 1;
                    }
                    else
                    {
                        L[i][j] = L[i - 1][j - 1] + 1;
                    }
                    //Update longest common substring size
                    if(L[i][j] > z && i + j == len + L[i][j] - 2) //len - 1 - j == i + 1 - L[i][j] indicates the same substring
                    {
                        z = L[i][j];
                        result.clear();
                        result.push_back(s.substr(i + 1 - z, z));
                    }
                    else if(L[i][j] == z && i + j == len + L[i][j] - 2)
                    {
                        result.push_back(s.substr(i + 1 - z, z));
                    }
                }
                else
                {
                    L[i][j] = 0;
                }
            }
        }
        return result.at(0);
    }
};