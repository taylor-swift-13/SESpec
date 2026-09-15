

/*@
  requires \valid(&s[0] + (0..100-1));
  requires \forall integer i; 0 <= i < 100 ==> 0 <= s[i] <= 100;
  assigns \nothing;
  ensures \result == 0 || \result == 1;
  ensures \result == 1 ==> \forall integer i; 0 <= i < ((int)strlen(s)) ==> s[i] == s[((int)strlen(s)) - 1 - i];
  ensures \result == 0 ==> \exists integer i; 0 <= i < ((int)strlen(s)) && s[i] != s[((int)strlen(s)) - 1 - i];
*/
int foo122(const char * s) {

        int n = ((int)strlen(s));

        
            
        /*@
          loop invariant 0 <= i <= ((int)strlen(s));
          loop invariant n == ((int)strlen(s));
          loop invariant \forall integer k; 0 <= k < i ==> s[k] == s[n - 1 - k];
          loop invariant \forall integer k; 0 <= k < ((int)strlen(s)) ==> s[k] == \at(s[k], Pre);
          loop assigns i;
        */
        
            /*@
          loop invariant 0 <= i <= ((int)strlen(s));
          loop invariant n == ((int)strlen(s));
          loop invariant \forall integer k; 0 <= k < i ==> s[k] == s[n - 1 - k];
          loop invariant \forall integer k; 0 <= k < ((int)strlen(s)) ==> s[k] == \at(s[k], Pre);
          loop assigns i;
            */
            for(int i = 0; i < ((int)strlen(s)); i++) {
            if(s[i] != s[n - 1 - i]) {
                return 0;
            }
        }
            

        return 1;
}
