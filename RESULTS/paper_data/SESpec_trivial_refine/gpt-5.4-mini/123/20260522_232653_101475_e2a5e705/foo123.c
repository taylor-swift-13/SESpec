
/*@
*/

/*@
  requires \valid_read_string(pat);
  requires \valid_read_string(txt);
  assigns \nothing;
  ensures \result == 1 ==> \forall integer k; 0 <= k < (int)strlen(pat) ==> pat[k] == txt[k];
  ensures \result == 1 ==> (int)strlen(txt) >= (int)strlen(pat);
  ensures \result == 0 ==> \exists integer k; 0 <= k < (int)strlen(pat) && (k >= (int)strlen(txt) || pat[k] != txt[k]);
  ensures \result == 1 <==> ((int)strlen(txt) >= (int)strlen(pat) && \forall integer k; 0 <= k < (int)strlen(pat) ==> pat[k] == txt[k]);
*/
int foo123(const char * pat, const char * txt) {

        int i = 0;

        /*@
          loop invariant 0 <= i <= (int)strlen(pat);
          loop invariant \forall integer k; 0 <= k < i ==> pat[k] == txt[k];
          loop assigns i;
          loop variant (int)strlen(pat) - i;
        */
        while(i < ((int)strlen(pat))) {
            if(i >= ((int)strlen(txt)) || pat[i] != txt[i])
                return 0;
            i = i + 1;
        }

        return 1;
}
