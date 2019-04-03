class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        std::map<int, int> m;
        for(int i = 0; i < nums.size(); i++)
        {
            if(m.find(target - nums.at(i)) == m.end())
            {
                m[nums.at(i)] = i;
            }
            else
            {
                result.push_back(m.find(target - nums.at(i))->second);
                result.push_back(i);
                return result;
            }
        }
        return result;
    }
};