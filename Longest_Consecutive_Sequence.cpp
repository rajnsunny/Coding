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


