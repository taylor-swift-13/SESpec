int foo27(int n);

int foo27(int n) {

    if (n > 100) return n - 10;
    else return foo27(foo27(n + 11));
}
