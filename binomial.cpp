#include <iostream>
using namespace std;

int dp[400][1010] = {0,};

long long solution(int n, int r){
    if(r == 0 || n == r) return 1;
    if(dp[n][r] != 0) {
        return dp[n][r] % 1000000007;
    }
    return dp[n][r] = (solution(n-1, r-1) + solution(n-1, r)) % 1000000007;
}

//이항 계수란?

int main(){
    int n, r;
    cin >> n >> r;
    cout << solution(n, r);
}