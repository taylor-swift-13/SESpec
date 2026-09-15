
#include <limits.h>

/*@
  requires x >= 0;
  requires y >= 0;
  requires x == 0 || y <= INT_MAX / x;
*/
void foo84(int x,int y){

    int a=x;
    int b=y;
    int p=1;
    int q=0;

    
            
        /*@
          loop invariant a >= 0;
          loop invariant b >= 0;
          loop invariant p >= 1;
          loop invariant a == 0 || b == 0 || (a > 0 && b > 0);
          loop invariant a <= \at(x,Pre) || b <= \at(y,Pre);
          loop invariant p == 1 || p >= 4;
          loop invariant (\at(x,Pre) != 0 && \at(y,Pre) != 0) ==> (a >= 0 && b >= 0 && p >= 1);
          loop invariant (\at(x,Pre) != 0 && \at(y,Pre) != 0) ==> (a == 0 || b == 0 || (a > 0 && b > 0));
          loop invariant (\at(x,Pre) != 0 && \at(y,Pre) != 0) ==> (p >= 1);
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
