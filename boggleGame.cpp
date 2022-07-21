#include <stdio.h>
#include<string.h>
using namespace std;

int n;
int d;
char word[11];
char field[5][5];
int checked[5][5][10] = {0,};
int dx[8] = {1,1, 0, -1, -1, -1, 0, 1};
int dy[8] = {0,1, 1,1, 0, -1, -1, -1};

int findall(int x, int y, int depth){
    if (depth >= strlen(word)){
        return 1;
    }
        for (int i =0; i<8;i++){
            int mx = x + dx[i];
            int my = y + dy[i];
            if (mx >= 0 && mx < 5 && my >=0 && my < 5){
                if(word[depth] == field[mx][my] && checked[mx][my][depth+1] != -1) {
                    int flag = findall(mx, my, depth+1);
                    if(flag == 1){
                        return 1;
                    }
                    else {
                        continue;
                    }
                }
            }
        }
        checked[x][y][depth] = -1;
        return -1;
}
bool Find(void){
    for(int i =0; i<5; i++){
        for (int j = 0; j < 5; j++){
            if (field[i][j] == word[0]){
                if (findall(i, j, 1) == 1){
                    return true;
                }
            }
        }
    }
    return false;
}

int main(){
    scanf("%d", &n);
    for (int i =0; i< n; i++) {
        for(int j = 0; j < 5; j++){
            scanf("%s", field[j]);
        }
       scanf("%d", &d);

        for(int j = 0; j < d; j++){
            memset(checked, 0, sizeof(checked));
            scanf("%s", &word);
            if(Find()){
                printf("%s %s\n", word, "YES");
            }
            else{
                printf("%s %s\n", word, "NO");
            }
        }
        }
    return 0;
    }
