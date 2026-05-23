
/*@
  predicate PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION = \true;
*/
        
void foo90(int x,int y){

  int q=0;
  int r=0;

            
        /*@
          loop invariant 0 <= q;
          loop invariant 0 <= r;
          loop invariant (y > 0) ==> r < y;

          loop invariant x == \at(x,Pre);
          loop invariant y == \at(y,Pre);

          loop invariant 0 <= q * y + r;

          loop invariant (\exists integer k; 0 <= k && k == q + r); 

          loop invariant q >= 0;
          loop invariant r >= 0 && (y > 0 ==> r < y);
          
          loop invariant (\at(x,Pre) > \at(y,Pre) * 0 + 0) ==> (q >= 0);
          loop invariant (\at(x,Pre) > \at(y,Pre) * 0 + 0) ==> (q == q);
          loop invariant (\at(x,Pre) > \at(y,Pre) * 0 + 0) ==> (((r == 0)&&(q == 0)&&(y == \at(y,Pre))&&(x == \at(x,Pre))) || (r >= 0 && q >= 0));
          loop invariant (!(\at(x,Pre) > \at(y,Pre) * 0 + 0)) ==> ((r == 0)&&(q == 0)&&(y == \at(y,Pre))&&(x == \at(x,Pre)));

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
