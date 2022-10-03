#include <iostream>
#include <string.h>
using namespace std;
const int MOD = 10*1000*1000;
int cache[101][101];
int solution(int k, int first){
    if(k == first)
        return 1;
    int&ret = cache[k][first];
    if(ret != -1) return ret;
    ret = 0;
    for(int second = 1; second <= k-first; ++second){
        int add = second + first - 1;
        add *= solution(k-first, second); // 첫 줄에 들어갈 도미노를 빼고, 두 번쨰 줄에 들어갈 도미노를 늘려나간다. second가 다음 재귀호출의 first가 되어야 한다.
        add %= MOD;
        ret += add;
        ret %= MOD;
    }
    return ret;
}

int main(){
    int n;
    int k;
    cin >> n;
    for(int i = 0; i < n; i++){
        memset(cache, -1, sizeof(cache));
        cin >> k;
        int result = 0;
        for(int j = 1; j <= k; j++) {
            result += solution(k, j);
            result %= MOD;
        }
        cout << result << endl;
    }
}