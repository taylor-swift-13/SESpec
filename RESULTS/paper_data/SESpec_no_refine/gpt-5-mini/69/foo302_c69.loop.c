
/*@
  predicate div3_count(unsigned int l, unsigned int c3, unsigned int ceven_not3, unsigned int crest) =
    l == c3 + ceven_not3 + crest
    && c3 == l / 3
    && ceven_not3 + crest == l - c3
    && ceven_not3 == (l - c3) / 2; 
*/
        
void foo302_c69(unsigned int n) {

    unsigned int j;
    unsigned int i;
    unsigned int k;
    unsigned int l;

    i = 0;
    k = 0;
    j = 0;
    l = 0;

    
            
        /*@
          loop invariant (0 < \at(n,Pre)) ==> (l == i + j + k);
          loop invariant (0 < \at(n,Pre)) ==> (k == l - i - j);
          loop invariant (!(0 < \at(n,Pre))) ==> ((l == 0)&&(k == 0)&&(i == 0)&&(j == 0)&&(n == \at(n,Pre)));
          loop invariant n == \at(n,Pre);
          loop assigns i, j, k, l;
        */
            while (l < n) {
       if ((l % 3) == 0) {
       i = i + 1;
      }
       else if((l % 2) == 0){
       j = j + 1;
      }
       else{
       k = k + 1;
      }
       l = l + 1;
      }
            

  }
