int foo61();

int foo61() {

    if(A.i != 1) return 0;
    A.i = 999;
    if (A.i != 999)
      return 0;
    return 1;
}
