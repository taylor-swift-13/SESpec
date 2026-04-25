int foo50_helper1();
long long foo50_helper2();
void foo50();

int foo50_helper1() {

    int value = 3;
    value &= 1;
    value |= 4;
    value ^= 4;
    value <<= 2;
    value >>= 1;
    value = -value;
    value >>>= 1;
    return value;
}

long long foo50_helper2() {

    long value = 3L;
    value &= 1L;
    value |= 4L;
    value ^= 4L;
    value <<= 2L;
    value >>= 1L;
    value = -value;
    value >>>= 1L;
    return value;
}

void foo50() {

    short lhs = 127;
    short rhs = 32767;
    if (lhs < rhs) {
      return;
    }
    assert 0;
}
