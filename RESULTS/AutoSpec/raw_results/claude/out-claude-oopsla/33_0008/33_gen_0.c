int unknown1();
int unknown2();
int unknown3();

void foo(int k)
{
  int z = k;
  int x = 0;
  int y = 0;

  while(unknown1())
  {
    int c = 0;
    /*@
    loop invariant 0 <= c;
    loop invariant z == k + y - c;
    loop invariant x + y + c == 2 * y;
    loop invariant x >= 0 && y >= 0;
    loop assigns c;
    loop assigns x;
    loop assigns y;
    loop assigns z;
    */
    while(unknown2())
    {
      if(z==k+y-c)
      {
        x++;
        y++;
        c++;
      }else
      {
        x++;
        y--;
        c++;
      }
    }
    while(unknown3())
    {
      x--;
      y--;
    }
    z=k+y;
  }
  // @ assert x==y;
}
