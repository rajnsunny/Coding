class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        unordered_map<char,int> ump;
        bool flag = true;
        for(auto s:words){
            unordered_map<char,int> ump1;
            for(auto e:s){
                ump1[e]++;
            }
            if(flag){
                ump = ump1;
                flag =false;
            }
            for(auto e:ump){
                ump[e.first] = min(ump[e.first],ump1[e.first]);
            }
        }

        

        vector<string> ans ;
        for(auto ele:ump){
            while(ele.second--){
               string s(1,ele.first);
               ans.push_back(s);
            }
        }

        return ans;
    }
};
