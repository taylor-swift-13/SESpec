
/*@ 
  predicate equal_prefix(const char* pat, const char* txt, integer n) =
    \forall integer k; 0 <= k < n ==> pat[k] == txt[k];
*/

/*@
  requires \valid(&pat[0] + (0..txt-1));
  requires \forall integer i; 0 <= i < txt ==> 0 <= pat[i] <= 100;
  requires txt > 0;
  requires txt < 100;
  requires \valid(&txt[0] + (0..100-1));
  requires \forall integer i; 0 <= i < 100 ==> 0 <= txt[i] <= 100;
  assigns \nothing;
  ensures (\result == 1) <==> (\forall integer k; 0 <= k < (int)strlen(pat) ==> (k < (int)strlen(txt) && pat[k] == txt[k]));
  ensures (\result == 0) <==> (\exists integer k; 0 <= k < (int)strlen(pat) && (k >= (int)strlen(txt) || pat[k] != txt[k]));
  ensures \forall integer k; 0 <= k < (int)strlen(txt) ==> txt[k] == \at(txt[k], Pre);
  ensures \forall integer k; 0 <= k < (int)strlen(pat) ==> pat[k] == \at(pat[k], Pre);
*/
int foo123(const char * pat, const char * txt) {

        int i = 0;

        /* >>> LOOP INVARIANT TO FILL <<< */
        
        /*@
          loop invariant 0 <= i <= (int)strlen(pat);
          loop invariant (i < (int)strlen(pat)) ==> (i < (int)strlen(txt) && equal_prefix(pat, txt, i));
          loop invariant (!(i < (int)strlen(pat))) ==> equal_prefix(pat, txt, (int)strlen(pat));
          loop invariant \forall integer k; 0 <= k < (int)strlen(txt) ==> txt[k] == \at(txt[k], Pre);
          loop invariant \forall integer k; 0 <= k < (int)strlen(pat) ==> pat[k] == \at(pat[k], Pre);
          loop assigns i;
        */
        while(i < ((int)strlen(pat))) {
            if(i >= ((int)strlen(txt)) || pat[i] != txt[i])
                return 0;
            i = i + 1;
        }
            

        return 1;
}
