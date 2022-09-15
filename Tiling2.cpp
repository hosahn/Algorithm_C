#include <iostream>
#include <string.h>
using namespace std;
const int MOD = 1000000007;
long long cache[101];
int solution(int k){
    if (k == 1 || k == 0)
        return 1;
    if (k == 2)
        return 2;
    long long& ret = cache[k];
    if (ret != -1)
        return ret % MOD;
    ret = solution(k-1) + solution(k-2);
    return ret % MOD;
}
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        memset(cache, -1, sizeof(cache));
        int k;
        cin >> k;
        cout << solution(k) << endl;
    }
}

