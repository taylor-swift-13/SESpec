
/*@
  requires array_len >= 0;
  requires \valid(&array[0] + (0..array_len-1));
  requires \forall integer i; 0 <= i < array_len ==> 0 <= array[i] <= 100;
  assigns \nothing;
  ensures \result >= 0;
  ensures \forall integer i,j; 0 <= i < j < num ==> array[i] == \at(array[i],Pre) && array[j] == \at(array[j],Pre);
  ensures \forall integer k; 0 <= k < array_len ==> array[k] == \at(array[k],Pre);
*/
int foo244(int * array, int array_len, int num, int p) {

		int ret = 0;
		
            /*@
              loop invariant \forall integer k; 0 <= k < \at(num,Pre) ==> array[k] == \at(array[k], Pre);
              loop invariant ret >= 0;
              loop invariant p == \at(p,Pre);
              loop invariant num == \at(num,Pre);
              loop invariant array_len == \at(array_len,Pre);
              loop invariant array == \at(array,Pre);
              loop assigns ret, index;
            */
            for (int index = 0; index < num; index++) {
			
            /*@
              loop invariant index+1 <= j <= num;
              loop invariant ret >= 0;
              loop assigns ret, j;
            */
            for (int j = index + 1; j < num; j++) {
				if (array[index] + array[j] == p) {
					ret++;
				}
			}
            
		}
            
		return ret;
}
