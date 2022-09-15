#include <iostream>
#include <string.h>
using namespace std;

int n;
int size;
int cache[100][100];
int triangle[100][100];
int cache2[100][100];

int path(int y, int x){
    if (y == size - 1)
        return triangle[y][x];
    int& ret = cache2[y][x];
    if (ret != -1)
        return ret;
    return ret = max(path(y + 1, x), path(y + 1, x + 1)) + triangle[y][x]; // 부분 경로의 최대치를 구한다.
}

int countPath(int y, int x){
    if (y == size-1) return 1;
    int& ret = cache[y][x];
    if(ret != -1) return ret;
    ret = 0;
    if(path(y+1, x+1) >= path(y+1, x)) ret += countPath(y+1, x+1);
    if(path(y+1, x+1) <= path(y+1, x)) ret += countPath(y+1, x);
    return ret;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        memset(cache, -1, sizeof(cache));
        memset(cache2, -1, sizeof(cache2));
        memset(triangle, 0, sizeof(triangle));
        cin >> size;
        for(int j = 0; j < size; j++){
            for(int k = 0; k <= j; k++){
                cin >> triangle[j][k];
            }
        }
        int result = countPath(0, 0);
        cout << result << endl;
    }
}