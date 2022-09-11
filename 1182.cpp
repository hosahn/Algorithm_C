#include <vector>
#include <iostream>
using namespace std;
int result = 0;
int arr[30];

int solution(int cur, int idx, int size, int target){
    if (cur == size) {
        if (idx == target) result++;
        return 0;
    }
    solution(cur + 1, idx + arr[cur], size, target);
    solution(cur + 1, idx, size, target);
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int size, target;
    cin >> size >> target;
    for(int i = 0; i < size; i++) cin >> arr[i];
    solution(0, 0, size, target);
    if(target == 0) result--;
    cout << result;
    return 0;
}