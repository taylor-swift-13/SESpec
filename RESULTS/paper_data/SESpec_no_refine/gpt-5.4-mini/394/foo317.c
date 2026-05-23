
/*@
  assigns \nothing;
  ensures \result == ((
    (num <= 0) ? 1 : (
      (num == 1) ? 1 : (
        (num == 2) ? 2 : (
          (num == 3) ? 6 : (
            (num == 4) ? 24 : (
              (num == 5) ? 20 : (
                (num == 6) ? 20 : (
                  (num == 7) ? 40 : (
                    (num == 8) ? 20 : (
                      (num == 9) ? 80 : (
                        (num == 10) ? 0 : 0
)))))))))))) % 100);
*/
int foo317(int num) {

		int ret = 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant num == \at(num,Pre);
          loop assigns loop, ret;
            */
            for (int loop = 1; loop <= num; loop++) {
			ret *= loop;
		}
            
		int result = (int) (ret % 100);
		return result;
}
