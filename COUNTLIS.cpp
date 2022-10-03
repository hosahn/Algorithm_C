#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 2000000000 + 1;
int n, s, k, tmp;
int cacheLen[501], cacheCnt[501];

vector<int>field;

int lis(int start, vector<int>& field) {
    int &ret = cacheLen[start + 1];
    if (ret != -1)
        return ret;
    ret = 1;
    for (int next = start + 1; next < s; next++) {
        if ((start == -1 || field[start] < field[next])) {
            ret = max(ret, lis(next, field) + 1);
        }
    }
    return ret;
}

int Count(int start, vector<int>& field){
    if(lis(start,field) == 1) return 1;
    int& ret = cacheCnt[start+1];
    if(ret != -1) return ret;
    ret = 0;
    for(int next = start + 1; next < s; next++){
     if((start== -1 || field[start] < field[next]) && lis(start, field) == lis(next, field) + 1){
         ret = min<long long>(MAX, (long long)ret + Count(next, field));
     }
    }
    return ret;
}

void reconstruct(vector<int>& result, int skip, int start, vector<int>& field){
    if(start != -1) result.push_back(field[start]);
    vector<pair<int, int>> followers;
    for(int next = start + 1; next < s; next++){
        if((start == -1 || field[start] < field[next]) && lis(start, field) == lis(next, field) + 1){
            followers.push_back(make_pair(field[next], next));
        }
    }
    sort(followers.begin(), followers.end());
    for(int i = 0; i < followers.size(); i++){
        int idx = followers[i].second;
        int cnt = Count(idx, field);
        if(cnt <= skip)
            skip -=cnt;
        else{
            reconstruct(result, skip, idx, field);
            break;
        }
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        memset(cacheCnt, -1, sizeof(cacheCnt));
        memset(cacheLen, -1, sizeof (cacheLen));
        field.clear();
        cin >> s >> k;
        for(int j = 0; j < s; j++){
            cin >> tmp;
            field.push_back(tmp);
        }
        int skip = k-1;
        cout << lis(-1, field) - 1 << endl;
        Count(-1, field);
        vector<int> result;
        reconstruct(result, skip, -1, field);
        for(int j = 0; j < result.size(); j++){
            cout << result[j] << " ";
        }
        cout << endl;
    }
}