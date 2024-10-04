class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto x:nums){
            mp[x]++;
        }
        
        vector<pair<int,int>>vep;
        for(auto x:mp){
            int freq = x.second;
            while(freq--){
                vep.push_back({x.second,x.first});
            }
        }
        
        sort(vep.begin(),vep.end(),[](pair<int,int> &a, pair<int,int> &b){
           if(a.first == b.first) return a>b;
            return b>a;
        });
        
        vector<int>ans;
        for(auto x: vep){
            ans.push_back(x.second);
        }
        
        return ans;
    }
};
