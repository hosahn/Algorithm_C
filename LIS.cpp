#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int cache[5000];

int solution(vector<int>& arr, int start){
    int &ret = cache[start];
    if(ret != -1) return ret;
    ret = 1;
    for(int i = start + 1; i < arr.size(); ++i){
        if(start  == -1 || arr[start] < arr[i])
            ret = max(ret, solution(arr, i) + 1);
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int k;
    cin >> k;
    for(int z = 0; z < k; z++) {
        int n;
        memset(cache, -1, sizeof(cache));
        cin >> n;
        vector<int> arr;
        for (int i = 0; i < n; i++) {
            int tmp;
            cin >> tmp;
            arr.push_back(tmp);
        }
        int maxLen = -1;
        for (int i = 0; i < n; i++) {
            maxLen = max(solution(arr, i), maxLen);
        }
    }
}