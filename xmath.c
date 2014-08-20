#include "xmath.h"
#include <stdlib.h>

ulong64 gcd(ulong64 a, ulong64 b) {

    ulong64 c;
    while (a != 0) {
        c = a;
        a = b % a;
        b = c;
     }
     return b;
}

ulong64 * factor(ulong64 n, int *numFactors) {

	ulong64 x,y,d,size;
	size = 10;
	ulong64 *buffer = (ulong64*) malloc(sizeof(ulong64)*size);

	int i = 0;
	while(n != 1) {
	    x=2; y=2; d=1;
		while(d == 1) {
		    x = (x*x - 1) % n;
		    y = (((y*y - 1) % n)*((y*y - 1) % n) - 1) % n;
	        buffer[i] = gcd(abs(x-y),n);
	        i++;
	        if(i == size) {
	        	size = 2*size;
	        	realloc(buffer,size);
	        }
	    }
		n = n / d;
	}
	*numFactors = i;
	return buffer;
}
