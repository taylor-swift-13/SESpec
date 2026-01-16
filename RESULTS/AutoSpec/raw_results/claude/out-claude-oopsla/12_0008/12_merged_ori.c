int unknown1();
int unknown2();


int main(int flag)
{
  int t = 0;
  int s = 0;
  int a = 0;
  int b = 0;
  /*@
  loop invariant t == s + (flag ? a*a : 0);
  loop invariant t <= 3 * s;
  loop invariant a == b >= 0;
  loop invariant a * b <= t;
  loop invariant 2 * s - a * (flag ? a : 0) <= t;
  loop invariant 0 <= t - 2 * s + a * (flag ? a : 0);
  loop invariant 0 <= s;
  loop invariant t <= 2*s + a*(flag ? a : 0);
  loop invariant t - a*(flag ? a : 0) <= 2*s;
  loop invariant s == a*(a+1)/2;
  loop invariant b*(b+1)/2 <= t;
  loop invariant a >= 0 && b >= 0;
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
  loop invariant 0 <= y;
  loop assigns y;
  */
  while(y <= x){
    if(unknown2()) 
       y++;
    else 
       y += 2;
  }
  // @ assert y <= 4;
}

