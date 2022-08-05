#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int>& fence, int right, int left){
    if(right == left){
        return fence[left];
    }
    int mid = (right + left) / 2;
    int ret = max(solution(fence, mid, left), solution(fence, right, mid + 1));
    int lo = mid, hi = mid + 1;
    int height = min(fence[lo], fence[hi]);
    ret = max(ret, height * 2);
    while(left < lo || hi < right) {
        if(hi < right && (lo == left || fence[lo-1] < fence[hi + 1])){
            ++hi;
            height = min(height, fence[hi]);
        }
        else {
            --lo;
            height = min(height, fence[lo]);
        }
        ret = max(ret, height * (hi - lo + 1));
    }
    return ret;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //20000개로 입력이 많으니 최적화 해준다.
    int n;
    cin >> n;
    for (int i = 0;  i < n; i++){
        vector<int> fence;
        int k;
        cin >> k;
        for(int j = 0; j < k; j++){
            int tmp;
            cin >> tmp;
            fence.push_back(tmp);
        }
        cout << solution(fence, fence.size() -1 , 0) << endl;
    }
}