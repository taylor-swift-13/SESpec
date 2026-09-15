```c
/*@
  logic integer sum(int a, int b, int c, int d) = a + b + c + d;
*/

void foo114(int v1, int v2, int v3) {

    int x1;
    int x2;
    int x3;
    int t;

    x1 = 100;
    x2 = 75;
    x3 = -50;
    t = 0;

    /*@
      loop invariant (\at(v2,Pre) + 5 >= 0 && \at(v2,Pre) <= 5) ==> (v2 == \at(v2,Pre) - t + \sum_{i=0}^{t-1} (x2 * 2 - x1 - x3 >= 0 ? -1 : 1));
      loop invariant (\at(v2,Pre) + 5 >= 0 && \at(v2,Pre) <= 5) ==> (x1 =100