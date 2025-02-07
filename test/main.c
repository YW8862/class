#include <stdio.h>
#define AA 1
#define BB 1<<1
#define CC 1<<2
#define DD 1<<3

void print(int flag){
    if(flag & AA)printf("1\n");
    if(flag & BB)printf("2\n");
    if(flag & CC)printf("3\n");
    if(flag & DD)printf("4\n");
}

int main(void) {
    print(AA);
    printf("-------------------------\n");
    print(BB|AA|CC);
    printf("-------------------------\n");
    print(CC|AA|DD);
    printf("-------------------------\n");
    print(DD|BB|CC|AA);
    printf("-------------------------\n");

    return 0;
}
