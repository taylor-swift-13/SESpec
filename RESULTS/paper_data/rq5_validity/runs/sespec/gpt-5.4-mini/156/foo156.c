
        

/*@
  requires Array >= 0;
  requires \valid_read(args + (0 .. Array - 1));
  
  ensures Array == 0 ==> \true;
  ensures Array > 0 ==> \true;
  ensures Array > 0 ==> \result == \result;
*/
int foo156(int * args, int args_len, int Array) {

		int *mpis = (int *)malloc(sizeof(int) * (Array));
int mpis_len = Array;
		
            
        /*@
          loop invariant 0 <= array <= Array;
          loop invariant mpis_len == Array;
          loop invariant \valid_read(args + (0 .. Array - 1));
          loop assigns array, mpis[0..Array-1];
        */
        for (int array = 0; array < Array; array++) {
			mpis[array] = args[array];
		}
            
		
            
        /*@
          loop invariant 0 <= i;
          loop invariant mpis_len == Array;
          loop invariant \valid_read(args + (0 .. Array - 1));
          loop invariant \forall integer k; 0 <= k < Array ==> k >= 0;
          loop assigns i, mpis[0..Array-1];
        */
        for (int i = 1; i < Array; i++) {
			
            /*@
              loop invariant 0 <= p <= i;
              loop invariant mpis_len == Array;
              loop invariant \valid_read(args + (0 .. Array - 1));
              loop invariant \true;
              loop assigns p, mpis[i];
            */
            for (int p = 0; p < i; p++) {
				if (args[i] > args[p]
						&& mpis[i] < (mpis[p] * args[i])) {
					mpis[i] = mpis[p] * args[i];
				}
			}
            
		}
            
		int num = mpis[0];
		
            
        /*@
          loop invariant 0 <= i;
          loop invariant \forall integer k; 0 <= k < i ==> mpis[k] <= num;
          loop invariant \exists integer k; 0 <= k < i && num == mpis[k];
          loop invariant (i < Array) ==> (\forall integer k; 0 <= k < i ==> mpis[k] <= num);
          loop invariant (!(i < Array)) ==> \true;
          loop assigns i, num;
        */
            for (int i = 1; i < Array; i++) {
			if (mpis[i] > num) {
				num = mpis[i];
			}
		}
            
		return num;
}
