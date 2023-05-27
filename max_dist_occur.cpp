#include <bits/stdc++.h>
using namespace std;



int main(){
  int n,m;
  cin>>n>>m;
  vector<int> nums(n);
  for(int i=0;i<n;i++) cin>>nums[i];
  unordered_map<int,int> ump;
  int mx = 0;
  for(int i=0;i<n;i++){
    if(ump.find(nums[i]) != ump.end() ){
       
        mx = max(i - ump[nums[i]],mx);
    }
    else{
      ump[nums[i]] = i;
    }
  }

  cout<<mx;


  
  
}
