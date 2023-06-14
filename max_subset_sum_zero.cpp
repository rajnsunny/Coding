class Solution{
    public:

    int max_distance_equal_element(int n,vector<int>pre){
    unordered_map<int,int>ump;
    int mx(0);
    for(int i=0;i<n;i++){
        if(ump.find(pre[i]) != ump.end()){
            mx = max(mx,i - ump[pre[i]]);   // P(l-1) = P(r)
        }
        else ump[pre[i]] = i;
        if(!pre[i]) mx = max(mx,i+1);   //check for the prefux sum = zero
    }

    return mx;
}

    
    int maxLen(vector<int>&nums, int n)
    {   
        vector<int> pre(n);
   
    pre[0] = nums[0];
   
    for(int i=1;i<n;i++) pre[i] = pre[i-1] + nums[i];
    
    return max_distance_equal_element(n,pre);
    }
};
