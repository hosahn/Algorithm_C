#include <iostream>
using namespace std;

void abc(int (*x)[5]){
    cout << x << endl;
}

int main(){

    int arr[5]={1,2,3,4,5};
    int (*ptr)[5] = &arr;
    abc(ptr);
}