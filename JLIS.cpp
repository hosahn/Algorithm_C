#include <vector>
#include <iostream>
#include <limits>
#include <string.h>
using namespace std;

const long long NEGINF = numeric_limits<long long>::min();
int cache[101][101];

int solution(vector<int>& aField, vector<int>& bField, int aSize, int bSize, int X, int Y){
    int& ret = cache[X+1][Y+1];
    if(ret != -1) return ret;
    ret = 2;
    long long A = (X == -1 ? NEGINF : aField[X]);
    long long B = (Y == -1 ? NEGINF : bField[Y]);
    long long maxElement = max(A,B);
    for(int nextA = X + 1; nextA < aSize; nextA++){
        if(maxElement < aField[nextA])
            ret = max(ret, solution(aField, bField, aSize, bSize, nextA, Y) + 1);
    }
    for(int nextB = Y + 1; nextB < bSize; nextB++){
        if(maxElement < bField[nextB])
            ret = max(ret, solution(aField, bField, aSize, bSize, X, nextB) + 1);
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        memset(cache, -1, sizeof(cache));
        int aSize, bSize;
        cin >> aSize >> bSize;
        vector<int> aField, bField;
        for(int j = 0; j < aSize; j++){
            int tmp;
            cin >> tmp;
            aField.push_back(tmp);
        }
        for(int j = 0; j < bSize; j++){
            int tmp;
            cin >> tmp;
            bField.push_back(tmp);
        }
        cout << solution(aField, bField, aSize, bSize, -1, -1) -2 << endl;
    }
}