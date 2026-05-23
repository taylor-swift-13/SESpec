
/*@
int foo78(int a) {

		int i = 2;
		int mid = a/2;

		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (2 <= \at(a,Pre) / 2) ==> (2 <= i <= \at(a,Pre) / 2 + 1);
          loop invariant (!(2 <= \at(a,Pre) / 2)) ==> ((mid == \at(a,Pre) / 2)&&(i == 2)&&(a == \at(a,Pre)));
          loop invariant mid == \at(a,Pre) / 2;
          loop invariant a == \at(a,Pre);
          loop assigns i;
            */
            while (i <= mid) {
			if (a%i == 0)
				return 0;
			i++;
		}
            
		return 1;
}
