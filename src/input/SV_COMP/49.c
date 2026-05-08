void foo49(const char * * args, int args_len);

void foo49(const char * * args, int args_len) {

    int i = 99;
    ++i;
    int tmp = i + 2;
    i = tmp;
    tmp = i - 3;
    i = tmp;
    i += 3;
    i -= 3;
    tmp = i * 2;
    i = tmp;
    tmp = i / 3;
    i = tmp;
    i %= 34;
    i = -i;
    long l = 99;
    ++l;
    l += 2L;
    l -= 3L;
    l *= 2L;
    l /= 3L;
    l %= 34L;
    l = -l;
}
