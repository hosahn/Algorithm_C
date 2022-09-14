#include <vector>
#include <iostream>
#include <string.h>
using namespace std;

vector<vector<int>> field;
int n, m;
int visited[501][501];
int mx[4] = {0 ,0, 1, -1};
int my[4] = {1, -1, 0, 0};

int solution(int x, int y){
    int& ret = visited[x][y];
    //도달한 경우 한 가지의 방법을 찾은 것이므로 1을 return
    if(x == n-1 && y == m-1){
        return 1;
    }
    //도달하지 않았어도 이미 도달한 타일에 도달한 경우는 타일의 경우의 수를 return
    if (visited[x][y] != -1) {
        return ret;
    }
    else {
        //아닌경우는 dfs로 완전탐색
        ret = 0;
        for (int i = 0; i < 4; i++) {
            int nx = x + mx[i];
            int ny = y + my[i];
            if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                if (field[nx][ny] < field[x][y]) {
                    ret = ret + solution(nx, ny);
                }
            }
        }
        return ret;
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(visited, -1, sizeof(visited));
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        vector<int> tmp;
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            tmp.push_back(x);
        }
        field.push_back(tmp);
    }
    int answer = solution(0, 0);
    cout << answer;
}