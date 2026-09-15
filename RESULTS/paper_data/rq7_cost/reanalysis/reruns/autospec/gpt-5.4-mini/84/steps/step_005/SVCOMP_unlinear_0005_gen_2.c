int main13(int x,int y){

    int a=x;
    int b=y;
    int p=1;
    int q=0;

    /*@
    loop invariant p > 0;
    loop invariant q >= 0;
    loop invariant a >= 0 && b >= 0;
    loop invariant a <= x && b <= y;
    loop invariant a + b <= x + y;
    loop invariant p % 2 == 1 || p % 2 == 0;
    loop invariant a == 0 || b == 0 || (a > 0 && b > 0);
    loop invariant (a == 0 || b == 0) ==> (a * b == 0);
    loop invariant q >= x || q >= y;
    loop invariant q >= 0 || a == 0 || b == 0;
    loop invariant q == 0 || p >= 1;
    loop invariant p == 4*q || p >= 4;
    loop invariant p == 1 || p >= 1;
    loop invariant p == 1 || p % 4 == 0;
    loop invariant p == 1 || p % 2 == 0;
    loop invariant p % 4 == 1 || p % 4 == 0;
    loop invariant p % 4 == 0 || p == 1;
    loop invariant p % 4 == 0 || p % 4 == 1;
    loop invariant p % 2 == 1 || p % 4 == 0;
    loop invariant p % 2 == 1 || p % 2 == 0;
    loop invariant p % 2 == 0 || p % 2 == 1;
    loop invariant b <= y;
    loop invariant a >= 0 && b >= 0;
    loop invariant a == 0 || b == 0 || (a > 0 && b > 0);
    loop invariant a <= x;
    loop invariant a <= x && b <= y;
    loop invariant a + b <= x + y;
    loop invariant \exists integer m,n; a == x - m && b == y - n;
    loop invariant \exists integer m, n; a == x - m && b == y - n;
    loop invariant 1 <= p;
    loop invariant 0 <= q;
    loop invariant 0 <= p;
    loop invariant 0 <= b;
    loop invariant 0 <= a;
    loop invariant 0 <= a + b;
    loop invariant 0 <= a && 0 <= b;
    loop invariant 0 < p;
    loop invariant (a == 0 || b == 0) || (a > 0 && b > 0);
    loop invariant (a == 0 || b == 0) ==> q >= 0;
    loop invariant (a == 0 || b == 0) ==> (a * b == 0);
    loop assigns q;
    loop assigns p;
    loop assigns b;
    loop assigns a;
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
