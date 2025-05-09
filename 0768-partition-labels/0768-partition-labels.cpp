class Solution {
public:

    vector<int> partitionLabels(string s) {

        int n=s.length();

        map<char,pair<int,int>> mp;

        for(int i=0 ; i<n ; i++){
            if(mp.find(s[i]) == mp.end()){
                mp[s[i]] = {i,i};
            }
            mp[s[i]].second = i;
        }

        // for(auto i:mp){
        //     cout<<i.first<<"->"<<i.second.first<<" "<<i.second.second<<endl;
        // }

        vector<pair<int,int>>v;
        for(auto &i:mp){
            v.push_back(i.second); 
        }
        sort(v.begin(),v.end());  
        vector<int>ans;
        int l=v[0].first;
        int h=v[0].second;
        for(int i=1;i<v.size();i++){
            if(v[i].first <= h) {
                h = max(h, v[i].second);
            } 
            else{
                ans.push_back(h - l + 1);
                l = v[i].first;
                h = v[i].second;
            }
        }
        ans.push_back(h - l + 1);
        return ans;
    }
};