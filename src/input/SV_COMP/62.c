int foo62_helper1();
int foo62(int depth);

int foo62_helper1() {

    return foo62(0) == 10;
}

int foo62(int depth) {

    if (depth < 10) return foo62(depth + 1) + 1;
    else return 0;
}
