
/*@
        PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
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
