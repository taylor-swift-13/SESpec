#include <assert.h>

void f(int i);

void f(int i) {
    if (i < -128 || i > 127) return;
    signed char b = (signed char)i;
    assert(b == i);
    short s = (short)i;
    assert(s == i);
    unsigned short c = (unsigned short)i;
    assert(c == (unsigned short)(0xffff & i));
    long l = (long)i;
    assert(l == i);
    float ff = (float)i;
    assert(ff == i);
    double d = (double)i;
    assert(d == i);
    ff = (float)d;
    assert((float)d == ff);
    i = (int)d;
    assert((int)d == i);
    l = (long)d;
    assert(i == l);
}
