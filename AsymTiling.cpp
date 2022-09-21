#include <iostream>
#include <string.h>
using namespace std;
int n;
int MOD = 1000000007 ;
int cache[101];
int solution2(int k){
    if (k <= 1)
        return 1;
    int& ret = cache[k];
    if (ret != -1)
        return ret;
    ret = (solution2(k-1) + solution2(k-2))% MOD;
    return ret ;
}

int solution(int m){
    if(m % 2 != 0)
        return (solution2(m) -solution2(m/2) + MOD) % MOD;
    int ret = solution2(m);
    ret = (ret - solution2(m/2) + MOD) % MOD;
    ret = (ret - solution2(m/2 -1) + MOD) % MOD;
    return ret;
}

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    for(int i =0 ; i < t; i++) {
        cin >> n;
        memset(cache, -1, sizeof(cache));
        cout << solution(n) << endl;
    }
}