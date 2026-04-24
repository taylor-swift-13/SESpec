int f();

int f() {

    long l = 4620693217682128896L;

    int i = (int) l;
    char c = (char) l;
    float f = l;
    double d = l;
    short s = (short) l;

    if (i >= 0)
      if ((long) i != (l & 0x7fffffff))
        return 0;

    if (c >= 0)
      if ((long) c == (l & 0x7fff))
        return 0;

    if (s >= 0)
      if ((long) s == (l & 0x7fff))
        return 0;

    return 1;
}
