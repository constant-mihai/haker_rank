/***************************************** 

* File Name : main.C

* Creation Date : 20-07-2015

* Last Modified :

* Created By : Mihai Constantin constant.mihai@googlemail.com

******************************************/

#include <iostream>
#include <stdio.h>

using namespace std;

int main(int argc, char** argv) {
    float n = 0;
    float np = 0 , nn = 0, z = 0;
    int a[100];

    cin >> n;
    if (n<1 || n>100) {
        printf ("N should be between 1 and 100\n");
        return -1;
    }

    for (int i = 0; i<n; i++) {
        cin >> a[i];
        if (a[i]<-100 || a[i]>100) {
            printf("Matrix elements should be between -100 and 100\n");
            return -1;
        }

        if (a[i] > 0) np++;
        if (a[i] < 0) nn++;
        if (a[i] == 0) z++;
    }

    printf("%f\n", np/n);
    printf("%f\n", nn/n);
    printf("%f\n", z/n);

}
