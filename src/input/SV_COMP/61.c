int foo61();

struct A_state {
    int i;
};

int foo61() {

    struct A_state A = {1};
    if(A.i != 1) return 0;
    A.i = 999;
    if (A.i != 999)
      return 0;
    return 1;
}
