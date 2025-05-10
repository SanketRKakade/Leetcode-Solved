class Solution {
public:
    long long minSum(vector<int >& nums1, vector<int >& nums2) {
        long long  z1=0;
        long long  z2=0;
        for(long long  i=0;i<nums1.size();i++){
            if(nums1[i]==0)z1++;
        }
        for(long long i=0;i<nums2.size();i++){
            if(nums2[i]==0)z2++;
        }
        long long  s1=accumulate(nums1.begin(),nums1.end(),0LL);
        long long  s2=accumulate(nums2.begin(),nums2.end(),0LL);
        
        if(z1==0&&s2+z2>s1||z2==0&&s1+z1>s2){
            return -1;
        }
        
        if(s1+z1>s2+z2){
            return s1+z1;
        }
        else if(s1==s2){
            if(z1>z2)return s1+z1;
            return s2+z2;
        }
        return s2+z2;
    }
};