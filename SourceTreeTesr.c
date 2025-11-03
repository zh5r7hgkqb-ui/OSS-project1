#include <stdio.h>

int main(){

    int i=0; 

    printf("hello world\n");
    printf("my name is hooyoien\n");
    printf("메인 브렌치에 추가했음");
    for(i=0; i<5; i++){
        printf("테스트 브렌치\n", i);
    }

    printf("끝\n");
    printf("추가함");
    printf("테스트 브렌치에 추가했음");
    return 0;
}