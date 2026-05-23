
        /*@
        predicate suffix_match{L}(const char *pat, const char *txt, integer i) =
          \forall integer k;
            i < k <= (integer)strlen(pat) - 1 ==>
              pat[k] == txt[k - (integer)strlen(pat) + (integer)strlen(txt)];
        */
        

int foo125(const char * pat, const char * txt) {

        int i = ((int)strlen(pat)) - 1;

        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (integer)strlen(txt) >= (integer)strlen(pat);
          loop invariant -1 <= i <= (integer)strlen(pat) - 1;
          loop invariant suffix_match(pat, txt, i);
          loop assigns i, j;
            */
            while(i >= 0) {
	    int j = i - ((int)strlen(pat)) + ((int)strlen(txt));
            if(j < 0 || pat[i] != txt[j])
                return 0;
            i = i - 1;
        }
            

        return 1;
}
