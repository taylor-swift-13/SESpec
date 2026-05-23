
int foo387(int num, int c, int r) {

		int ret = 0;
		
            
        /*@
          loop invariant r <= \at(r,Pre);
          loop invariant 0 <= num || num <= 0;
          loop invariant ret >= 0 || ret <= 0;

          loop invariant (\at(r,Pre) > 0) ==> (ret == ret);
          loop invariant (\at(r,Pre) > 0) ==> (r <= \at(r,Pre));
          loop invariant (\at(r,Pre) > 0) ==> (c == \at(c,Pre));
          loop invariant (\at(r,Pre) > 0) ==> (((ret == 0)&&(r == \at(r,Pre))&&(c == \at(c,Pre))&&(num == \at(num,Pre))) || (ret == ret));
          loop invariant (!(\at(r,Pre) > 0)) ==> ((ret == 0)&&(r == \at(r,Pre))&&(c == \at(c,Pre))&&(num == \at(num,Pre)));
          loop invariant c == \at(c,Pre);
          loop assigns r, num, ret;
            */
            while (r > 0) {
			r -= 1;
			num *= 10;
			ret = num / c;
			num %= c;
		}
            
		return ret;
}
