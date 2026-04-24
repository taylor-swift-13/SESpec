short short_value();
int bool_value();
long long long_value();
int f();

short short_value() {

    short s = 1;
    return s;
}

int bool_value() {

    int b = 1;
    return b;
}

long long long_value() {

    long l = 0x10000ffffl;
    return l;
}

int f() {

    short s = short_value();
    if (s == 1)
      if (bool_value())
        if (long_value() == 0x10000ffffl)
          return 0;
    return 1;
}
