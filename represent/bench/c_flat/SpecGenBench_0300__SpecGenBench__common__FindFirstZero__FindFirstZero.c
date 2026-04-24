int FindFirstZero(int * x, int x_len);

int FindFirstZero(int * x, int x_len) {

         	assert x_len >= 0;
         	if (x_len == 0) {
            		return -1;
        	} else {
            		int index = 0;

            		while (x_len - index > 0 && x[index] != 0) {
                		index = index + 1;
            		}
            		if (x_len - index == 0) {
               			index = -1;
            		}
            	return index;
        	}
}
