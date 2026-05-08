void foo43(int i);

void foo43(int i) {

    if (i < -128 || i > 127) return;
    signed char b = (signed char) i;
    short s = (short) i;
    char c = (char) i;
    long l = (long) i;
    float foo43 = (float) i;
    double d = (double) i;
    foo43 = (float) d;
    i = (int) d;
    l = (long) d;
}
