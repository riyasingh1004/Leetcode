// Time Complexity O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int n = nums.size();
        unordered_map<int,int> mp;
        vector<int> res;
        
        for (int i = 0; i < n; i++) {
            
            if (mp.find(target-nums[i]) != mp.end()) {
                
                res.push_back(mp[target-nums[i]]);
                res.push_back(i);
                return res;
            }
            
            mp[nums[i]] = i;
        }
        
        return res;
    }
};