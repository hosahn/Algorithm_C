#include <iostream>
using namespace std;

void abc(int (*x)[5]){
    for(int i = 0; i < sizeof(*x)/sizeof((*x)[0]); i++){
        cout << (*x)[i] << endl;
        (*x)[i] = 20;
    }
}

int main(){

    int arr[5]={1,2,3,4,5};
    int (*ptr)[5] = &arr;
    abc(ptr);
    for(int i =0; i < 5; i++){
        cout << arr[i] << endl;
    }
}