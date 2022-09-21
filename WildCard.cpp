#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

int cache[101][101];

int solution(string target, string tmp, int a, int b, int tmpSize, int targetSize){
    int& ret = cache[a][b];
    if(ret != -1) return ret;
    //방문한 적이 있다면 바로 return
    while(a < targetSize && b < tmpSize && (target[a] == '?' || target[a] == tmp[b])) {
        ret = solution(target, tmp, a + 1, b + 1, tmpSize, targetSize);
        return ret;
    }
    // ? 와일드카드인경우
    if(a == targetSize){
        ret = (b == tmpSize);
        return ret;
    }
    // a끝에 도달한경우
    if(target[a] == '*'){
        if((b < tmpSize && solution(target, tmp, a, b+1, tmpSize, targetSize)) || (a < targetSize && (solution(target, tmp, a+1, b, tmpSize, targetSize)))){
            //b+1 = a는 계속 *로 머물고 b의 다음칸 대응 검사, a+1 = 이제 * 스킵하고 a의 다음 문자열 검사(사이즈 체크 필요)
            ret = 1;
            return ret;
        }
    }
    ret = 0;
    return ret;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string target;
        cin >> target;
        int k;
        cin >> k;
        vector<string> ans;
        for(int j = 0; j < k; j++){
            memset(cache, -1, sizeof(cache));
            string tmp;
            cin >> tmp;
            if(solution(target, tmp, 0, 0, tmp.size(), target.size()) == 1){
                ans.push_back(tmp);
            }
        }
        sort(ans.begin(), ans.end());
        for (auto e : ans) {
            cout << e << "\n";
        }
    }
}