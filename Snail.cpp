#include <iostream>
using namespace std;

double memo[1001][2001];
int n, m;

double solution(int days, int clime){
    if (days == m) return clime >= n ? 1 : 0;
    double& ret = memo[days][clime];
    if (ret != -1) return ret;
    return ret = (0.25 * solution(days + 1, clime + 1)) + (0.75 * solution(days + 1, clime + 2));
}

int main(){
    cout.precision(10);
    int k;
    cin >> k;
    for(int i = 0; i < k; i++){
        for (int i = 0; i < 1001; i++)
            for (int j = 0; j < 2001; j++)
                memo[i][j] = -1;
        cin >> n >> m;
        cout << solution(0, 0)  << endl;
    }
    return 0;
}