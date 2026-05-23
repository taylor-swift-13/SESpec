Here is the completed C program with the placeholders filled:

```c
void foo307(unsigned int n) {

    unsigned int j;
    unsigned int i;
    unsigned int k;
    unsigned int v4;
    unsigned int v3;
    unsigned int v2;
    unsigned int v1;
    unsigned int l;

    i = 0;
    k = 0;
    j = 0;
    l = 0;
    v4 = 0;
    v3 = 0;
    v2 = 0;
    v1 = 0;

    /*@
      loop invariant (0 < \at(n,Pre)) ==> (j == \sum(0, l-1, \lambda x; (x % 2 == 0 && x % 3 != 0 && x % 4 != 0 && x % 5 != 0 && x % 6 != 0 && x % 7 != 0)));
      loop invariant (0 < \at(n,Pre)) ==> (i == \sum(0, l-1, \lambda x; (x % 3 == 0 && x % 4 != 0 && x % 5 != 0 && x % 6 != 0 && x % 7 != 0)));
      loop invariant (0 < \at(n,Pre)) ==> (k == \sum(0, l-1, \lambda x; (x % 7 == 0 && x % 6 != 0 && x % 5 != 0 && x % 4 != 0 && x % 3 != 0 && x % 2 != 0)));
      loop invariant (0 < \at(n,Pre)) ==> (v4 ==