#include <iostream> //표준입출력 라이브러리, 더 안전함
#include <stdio.h> //표준입출력 라이브러리
#include <string.h> //stoi 사용을 위해서
#include <vector> //구조체
using namespace  std;

//주석은 JAVA 작성법과 동일하다.
// 1. arr == &arr[0];
// 2. *arr == arr[0];
int main() {
    int arr[3];
    int *ptr = arr;
    printf("%d\n", ptr);
    int arr2[3];
    int *ptr2 = arr2; // arr[i] == *(arr + i), *&같이 있으면 사라짐
    ptr = ptr2;
    printf("%d\n", ptr2);
    printf("%d\n", ptr);

    int arr3[3] = {1,2,3};
    int *ptr_arr = arr3; // ptr_arr 자체가 ptr_arr[1][3]의 배열이 된다.

    for (int i =0; i < 3; i++){
        printf("%d\n", ptr_arr[i]);
    }

    int arr_2d[2][3] = {{1,3,4}, {1,3,4}};
    int(*ptr_2d)[3] = arr_2d; // ptr_2d 자체가 ptr_2d[2][3]의 배열이 된다.
    //따라서 배열의 치환은 ptr을 이용한다. ptr의 주소값을 바꾸자.
    printf("%d ! \n ", ptr_2d[1][2]);
    int ex1[2][3] = {{1,2,3},{4,5,6}};
    for (int(*row)[3] = ex1; row < ex1+2; row++){
        printf("%d ", *row[1]); // *row는 1차원 배열을 가리키는 포인터이므로 ex1[i]의 주소값을 나타낸다.
        for(int *col = *row; col < *row+3; col++){ // *col은 *row, (*row는 각 일차원 배열의 주소값) 즉 배열 안 요소의 주소를 나타내는 포인터이다.
            printf("%d ", *col); // **col은 즉, value를 나타낸다.
        }
        printf("\n");
        // *row[1]과 row[1][2]는 같다. 왜냐하면 *row자체가 어떠한 일차원배열 row[i]를 가리키기 때문이다. 반대로 row[i]만 쓰면 그냥 일차원배열의 주소값만 출력된다. 왜? 알잖어.
        // 정리 : 일차원 배열에서는 *col하면 값이 출력된다. 이차원 배열에서는 *row[i]하면 출력된다. *x 자체가 배열 x를 가리키기 때문이다.
        // 기본적으로 int *ptr = arr 하면 ptr[1]로도 출력 가능하고, *ptr + 1로도 출력 가능하다. ptr[0] = *ptr, ptr[1] = *ptr + 1 ....
    }
    char strings[3][10] ={"Hello", "World", "Hosan"};
}
// sizeof(x) : x의 크기를 알려줌
// x : 형 (int, float ...)
//     변수이름
