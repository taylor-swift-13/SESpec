
/*@
  requires x >= 0;
*/
void foo90(int x,int y){

  int q=0;
  int r=0;

  
            
        /*@
          loop invariant x == \at(x,Pre);
          loop invariant y == \at(y,Pre);
          loop invariant 0 <= q;
          loop invariant 0 <= r;
          loop invariant y * q + r <= x;
          loop invariant x == \at(x,Pre);
          loop invariant y == \at(y,Pre);
          loop invariant (\at(x,Pre) > \at(y,Pre) * 0 + 0) ==> (x >= y * q + r);
          loop invariant (\at(x,Pre) > \at(y,Pre) * 0 + 0) ==> (0 <= q);
          loop invariant (\at(x,Pre) > \at(y,Pre) * 0 + 0) ==> (((r == 0)&&(q == 0)&&(y == \at(y,Pre))&&(x == \at(x,Pre))) || (0 <= r));
          loop invariant (!(\at(x,Pre) > \at(y,Pre) * 0 + 0)) ==> ((r == 0)&&(q == 0)&&(y == \at(y,Pre))&&(x == \at(x,Pre)));
          loop invariant y == \at(y,Pre);
          loop invariant x == \at(x,Pre);
          loop assigns r, q;
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
            

}
