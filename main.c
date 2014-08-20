#include "xmath.h"
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

//returns the sum of all the
//multiples of 3 or 5
int euler1() {

    clock_t begin, end;
    begin = clock();
    int i,k,s;
    s = 0;
    for(i = 1; i <= 333; i++) {
        if(i < 200) s += i*5;
        if((k = 3*i) % 5) s += k;
    }
    end = clock();
    printf("euler1 time: %f\n",(double)(end - begin) / CLOCKS_PER_SEC);
    printf("euler1 answer: %d\n",s);
    return s;
}

//returns the sum of the even Fibonacci
//numbers valued less than 4,000,000
int euler2() {

    clock_t begin, end;
    begin = clock();
    int i,s;
    s = 0;
    double g = (1 + sqrt(5))/2;

    for(i = 1; i <= 11; i++) {
    	int fn = floor(pow(g,i)/sqrt(5) + 0.5);
    	s += 5*pow(fn,3)+3*pow(-1,i)*fn;
    }

    end = clock();
    printf("euler2 time: %f\n",(double)(end - begin) / CLOCKS_PER_SEC);
    printf("euler2 answer: %d\n",s);
    return s;
}


//Using Pollard's rho algorithm and
//just keeping track of a max to find the
//largest prime factor of 600851475143
ulong64 euler3() {

    clock_t begin, end;
    begin = clock();
    ulong64 x,y,d,n, max;
    n=600851475143;
    max = 0;
    while(n != 1) {
        x=2; y=2; d=1;
        while(d == 1) {
            x = (x*x - 1) % n;
	    y = (((y*y - 1) % n)*((y*y - 1) % n) - 1) % n;
            d = gcd(abs(x-y),n);
            if(d > max) max = d;
        }
	n = n / d;
    }
    end = clock();
    printf("euler3 time: %f\n",(double)(end - begin) / CLOCKS_PER_SEC);
    printf("euler3 answer: %lld\n", max);
    return max;
}

int euler4() {

    clock_t begin, end;
    begin = clock();
    int i,max;
    max = 0;
    for(i = 999; i >= 100; i--) {
        int p,j;
        if(max > 0) break;
        p = 1100 * i - 990 * floor(i/10.0) - 99 * floor(i/100.0);
        for(j=100; j <= 999; j++) {
            int d = p / j;
            if(p % j == 0 && d <= 999 && d >= 100) {
	        max = p;
	    }
        }
    }
    end = clock();
    printf("euler4 time: %f\n",(double)(end - begin) / CLOCKS_PER_SEC);
    printf("euler4 answer: %d\n",max);
    return max;
}


int main() {
    euler1();
    euler2();
    euler3();
    euler4();
    return 0;
}
