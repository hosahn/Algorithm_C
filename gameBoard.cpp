#include <iostream>
#include <vector>
using namespace  std;

const int coverType[4][3][2] = {
        {{0,0}, {1,0}, {0, 1}},
        {{0, 0}, {0, 1}, {1,1}},
        {{0,0}, {1,0}, {1, 1}},
        {{0,0}, {1,0}, {1,-1}}
};

bool set(vector<vector<int>> &board, int x, int y, int i, int j){
    bool ok = true;
    for(int k = 0; k < 3; ++k){
        const int nx = x + coverType[i][k][0];
        const int ny = y + coverType[i][k][1];
        if(nx < 0 || nx >= board.size() || ny < 0 || ny >= board[0].size())
            ok = false;
        else if ((board[nx][ny] += j) > 1)
            ok = false;
    }
    return ok;
}

int solution(vector<vector<int>> &board, int width, int height){
    int minX = -1;
    int minY = -1;

    for(int i =0; i < height; i++){
        for (int j =0; j< width; j++){
            if (board[i][j] == 0){
                minX = i;
                minY = j;
                break;
            }
        }
        if(minX != -1) break;
    }
    if (minX == -1) {
        return 1;
    }
    int result = 0;
    for (int z =0; z < 4; z++) {
        if(set(board, minX, minY, z, 1)){
            result += solution(board, width, height);
        }
        set(board, minX, minY, z, -1);
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    char a = '#';
    for(int i = 0; i < n; i++){
        int height, width;
        cin >> height >> width;
        vector<vector<int>> board;
        for(int k = 0; k < height; k++) {
            string str;
            vector<int> line(0);
            cin >> str;
            for (int j = 0; j < width; j++) {
                if (str[j] == a) line.push_back(1);
                else line.push_back(0);
            }
            board.push_back(line);
        }
        cout << solution(board, width, height) << endl;
    }
}