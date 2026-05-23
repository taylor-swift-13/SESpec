
        /*@
        */
        
int foo149(int a) {

		int i = 2;
		int mid = a/2;

		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant \true;
          loop invariant 2 <= i <= mid + 1;
          loop invariant \forall integer k; 2 <= k < i ==> a % k != 0;
          loop assigns i;
            */
            while (i <= mid) {
			if (a%i == 0)
				return 0;
			i++;
		}
            
		return 1;
}
