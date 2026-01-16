/*@ requires x >= 1;
    requires y >= 1;
*/
int main6(int x,int y){
  
  int a,b,p,q,r,s;
 
  a = x;
  b = y;
  p = 1;
  q = 0;
  r = 0;
  s = 1;

 
  /*@
  loop invariant a > 0 && b > 0;
  loop invariant x*p + y*r == a;
  loop invariant x*q + y*s == b;
  loop invariant p*s - q*r == 1 || p*s - q*r == -1;
  loop invariant p == (p == p) && q == (q == q);  // (This is redundant, can omit)
  loop assigns a, b, p, q, r, s;
  */
  while(a!=b){
      if (a>b) {
         a = a-b;
         p = p-q;
         r = r-s;
      }
      else {
         b = b-a;
         q = q-p;
         s = s-r;
      }
  }
 
  //@ assert(a == y*r + x*p);
 
}