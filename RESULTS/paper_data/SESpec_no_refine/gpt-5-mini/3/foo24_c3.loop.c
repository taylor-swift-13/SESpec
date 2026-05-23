int foo24_c3(int y1, int y2);


int foo24_c3(int y1, int y2) {

        if (y1 <= 0 || y2 <= 0) {
          return 0;
        }
        if (y1 == y2) {
          return y1;
        }
        if (y1 > y2) {
          return foo24_c3(y1 - y2, y2);
        }
        return foo24_c3(y1, y2 - y1);
}