#include <vector>
#include <iostream>
#include <string.h>
using namespace std;


int cache[101][101];

int solution(vector<vector<int>>& field, int size, int x, int y){
    if(x >= size || y >= size)
        return 0;
    int& ret = cache[x][y];
    if(field[x][y] == 0)
        return ret = 1;

    //이게
    if(ret != -1)
        return ret;
    //메모이제이션 코드 (없어도 동작하지만 완전탐색이 되어버림)

    int jump = field[x][y];
    return ret = solution(field, size, x + jump, y) || solution(field, size, x, y + jump);
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        vector<vector<int>>field;
        int size;
        cin >> size;
        for(int j = 0; j < size; j++){
            memset(cache, -1, sizeof(cache));
            vector<int> temp;
            for(int k = 0; k < size; k++){
                int tmp;
                cin >> tmp;
                temp.push_back(tmp);
            }
            field.push_back(temp);
        }
        if(solution(field, size, 0, 0) == 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}