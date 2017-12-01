/***************************************** 

* File Name : main.C

* Creation Date : 20-07-2015

* Last Modified :

* Created By : Mihai Constantin constant.mihai@googlemail.com

******************************************/

#include <iostream>
#include <stdio.h>

using namespace std;

typedef enum {
    Earlier,
    Expected_date,
    Same_month,
    Same_year,
    Other_year,
} ret_date_e;

typedef enum {
    unknown,
    Jan,
    Febr,
    Mar,
    Apr,
    Mai,
    Jun,
    Jul,
    Aug,
    Sept,
    Oct,
    Nov,
    Dec,
} month_e;

typedef struct  {
    int dd;
    int mm;
    int yy;
}date_t;

bool check_leap_year(int year) {

    if ( (year%4) != 0 )
        return false;
    else if ( (year%100) != 0 )
        return true;
    else if ( (year%400) != 0 )
        return false;
    else
        return true;
}

int calc_days(month_e month, int year) {

    bool is_leap_year = check_leap_year(year);

    switch(month) {
        case Jan:
            return 31;
            break;
        case Febr:
            if (is_leap_year) return 29;
            else return 28;
            break;
        case Mar:
            return 31;
            break;
        case Apr: 
            return 30;
            break;
        case Mai:
            return 31;
            break;
        case Jun:
            return 30;
            break;
        case Jul:
            return 31;
            break;
        case Aug:
            return 31;
            break;
        case Sept:
            return 30;
            break;
        case Oct:
            return 31;
            break;
        case Nov:
            return 30;
            break;
        case Dec:
            return 31;
            break;
        default:
            return -1;
            break;
    }

    return -1;
}

int compare_date(date_t ard, date_t erd, int& late_days, int& late_months) {

    if ( (ard.yy-erd.yy) > 0 ) return Other_year;
    if ( (ard.yy-erd.yy) < 0 ) return Earlier;

    if ( ard.mm != erd.mm ) {
        if ( ard.mm > erd.mm) {
            for ( int i=erd.mm; i<=ard.mm; i++ ) {
                int diff = 0;
                int days_in_month = calc_days((month_e)i, ard.yy);

                if      (i==erd.mm) diff = erd.dd;
                else if (i==ard.mm) diff = days_in_month - ard.dd;
                else                diff = 0;

                late_days += (days_in_month - diff);
            }

            late_months = ard.mm - erd.mm;
            return Same_year;
        }

        if ( ard.mm < erd.mm ) return Earlier;
    }

    if ( ard.mm == erd.mm ) {
        if ( ard.dd == erd.dd ) { 
            return Expected_date;
        } else if ( ard.dd < erd.dd ) {
            return Earlier;
        } else {
            late_days = ard.dd-erd.dd;
            return Same_month;
        }
    }

    return -1;
}

int main (int argc, char** argv) {

    int fine = 0;
    int rd = 0, late_days = 0, late_months;
    date_t ard, erd;

    cin >> ard.dd >> ard.mm >> ard.yy;
    cin >> erd.dd >> erd.mm >> erd.yy;

    if ( ard.dd < 1 || ard.dd > 31 || ard.mm < 1 || ard.mm > 12 || ard.yy < 1 || ard.yy > 3000 )
        return -1;

    if ( erd.dd < 1 || erd.dd > 31 || erd.mm < 1 || erd.mm > 12 || erd.yy < 1 || erd.yy > 3000 )
        return -1;

    rd = compare_date(ard, erd, late_days, late_months);

    switch(rd) {
        case Earlier:
             fine = 0;
             break;
        case Expected_date:
            fine = 0;
            break;
        case Same_month:
            fine = 15*late_days;
            break;
        case Same_year:
            fine = 500*late_months;
            break;
        case Other_year:
            fine = 10000;
            break;
        default:
            return -1;
            break;
    }
    
    printf("%d", fine);
}
