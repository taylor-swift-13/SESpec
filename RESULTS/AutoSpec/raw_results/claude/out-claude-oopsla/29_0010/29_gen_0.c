int unknown1();
int unknown2();
int unknown3();

void main() {
  int a = 1;
  int b = 1;
  int c = 2;
  int d = 2;
  int x = 3;
  int y = 3;
  /*@
  Looking at this code, I need to generate loop invariants for the outer while loop that will help prove the final assertion `a + c == b + d`.
  
  Let me trace through the logic:
  - Initially: `a=1, b=1, c=2, d=2, x=3, y=3`
  - The relation `a + c == b + d` holds initially (1+2 == 1+2)
  - In each iteration: `x = a + c` and `y = b + d`, so `x == y` always
  - When `(x+y) % 2 == 0`: both `a++` and `d++`, preserving `a+c == b+d`
  - When `(x+y) % 2 != 0`: only `a--`, but this means `x+y` is odd, so `a+c` is odd
  - The inner loop decrements both `c` and `b` equally, preserving `a+c == b+d`
  - After the outer loop, we need `a + c == b + d` to hold
  
  ```c
  loop invariant a + c == b + d;
  loop invariant x == y;
  loop invariant x == a + c;
  loop invariant y == b + d;
  loop assigns a;
  loop assigns b;
  loop assigns c;
  loop assigns d;
  loop assigns x;
  loop assigns y;
  ```
  */
  while (unknown1()) {
    x = a + c;
    y = b + d;
    if ((x + y) % 2 == 0) {
      a++;
      d++;
    } else {
      a--;
    }

    /*@
    loop invariant a + c == b + d;
    loop invariant 0; // loop does not break invariant <= \forall integer k; k;
    loop assigns c;
    loop assigns b;
    */
    while (unknown2()) {
      c--;
      b--;
    }
  }
  // @ assert a + c == b + d;
}