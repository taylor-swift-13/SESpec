/*@ requires x >= 1;
    requires y >= 1;
*/
int main8(int x,int y){
  
  int a,b,p,q,r,s;
 
  a = x;
  b = y;
  p = 1;
  q = 0;
  r = 0;
  s = 1;

 
  /*@
  loop invariant a > 0 && b > 0;
  loop invariant a * s - b * r == x * q - y * p;
  loop invariant p * s - q * r == 1;
  loop invariant x * q - y * p == (a - b) * (p - q) + (r - s) * (q - p);
  loop invariant (a == b) || (a != b);
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
 
  //@ assert((r-s) * y == (q-p) * x);
}