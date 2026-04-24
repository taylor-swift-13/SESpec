int i();
long long l();
void s();

int i() {

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

long long l() {

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

void s() {

    short lhs = 127;
    short rhs = 32767;
    if (lhs < rhs) {
      return;
    }
    assert 0;
}
