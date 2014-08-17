#include <stdio.h>
#include <time.h>
#include <math.h>

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
    printf("time: %f\n",(double)(end - begin) / CLOCKS_PER_SEC);
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


int main() {
    euler1();
    euler2();
    return 0;
}
