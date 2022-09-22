#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;

double cache[101][101]; int deg[51];
int field[101][101];
int n, nV, size, passed, prison, toFind, tmpN; //반복 회수, 1 반복당 탐색해봐야할 마을의 개수,필드 사이즈, 경과한 일수, 감옥의 위치, 확률을 찾아야 할 마을, 연결 여부를 위한 임시변수
double solution(int left, int loc, int target){
    if(left == passed) return loc == target ? 1.0 : 0.0;
    double& ret = cache[left][loc];
    if(ret > -0.5) return ret;
    ret = 0.0;
    for(int i = 0; i < size; i++)
        if(field[loc][i] == 1) ret += solution(left + 1, i, target) / deg[loc];
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> size >> passed >> prison;
        memset(field, 0, sizeof(field));
        memset(deg, 0, sizeof(deg));
        for(int j = 0; j < size; j++){
            for(int k = 0; k < size; k++){
                cin >> tmpN;
                field[j][k] = tmpN;
                if(tmpN == 1) deg[j]++;
            }
        }
        cin >> nV;
        for(int j = 0; j < nV; j++){
            memset(cache, -1, sizeof(cache));
            cin >> toFind;
            cout << fixed << setprecision(8) << solution(0, prison, toFind)<< " ";
        }
        cout << endl;
    }
}