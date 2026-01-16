/*@
requires n >= 0;
*/
int main20(int n){
    // variable declarations

    //precondition
    int a=0;
    int s=1;
    int t=1;

    // loop body
    /*@
    loop invariant t == 2 * a + 1;
    loop invariant s == a * a + a + 1;
    loop invariant s <= n + t;
    loop invariant 1 <= s;
    loop invariant 0 <= a;
    loop assigns t;
    loop assigns s;
    loop assigns a;
    */
    while(s <= n){
     a=a+1;
     t=t+2;
     s=s+t;
    }

    // post-condition
    //@ assert( n < (a + 1) * (a + 1));
}