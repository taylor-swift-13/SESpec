int f();

int f() {

    if(A.i != 1) return 0;
    A.i = 999;
    if (A.i != 999)
      return 0;
    return 1;
}
