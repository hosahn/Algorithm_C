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
        else {
            board[nx][ny] += j;
            if(board[nx][ny] > 1) ok = false;
        }
    }
    return ok;
}

//set에 단순히 board[nx][ny] = true를 대입할 수 없는 이유 :
//나중에 방문 해제처리 할 때(다시 false로 되돌릴 때) 원래 true였던 애까지 false로 바꿔버린다 => 무한루프에 빠진다.
//따라서 1, -1을 대입해서 (일단 한 번 방문한 칸들은 결국 무조건 방문 해제처리하는 백트래킹 로직이니) 더했다 뻈다 해주면 된다.

int solution(vector<vector<int>> &board, int width, int height){
    int minX = -1;
    int minY;
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
    if (minX == -1) return 1;
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