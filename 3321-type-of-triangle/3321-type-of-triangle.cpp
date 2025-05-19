class Solution {
public:

    bool triangle(int a,int b, int c){
        if((a+b)>c && (b+c)>a && (a+c)>b) return true;
        return false;
    }

    string triangleType(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int a=nums[0],b=nums[1],c=nums[2];
        if(!triangle(a,b,c)) return "none";
        if(a==b && b==c) return "equilateral";
        else if((a==b && b!=c) || (a!=b && b==c)) return "isosceles";
        return "scalene";
    }
};