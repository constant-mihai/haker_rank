/***************************************** 

* File Name : main.C

* Creation Date : 20-07-2015

* Last Modified :

* Created By : Mihai Constantin constant.mihai@googlemail.com

******************************************/

#include <iostream>
#include <cstdio>
#include <math.h>
#include <cmath>

using namespace std;

int main(int argc, char** argv) {

    int n = 0;
    int m[100][100];
    long int sum[2];

    cin >> n;
    if (n<1 || n>100) {
        printf ("N should be between 1 and 100\n");
        return -1;            
    }

    for (int i = 0; i<n; i++)
        for (int j = 0; j<n; j++) {
            cin >> m[i][j];
            if (m[i][j]<-100 || m[i][j]>100) {
                printf("Matrix elements should be between -100 and 100\n");
                return -1;
            }

            if (i == j) sum[0]+= m[i][j];
            if (j == (n-1-i)) sum[1]+=m[i][j];
    }

    cout << abs(sum[0]-sum[1]);
}
