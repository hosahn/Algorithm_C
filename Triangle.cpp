#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

const int MAX = 100;
int triangle[MAX][MAX];
int n;
int cache[MAX][MAX];

int path(int y, int x){
    if (y == n - 1)
        return triangle[y][x];
    int& ret = cache[y][x];
    if (ret != -1)
        return ret;
    return ret = max(path(y + 1, x), path(y + 1, x + 1)) + triangle[y][x]; // 부분 경로의 최대치를 구한다.
}

int main(){
    int C;
    cin >> C;
    while (C--){
        cin >> n;
        memset(cache, -1, sizeof(cache));
        for(int i=0; i< n; ++i)
            for (int j = 0; j <= i; ++j){
                cin >> triangle[i][j];
            }
        int result = path(0, 0);
        cout << result << endl;
    }
    return 0;
}

