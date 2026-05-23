
/*@
  logic integer power2(integer n) = n <= 0 ? 1 : 2 * power2(n - 1);
*/

void foo84(int x,int y){

    int a=x;
    int b=y;
    int p=1;
    int q=0;

    /*@
      loop invariant (\at(x,Pre) != 0 && \at(y,Pre) != 0) ==> (p >= 1);
      loop invariant (\at(x,Pre) != 0 && \at(y,Pre) != 0) ==> (x == \at(x,Pre));
      loop invariant (\at(x,Pre) != 0 && \at(y,Pre) != 0) ==> (y == \at(y,Pre));
      loop invariant (!(\at(x,Pre) != 0 && \at(y,Pre) != 0)) ==> ((q == 0)&&(p == 1)&&(b == \at(y,Pre))&&(a == \at(x,Pre))&&(y == \at(y,Pre))&&(x == \at(x,Pre)));
      loop invariant y == \at(y,Pre);
      loop invariant x == \at(x,Pre);
      loop assigns a, b, p, q;
    */
    while(a!=0 && b!=0) {
     if (a % 2 ==0 && b % 2 ==0 ){
          a = a/2;
          b = b/2;
          p = 4*p;
     }
     else if (a % 2 ==1 && b % 2 ==0 ){
          a = a-1;
          q = q+b*p;
     }
     else if (a % 2 ==0 && b % 2 ==1 ){
          b = b-1;
          q = q+a*p;
     }
     else {
          a = a-1;
          b = b-1;
          q = q+(a+b+1)*p;
     }
    }
}
