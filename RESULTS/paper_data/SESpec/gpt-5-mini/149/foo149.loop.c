
/* No function-level contract mentioning locals (i, mid). */
/*@
  requires a == \at(a,Pre);
*/
        
int foo149(int a) {

		int i = 2;
		int mid = a/2;

        /*@
          loop invariant i >= 2;
          loop invariant (mid >= 2) ==> i <= mid + 1;
          loop invariant mid == \at(a,Pre) / 2;
          loop invariant a == \at(a,Pre);
          loop invariant (\forall integer k; 2 <= k < i ==> a % k != 0);
          loop invariant (\forall integer k; 2 <= k < i ==> k <= mid);
          loop invariant (i > mid) ==> (\forall integer k; 2 <= k <= mid ==> a % k != 0);
          loop assigns i;
        */
            while (i <= mid) {
			if (a%i == 0)
				return 0;
			i++;
		}
            
		return 1;
}
