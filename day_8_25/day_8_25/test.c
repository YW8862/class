#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

#include<stdio.h>
#include<math.h>
int main() {
    int num = 0;
    scanf("%d", &num);
    for (int i = 0; i < num; i++) {
        double a = 0, b = 0, c = 0;
        scanf("%lf%lf%lf", &a, &b, &c);
        double temp = b * b - 4 * a * c;
        double x1 = 0, x2 = 0;
        if (temp > 0) {
            x1 = (-b + sqrt(temp)) / 2 * a;
            x2 = (-b - sqrt(temp)) / 2 * a;
            printf("x1=%.5lf;x2=%.5lf\n", x1, x2);
        }
        else if (temp == 0) {
            x1 = x2 = -b / 2 * a;
            printf("x1=x2=%.5lf\n", x1);
        }
        else {
            x1 = (-b + sqrt(-temp)) / 2 * a;
            x2 = (-b - sqrt(-temp)) / 2 * a;
            printf("x1=%.5lf;x2=%.5lf\n", x1, x2);
        }
    }


}