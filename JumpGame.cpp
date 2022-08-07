#include <iostream>
#include <vector>
using namespace std;

int solution(vector<vector<int>>& field, vector<vector<int>>& visited, int x, int y, int size){
    if (x >= size || y >= size) {
        return -1;
    }
    if ((x == size - 1) && (y == size - 1)) {
        return 1;
    }
    if (visited[x][y] != 0) {
        return visited[x][y];
    }
    int jump = field[x][y];
    int s1 = solution(field, visited, x + jump, y, size);
    int s2 = solution(field, visited, x, y+ jump, size);
    if (s1 == 1 || s2 == 1){
        return visited[x][y] = 1;
    }
    else{
        return visited[x][y] = -1;
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        vector<vector<int>> field;
        vector<vector<int>> visited;
        int size;
        cin >> size;
        for(int j = 0; j < size; j++){
            vector<int> tmp(0);
            vector<int> tmpVisited(size);
            for(int k = 0; k < size; k++){
                int z;
                cin >> z;
                tmp.push_back(z);
            }
            field.push_back(tmp);
            visited.push_back(tmpVisited);
        }
        int result = solution(field, visited, 0, 0, size);
        if (result == 1){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}