#include <iostream>
#include <string.h>
using namespace std;

const int M = 1000000000 + 100;
int skip;
int bino[201][201];
int a, b;
void calcBino(){
    memset(bino, 0, sizeof(bino));
    for(int i = 0; i <= 200; i++){
        bino[i][0] = bino[i][i] = 1;
        for(int j = 1; j < i; j++){
            bino[i][j] = min(M, bino[i-1][j-1] + bino[i-1][j]);
        }
    }
}

void generate(int n, int m, string s){
    if (skip < 0) return;
    if(n == 0 && m == 0){
        if(skip == 0) cout << s << endl;
        skip--;
        return;
    }
    if(bino[n+m][n] <= skip){
        skip -= bino[n+m][n];
        return;
    }
    if (n > 0) generate(n-1, m, s + "-");
    if (m > 0) generate(n, m-1, s + "o");
}

int main(){
    int k;
    cin >> k;
    calcBino();
    for(int i = 0; i < k; i++){
        cin >> a >> b >> skip;
        skip--;
        generate(a, b, "");
    }
}