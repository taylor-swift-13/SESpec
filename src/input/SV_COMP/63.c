short foo63_helper1();
int foo63_helper2();
long long foo63_helper3();
int foo63();

short foo63_helper1() {

    short s = 1;
    return s;
}

int foo63_helper2() {

    int b = 1;
    return b;
}

long long foo63_helper3() {

    long l = 0x10000ffffl;
    return l;
}

int foo63() {

    short s = foo63_helper1();
    if (s == 1)
      if (foo63_helper2())
        if (foo63_helper3() == 0x10000ffffl)
          return 0;
    return 1;
}
