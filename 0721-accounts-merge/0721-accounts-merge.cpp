class Solution {
public:
    
    int parent[1000];
    int Size[1000];
    void make(int n){
        for(int i=0;i<n;i++){
            parent[i]=i;
            Size[i]=1;
        }
    }
    int find(int i){
        if(i==parent[i])return i;
        return parent[i]=find(parent[i]);
    }
    void Union(int a,int b){
        a=find(a);
        b=find(b);
        if(a==b)return;
        if(Size[b]>Size[a])swap(a,b);
        parent[b]=a;
        Size[a]+=Size[b];
    }


    vector<vector<string>> accountsMerge(vector<vector<string>>& ac) {
        unordered_map<string,int> mpp;
        make(ac.size());
        for(int i=0;i<ac.size();i++){
            for(int j=1;j<ac[i].size();j++){
                if(mpp.find(ac[i][j])!=mpp.end()){
                    Union(i,mpp[ac[i][j]]);
                }
                else{
                    mpp[ac[i][j]]=i;
                }
            }
        }
        vector<vector<string>> ans(ac.size());
        for(auto it:mpp){
            ans[find(it.second)].push_back(it.first);
        }
        vector<vector<string>> ans1;
        for(int i=0;i<ac.size();i++){
            if(ans[i].size()==0)continue;
            vector<string> v;
            v.push_back(ac[i][0]);
            for(auto it:ans[i])v.push_back(it);
            sort(++v.begin(),v.end());
            ans1.push_back(v);
        }
        
        return ans1;
    }
};