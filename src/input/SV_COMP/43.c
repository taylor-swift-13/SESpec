void foo43(int i);

void foo43(int i) {

    if (i < -128 || i > 127) return;
    byte b = (byte) i;
    assert b == i;
    short s = (short) i;
    assert s == i;
    char c = (char) i;
    assert c == (0xffff & i);
    long l = (long) i;
    assert l == i;
    float foo43 = (float) i;
    assert foo43 == i;
    double d = (double) i;
    assert d == i;
    foo43 = (float) d;
    assert (float) d == foo43;
    i = (int) d;
    assert (int) d == i;
    l = (long) d;
    assert i == l;
}
