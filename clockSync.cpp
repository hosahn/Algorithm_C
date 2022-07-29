#include <iostream>
#include <vector>
using namespace std;

int INF = 1000000;
int connection[10][16] = {
        {1, 1, 1, 0,},
        {0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0,},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1,},
        {1, 0, 0, 0, 1, 1, 1, 1, 0,},
        {0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0,},
        {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
        {0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1},
        {0, 1, 1, 1, 1, 1, 0,},
        {0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0,}
};

//문제의 스위치-시계 연결의 배열 표현 (순 노가다..)


void rotate(int n, vector<int>& clocks){
    for(int i =0; i < 16; i++){
        if(connection[n][i] == 1){
            clocks[i] += 3;
            if (clocks[i] == 15)
                clocks[i] = 3;
        }
    }
}

bool check(vector<int>& clocks){
    for(int i = 0; i < 16; i++){
        if (clocks[i] != 12){
            return false;
        }
    }
    return true;
}

int solution(vector<int>& clocks, int Switch){
    if(Switch == 10)  return check(clocks) ? 0 : INF;
    int result = INF;
    for(int i = 0; i < 4; i++){
        int tmp = solution(clocks, Switch + 1);
        if (tmp < INF) {
            result = min(result, i + tmp);
        }
        rotate(Switch, clocks);
    }
    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        vector<int> clocks(0);
        for(int j = 0; j < 16; j++){
            int tmp;
            cin >> tmp;
            clocks.push_back(tmp);
        }
        int result = solution(clocks, 0);
        if(result >= INF){
            cout << -1 << endl;
        }
        else {
            cout << result << endl;
        }
    }
}