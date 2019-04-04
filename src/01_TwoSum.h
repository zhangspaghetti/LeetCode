class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        for(int i = 0; i < nums.size(); i++)
        {
            if(m.find(target - nums.at(i)) == m.end())
            {
                m[nums.at(i)] = i;
            }
            else
            {
                return vector<int>{m.find(target - nums.at(i))->second, i};
            }
        }
        return vector<int>{};
    }
};