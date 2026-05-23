int foo27_c5(int n);


int foo27_c5(int n) {

    if (n > 100) return n - 10;
    else return foo27_c5(foo27_c5(n + 11));
}