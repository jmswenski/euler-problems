
#include "xmath.h"

ulong64 gcd(ulong64 a, ulong64 b) {
  long c;
  while (a != 0) {
     c = a;
     a = b % a;
     b = c;
  }
  return b;
}
