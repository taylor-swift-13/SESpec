
/*@
predicate mult_inv(int x, int y, int a, int b, int p, int q) = q + a*b*p == x*y;
*/

void foo84(int x,int y){

    int a=x;
    int b=y;
    int p=1;
    int q=0;

    /* >>> LOOP INVARIANT TO FILL <<< */
    
    /*@
      loop invariant \true;
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
