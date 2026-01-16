/*@ requires x>0;
    requires y>0;
*/
int main2(int x,int y){
 
  int q=0;
  int r=0;
  
  /*@
  Looking at this verification problem, I need to generate loop invariants that will help prove `q == x / y` after the loop terminates.
  
  The loop condition is `x > y * q + r`, and the loop maintains a relationship where `y * q + r` approaches `x`. When the loop exits, we'll have `x <= y * q + r`, and combined with the invariants, this should establish the division property.
  
  ```c
  loop invariant 0 <= r < y;
  loop invariant y * q + r <= x;
  loop invariant x < y * (q + 1);
  loop assigns q;
  loop assigns r;
  ```
  */
  while(x > y * q + r) {
      if (r == y - 1){
          r = 0;
          q += 1;
      }
      else{
          r += 1;
      }

  }
  
  // @ assert q == x / y;
  
}
