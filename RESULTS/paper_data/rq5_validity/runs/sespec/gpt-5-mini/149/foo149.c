int foo149(int a);


/*@
ensures \exists integer i_62, mid_61; (i_62 > mid_61) && (i_62 >= 2) && (mid_61 >= 2 ==> i_62 <= mid_61 + 1) && (mid_61 == a / 2) && (\forall integer k_50; 2 <= k_50 && k_50 < i_62 ==> a % k_50 != 0) && (\forall integer k_51; 2 <= k_51 && k_51 < i_62 ==> k_51 <= mid_61) && (i_62 > mid_61 ==> (\forall integer k_52; 2 <= k_52 && k_52 <= mid_61 ==> a % k_52 != 0)) ==> (\result == 1);
ensures \exists integer i_62, mid_61; (a % i_62 == 0) && (i_62 <= mid_61) && (i_62 >= 2) && (mid_61 >= 2 ==> i_62 <= mid_61 + 1) && (mid_61 == a / 2) && (\forall integer k_50; 2 <= k_50 && k_50 < i_62 ==> a % k_50 != 0) && (\forall integer k_51; 2 <= k_51 && k_51 < i_62 ==> k_51 <= mid_61) && (i_62 > mid_61 ==> (\forall integer k_52; 2 <= k_52 && k_52 <= mid_61 ==> a % k_52 != 0)) ==> (\result == 0);

assigns \nothing;
*/

int foo149(int a) 
{

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