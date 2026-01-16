/*@
requires x>=1 && y>=1;
*/
int main13(int x,int y){
   
    int a=x;
    int b=y;
    int p=1;
    int q=0;

    // loop body
    /*@
    loop invariant a >= 0 && b >= 0;
    loop invariant p == 4 * (((x / (a * b == 0 ? 1 : 1)) / (b != 0 ? 1 : 1)) ? 1 : 1) || p >= 1;
    loop invariant q + a * b * p == x * y;
    loop invariant p >= 1;
    loop assigns a;
    loop assigns b;
    loop assigns p;
    loop assigns q;
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
    // @ assert q == x*y;
}
