int foo62_helper1_c13();
int foo13(int depth);

int foo62_helper1_c13() {

    return foo13(0) == 10;
}

int foo13(int depth) {

    if (depth < 10) return foo13(depth + 1) + 1;
    else return 0;
}
