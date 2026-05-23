
/*@
  ensures \result == (\at(num,Pre) <= 1 ? 1 : \at(num,Pre));
  assigns \nothing;
*/
int foo151(int num) {

        int first = 1;

        /*@
          loop invariant 1 <= first;
          loop invariant num == \at(num,Pre);
          loop invariant (c <= \at(num,Pre)) ==> (first == pow(c - 1, c - 1));
          loop invariant (!(c <= \at(num,Pre))) ==> ((first == 1)&&(num == \at(num,Pre)));
          loop assigns c, first;
        */
        for (int c = 2; c <= num; c++) {
			first *= c;
		}

		int result = 0;

        /*@
          loop invariant first >= 0;
          loop invariant 0 <= result <= 9;
          loop invariant first >= 0;
          loop assigns result, first;
        */
            /*@
          loop invariant (!(first > 0)) ==> ();
          loop assigns result, first;
            */
            while (first > 0) {
			result = first % 10;
			first /= 10;
		}

		return result;
}
