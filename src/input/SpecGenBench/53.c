int foo53(int search, int array[], int array_len);

int foo53(int search, int array[], int array_len) {

	      int c;
        int location;

        for (c = 0; c < array_len; c++) {
          if (array[c] == search) {
	      location = c;
              break;
          }
        }
       if (c == array_len) {
            location = -1;
       }
     return location;
}
