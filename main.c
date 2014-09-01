#include "xmath.h"
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define QUOTE(...) #__VA_ARGS__

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

//Find the largest 6 digit palindrome that is a product
//of two 3 digit numbers. Generate palindromes p. Then for each p
//check if it is divisible by some j in [100,999].
//if it is, make sure the quotient p/j is also in [100,999]
//since we're going in decending order, we can quit when we find the first one.
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

//find the smallest number that is divisible by all
//the numbers from 1-20. An upper bound on this number
//would obviously be factorial(20). We can minimize this
//by walking over 1..20 and for each composite number
//divide it by any smaller factors
ulong64 euler5() {

    clock_t begin, end;
    begin = clock();

    int factors[19];
    int i;
    int f = 2;
    ulong64 ans = 1;
    for(i = 0; i < 19; i++) {
        int j;
        if(is_prime(f)) {
            factors[i] = f;
        }
        else {
            int t = f;
            for(j = 0; j < i; j++) {
                if(t % factors[j] == 0) {
                    t = t / factors[j];
                }
            }
            factors[i] = t;
        }
        f++;
        ans *= factors[i];
    }
    end = clock();
    printf("euler5 time: %f\n",(double)(end - begin) / CLOCKS_PER_SEC);
    printf("euler5 answer: %lld\n",ans);
    return ans;
}

//Find the difference between the sum of the squares of the
//first one hundred natural numbers and the square of the sum.
//The sum of the squares or S^2(n) has a closed formula namely
//n(n+1)(2n+1)/6. The sum of the first n natural numbers S(n)
//also has a closed formula, namely n(n+1)/2. Therefore the
//difference i.e. S(n)^2-S^2(n) can be written as a compact
//one liner - (3n^4+2n^3-3n^2-2n)/12
int euler6() {

    clock_t begin, end;
    begin = clock();
    int n = 100;
    ulong64 ans = (3*n*n*n*n + 2*n*n*n - 3*n*n - 2*n)/12;
    end = clock();
    printf("euler6 time: %f\n",(double)(end - begin) / CLOCKS_PER_SEC);
    printf("euler6 answer: %lld\n",ans);
    return ans;
}

//Using a (badly implemented) sieve to count primes
//less than 120000 since pi(120000) ~ 120000/ln(120000)
//~ 10260
int euler7() {


    int L = 120000;
    int *primes = (int*) malloc(sizeof(int)*L);
    memset(primes,0,sizeof(int)*L);

    clock_t begin, end;
    begin = clock();

    int i, j;
    for(i = 2; i < L; i++) {

        j = 2;
        while(j*i < L) {
           primes[j*i] = 1;
           j++;
        }
    }

    int count = 0;
    int answer;
    for(i = 2; i < L; i++) {
        if(primes[i] == 0 && ++count == 10001) {
            answer = i;
            break;
        }
    }

    end = clock();
    free(primes);
    printf("euler7 time: %f\n",(double)(end - begin) / CLOCKS_PER_SEC);
    printf("euler7 answer: %d\n",answer);
    return answer;
}

//To be continued with a shift register
int euler8() {

    clock_t begin, end;
    begin = clock();

    char * data = QUOTE(
                      7316717653133062491922511967442657474235534919493496983520312774506326239578
                      3180169848018694788518438586156078911294949545950173795833195285320880551112
                      5406987471585238630507156932909632952274430435576689664895044524452316173185
                      6403098711121722383113622298934233803081353362766142828064444866452387493035
                      8907296290491560440772390713810515859307960866701724271218839987979087922749
                      2190169972088809377665727333001053367881220235421809751254540594752243525849
                      0771167055601360483958644670632441572215539753697817977846174064955149290862
                      5693219784686224828397224137565705605749026140797296865241453510047482166370
                      4844031998900088952434506585412275886668811642717147992444292823086346567481
                      3919123162824586178664583591245665294765456828489128831426076900422421902267
                      1055626321111109370544217506941658960408071984038509624554443629812309878799
                      2724428490918884580156166097919133875499200524063689912560717606058861164671
                      0940507754100225698315520005593572972571636269561882670428252483600823257530
                      420752963450
                   );

    double reg[13] = {-1,7,3,1,6,7,1,7,6,5,3,1,3};
    int len = 1000;
    int i;
    double max,temp;

    max = 0;
    for(i = 12; i < len; i++) {

        reg[0] = reg[1];
        reg[1] = reg[2];
        reg[2] = reg[3];
        reg[3] = reg[4];
        reg[4] = reg[5];
        reg[5] = reg[6];
        reg[6] = reg[7];
        reg[7] = reg[8];
        reg[8] = reg[9];
        reg[9] = reg[10];
        reg[10] = reg[11];
        reg[11] = reg[12];
        reg[12] = ((double)data[i])-48;


        temp = reg[0]*reg[1]*reg[2]*reg[3]*
               reg[4]*reg[5]*reg[6]*reg[7]*
               reg[8]*reg[9]*reg[10]*reg[11]*
               reg[12];

        if(temp > max) max = temp;
    }
    end = clock();
    printf("euler8 time: %f\n",(double)(end - begin) / CLOCKS_PER_SEC);
    printf("euler8 answer: %f\n",max);
    return max;
}


int euler9() {
    //TODO - a^2+b^2=c^2
    //     with constraint a + b + c = 1000
    //     pythagorean triples can be constructed in the following way
    //     a = n^2 - m^2
    //     b = 2nm
    //     c = n^2 + m^2
    //     Adding in the constraint gives n(n+m)=500, choosing a few factors
    //     of 500 gives, n=20,m=5 since it must be that n | 500
    //     this gives a,b,c = {375,200,425}
    //     which gives the product abc=31875000

    return 0;
}

int euler10() {


    int L = 2000000;
    int *primes = (int*) malloc(sizeof(int)*L);
    memset(primes,0,sizeof(int)*L);

    clock_t begin, end;
    begin = clock();

    int i, j;
    for(i = 2; i < L; i++) {

        j = 2;
        while(j*i < L) {
           primes[j*i] = 1;
           j++;
        }
    }

    double answer = 0;
    for(i = 2; i < L; i++) {
        if(primes[i] == 0) {
            answer += i;
        }
    }

    end = clock();
    free(primes);
    printf("euler10 time: %f\n",(double)(end - begin) / CLOCKS_PER_SEC);
    printf("euler10 answer: %f\n",answer);
    return answer;
}

int main() {
    euler1();
    euler2();
    euler3();
    euler4();
    euler5();
    euler6();
    euler7();
    euler8();
    euler9();
    euler10();
    return 0;
}
