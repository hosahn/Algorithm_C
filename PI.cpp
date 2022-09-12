#include <string>
#include <iostream>
#include <string.h>
using namespace std;

int INF = 987654321;
int cache[20000];
string N;

//동일, 등차, 반복을 체크하는 단순 구현함수이다.
int classify(int a, int b) {
    string M = N.substr(a, b-a+1);
    if(M ==string(M.size(), M[0])) return 1;
    bool progressive = true;
    for(int i = 0; i < M.size()-1; i++){
        if(M[i+1] - M[i] != M[1] - M[0]){
            progressive = false;
        }
    }
    if(progressive && abs(M[1] - M[0]) == 1)
        return 2;
    bool alter = true;
    for(int  i = 0; i < M.size(); i++){
        if(M[i] != M[i%2])
            alter = false;
    }
    if(alter) return 4;
    if(progressive) return 5;
    else return 10;
}

//실제 메모이제이션을 실행하는 solution 함수이다.
int solution(int begin){
    if(begin == N.size()) return 0;
    int& ret = cache[begin];
    if(ret != -1) return ret;
    ret = INF;
    for(int i = 3; i <= 5; i++){
        if(begin + i <= N.size())
            ret = min(ret, solution(begin + i) + classify(begin, begin + i - 1));
    }
    return ret;
}

int main() {
    int n;
    cin >> n;
    for(int i =0; i < n; i++){
        cin >> N;
        memset(cache, -1, sizeof(cache));
        cout << solution(0) << endl;
    }
}