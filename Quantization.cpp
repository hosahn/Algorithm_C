#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
int a, b;
vector<int> field;
int cache[101][11];

int minError(int lo, int hi){
    int minimum = 99999999;
    int lowest = field[lo];
    int highest = field[hi];
    if(lowest == highest) return 0;
    for(int i = lowest; i <= highest; i++){
        int tmpResult = 0;
        for(int j = lo; j <= hi; j++)
            tmpResult += pow(field[j]-i, 2);
        if(tmpResult < minimum)
            minimum = tmpResult;
    }
    return minimum;
}

//완전탐색

int minError2(int lo, int hi){
    int total = 0;
    for(int i = lo; i <= hi; i++) {
        total += field[i];
    }
    int avg = int(0.5 + (double)total / (hi-lo + 1));
    int result = 0;
    for(int i = lo; i <= hi; i++){
        result += pow(field[i]-avg, 2);
    }
    return result;
}

//평균 이용

int solution(int cur, int group){
    if(cur == a) return 0;
    //이미 양자화가 다 끝났을때
    if(group == 0) return 99999999;
    //group가 끝났는데 숫자가 남았을 때 => 불가능한 경우
    int& ret = cache[cur][group];
    if(ret != -1) return ret;
    ret = 99999999;
    for(int i = 1; i + cur <= a; i++){
        //첫번쨰 그룹의 minError와 다음 그룹의 (재귀) minError들을 더해본다.
        ret = min(ret, minError2(cur, cur + i - 1) + solution(cur + i, group -1));
    }
    return ret;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        for(int j = 0; j < a; j++){
            memset(cache, -1, sizeof(cache));
            int k;
            cin >> k;
            field.push_back(k);
        }
        sort(field.begin(), field.end());
        cout<<solution(0, b) << endl;
        field.clear(); //벡터 초기화
    }
}