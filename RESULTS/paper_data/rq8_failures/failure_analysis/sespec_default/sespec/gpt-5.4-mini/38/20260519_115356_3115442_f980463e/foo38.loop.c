
/*@
  logic integer pow2(integer n) = (n <= 0) ? 1 : 2 * pow2(n - 1);
*/

void foo38(int v1, int v2, int v3) {

    int x1;
    int x2;
    int x3;
    int t;

    x1 = 100;
    x2 = 75;
    x3 = -50;
    t = 0;

    /*@
      loop invariant v3 == \at(v3,Pre);
      loop invariant v1 == \at(v1,Pre);
      loop invariant t >= 0;
      loop invariant x1 == 100 + t * \at(v1,Pre);
      loop invariant x3 == -50 + t * \at(v3,Pre);
      loop invariant x2 == x2;
      loop invariant v2 == v2;
      loop assigns x1, x3, x2, v2, t;
    */
    while(v2 + 5 >= 0 && v2 <= 5){
       x1 = x1 + v1;
       x3 = x3 + v3;
       x2 = x2 + v2;
       if(x2 * 2 - x1 - x3 >= 0){
         v2 = v2 - 1;
       }
       else if(x2 * 2 - x1 - x3 <= 0){
         v2 = v2 + 1;
       }
       t = t + 1;
    }
}
