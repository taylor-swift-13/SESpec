/*@
  requires a >= 1;
  requires b >= 1;
*/
int hoo33(int a, int b) { 
    int x,y,u,v;
  
    //pre-condition
    x=a;
    y=b;
    u=b;
    v=0;
    
  
    //loop-body
    /*@
    loop invariant x;
    loop invariant x*u + y*v == a * b;
    loop invariant x > 0 && y > 0;
    loop invariant u == b;
    loop invariant 0 <= v;
    loop assigns x;
    loop assigns v;
    /*@;
    */
    while(x>y) {
      x=x-y;
      v=v+u;
    }
  
    //post-condition
    /*@ assert x*u + y*v == a*b; */
  }   