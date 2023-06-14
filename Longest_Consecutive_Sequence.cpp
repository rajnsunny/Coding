// TLE Solution.

class Solution {
public:
    int dfs(int x,unordered_map<int,int> ump){
        if(ump.find(x) == ump.end()) return 0;
        return 1+dfs(x+1,ump);
    }

    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int>ump;
        for(auto ele:nums) ump[ele]++;
        int mx = 0;
        for(auto ele:ump){
            mx = max(mx,dfs(ele.first,ump));
        }

        return mx;
    }
};


// Optimal One

int longestConsecutive(vector<int> &nums)
{
    int longest_cons_chain = 0;
    unordered_map<int, bool> present;
    unordered_map<int, bool> checked;
    for (auto a : nums)
    {
        present[a] = true;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        // !checked[nums[i]] means that number should not be part of a conseq sequence made already
        if (!checked[nums[i]] && !present[nums[i] - 1])
        {
            int current_chain = 0;
            int start = nums[i];
            while (present[start])
            {
                current_chain++;
                checked[start] = true;
                start++;
            }
            longest_cons_chain = max(longest_cons_chain, current_chain);
        }
    }
    return longest_cons_chain;
}


