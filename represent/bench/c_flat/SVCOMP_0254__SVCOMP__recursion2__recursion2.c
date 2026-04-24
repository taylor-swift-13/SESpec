int f();
int recursion_test(int depth);

int f() {

    return recursion_test(0) == 10;
}

int recursion_test(int depth) {

    if (depth < 10) return recursion_test(depth + 1) + 1;
    else return 0;
}
