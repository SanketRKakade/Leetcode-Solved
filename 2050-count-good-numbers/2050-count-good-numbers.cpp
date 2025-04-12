class Solution {
    const int MOD=1e9+7;
    long long powe(long long x,long long n,int mod){
        if(n==0){
            return 1;
        }
        long long half=powe(x,n/2,mod);
        return (n%2==0)? (half*half) % mod : ((half*half)%mod *x) % mod;
    }
public:
    int countGoodNumbers(long long n) {
        long long even=(n+1)/2;
        long long odd=n/2;
        long long ans=(powe(5,even,MOD)*powe(4,odd,MOD))%MOD;
        return ans;
    }
};