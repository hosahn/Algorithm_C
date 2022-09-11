#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int cache[1001];
int size;
vector<int> field;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(cache, 0, sizeof(cache));
    cin >> size;
    for(int i = 0; i < size; i++){
        int tmp;
        cin >> tmp;
        field.push_back(tmp);
    }
    int MaxLength = 0;
    for(int i = 1; i < size; i++){
        cache[i] = 1;
        for(int j = i - 1; j >= 0; j--){
            if(field[i] > field[j])
                cache[i] = cache[j] + 1;
        }
        if(cache[i] > MaxLength) {
            MaxLength = cache[i];
        }
    }
    cout << MaxLength;
}