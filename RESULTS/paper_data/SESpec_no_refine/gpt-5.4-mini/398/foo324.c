
/*@
  assigns \nothing;
*/
int foo324(int number) {

		int ret = 0;
		
            
        /*@
          loop invariant (\at(number,Pre) > 0) ==> (number >= 0);
          loop invariant (\at(number,Pre) > 0) ==> (ret >= 0);
          loop invariant (\at(number,Pre) > 0) ==> (number <= \at(number,Pre));
          loop invariant (!(\at(number,Pre) > 0)) ==> ((ret == 0)&&(number == \at(number,Pre)));
          loop assigns number, ret;
            */
            while (number > 0) {
			number /= 10;
			ret++;
		}
            
		return ret;
}
