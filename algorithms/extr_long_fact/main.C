/***************************************** 

* File Name : main.C

* Creation Date : 23-07-2015

* Last Modified :

* Created By : Mihai Constantin constant.mihai@googlemail.com

******************************************/


#include <iostream>
#include <string>
#include <stdio.h>
#include <math.h>

using namespace std;

void subtract_arrays(char *a, char* b, char* diff);

class BigInt {

    public:
        /* Constructors */
        BigInt() { 
            bzero(a, 1000*sizeof(long long int)); 
            size = 0;
        };


        BigInt(BigInt&) {
            bzero(a, 1000*sizeof(long long int)); 
        };


        BigInt(string s) {
            bzero(a, 1000*sizeof(long long int)); 

        }

        BigInt(char* aPtr, unsigned int size) {
            this->size = size;
            for (unsigned int i = 0; i<this->size; i++)
                a[i] = aPtr[i];

            s.assign(aPtr, size);
        }

        /* Destructor*/
        ~BigInt();

        BigInt& operator=(BigInt& bInt) {

            if (&bInt != this) {
                // TODO copy array/string here
                this->s     = bInt.getStr();
                this->size  = bInt.getSize();

                for (unsigned int i = 0; i<this->size; i++)
                    a[i] = bInt.getArray()[i];
            }

            return this;
        }


        BigInt operator+(BigInt& bInt) const {

            long long int* sum[1000];
            bzero(sum, 1000*sizeof(long long int));
            unsigned int newSize    = (size > bInt.getSize()) ? size : bInt.getSize();
            int          sDiff      = size - bInt.getSize();
            unsigned int abs_sDiff  = abs(sDiff);

            for (unsigned int i = newSize; i>=0; i--) {
                if (sDiff >= 0) {
                    sum[i] = bInt.getArray()[i] + a[i-abs_sDiff];
                } else {
                    sum[i] = a[i]               + bInt.getArray()[i-abs_sDiff];
                }
            }
            
            BigInt bInt_sum(sum, newSize);
            return bInt_sum;
        };

        BigInt& operator-(BigInt& bInt) {
        }

        BigInt& operator*(BigInt& bInt) {
        }

        BigInt& operator/(BigInt& bInt) {
        }

        string                   getStr()    const { return s; };
        const long long int*     getArray()  const { return a; };
        int                      getSize()         { return size; };

    private:
        string          s;
        long long int   a[1000];
        unsigned int    size;
}
