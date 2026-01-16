int unknown1();
int unknown2();


int main(int flag)
{
  int t = 0;
  int s = 0;
  int a = 0;
  int b = 0;
  /*@
  loop invariant s == (a*(a+1))/2;
  loop invariant s <= t;
  loop invariant b * (flag ? a : 0); <= t;
  loop invariant \old(t) <= t && \old(s) <= s && \old(a) <= a;
  loop invariant 0 <= a <= t && 0 <= b <= t && 0 <= s <= t;
  loop invariant t - (flag ? a : 0) <= s * 2;
  loop invariant s >= 0 && t >= 0 && a >= 0 && b >= 0;
  loop invariant a == b;
  loop invariant 0 <= a && 0 <= b && 0 <= s && 0 <= t;
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

