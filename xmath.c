#include "xmath.h"

ulong64 gcd(ulong64 a, ulong64 b) {

    ulong64 c;
    while (a != 0) {
        c = a;
        a = b % a;
        b = c;
     }
     return b;
}
