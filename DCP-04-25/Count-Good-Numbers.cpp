class Solution {
public:
    const long long m=1e9+7;
    long long solve(long long x,long long n){
        if(n==0)return 1;
        long long half=solve(x,n/2);
        if(n%2==0)return (half*half)%m;
        else return (x*half*half)%m;
    }
    int countGoodNumbers(long long n) {
        long long even=(n+1)/2;
        long long odd=n/2;
        long long even_pow=solve(5,even)%m;
        long long odd_pow=solve(4,odd)%m;
        return (even_pow*odd_pow)%m;
    }
};