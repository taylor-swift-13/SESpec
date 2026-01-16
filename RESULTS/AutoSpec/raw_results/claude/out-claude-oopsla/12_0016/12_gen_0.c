int unknown1();
int unknown2();


int main(int flag)
{
  int t = 0;
  int s = 0;
  int a = 0;
  int b = 0;
  /*@
  loop invariant s == a * (a + 1) / 2;
  loop invariant flag ? (t <= 2 * s) : (t == s);
  loop invariant a == b;
  loop assigns t;
  loop assigns s;
  loop assigns b;
  loop assigns a;
  */
  while(unknown1()) {
    a++;
    b++;
    s += a;
    t += b;
    if(flag) {
      t += a;
    }
  } 
  //2s >= t
  int x = 1;
  if(flag) {
    x = t - 2*s + 2;
  }
  //x <= 2
  int y = 0;
  /*@
  Looking at this problem, I need to generate loop invariants for the second while loop (the one with the INFILL marker).
  
  Let me analyze the loop:
  - Before the loop: `x = 1` if `!flag`, or `x = t - 2*s + 2` if `flag`
  - From the first loop's invariants: if `flag`, then `t <= 2*s`, which means `t - 2*s <= 0`, so `x <= 2` when `flag` is true
  - Therefore, `x <= 2` always holds before the second loop
  - Loop condition: `y <= x`
  - Loop body: `y` increases by either 1 or 2
  - Post-condition to prove: `y <= 4`
  
  The loop invariants should capture:
  1. The relationship between `y` and `x`
  2. Upper bounds on `y` and `x`
  3. The fact that `y` increases monotonically
  
  ```c
  loop invariant y <= x + 2;
  loop invariant x <= 2;
  loop invariant 0 <= y;
  loop assigns y;
  ```
  */
  while(y <= x){
    if(unknown2()) 
       y++;
    else 
       y += 2;
  }
  // @ assert y <= 4;
}

