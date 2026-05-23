
int foo340(int n, int z) {
		if (z < 0) {
			z = -z;
		}
		int result = 0;
		
        /*@
          loop invariant 1 <= loop <= z + 1;
          loop invariant n == \at(n,Pre);
          loop invariant z == \at(z,Pre) || z == -\at(z,Pre);
          loop assigns loop, result;
            */
            for (int loop = 1; loop <= z; loop++) {
			if (n % loop == 0) {
				result = result + 1;
			}
		}
            
		return result;
}
