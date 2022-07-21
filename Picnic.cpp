#include <iostream>
#include <vector>
using namespace  std;

int solution(vector<vector<bool>> student, vector<bool> &isTaken, int length) {
    int firstFree = -1;
    for (int i = 0; i < length; i++){
        if(!isTaken[i]){
            firstFree = i;
            break;
        }
    }
    if (firstFree == -1) {
        return 1;
    }
    int ret = 0;
    for(int pairWith = firstFree + 1; pairWith < length; pairWith++){
        if(!isTaken[pairWith] && student[firstFree][pairWith]) {
            isTaken[firstFree] = isTaken[pairWith] = true;
            ret += solution(student, isTaken, length);
            isTaken[firstFree] = isTaken[pairWith] = false;
        }
    }
    return ret;
}

int main () {
    int n;
    cin >> n;
    for(int i=0; i< n; i++){
        int a, b;
        cin >> a >> b;
        vector<vector<bool>> student;
        vector<bool> isTaken(a, false);
        vector<bool> arr(a, false);
        for(int j = 0; j < a; j++){
            student.push_back(arr);
        }
        for(int j = 0; j < b; j++){
            int x, y;
            cin >> x >> y;
            student[x][y] = true;
            student[y][x] = true;
        }
        cout << solution(student, isTaken, a) << endl;
    }
}
