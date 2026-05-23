#include <limits.h>

/*@ requires y1 >= 0 && y2 >= 0;
  decreases y1 + y2;
  assigns \nothing; */
int stub_A(int y1, int y2);

/*@ requires y2 >= 0;
requires y1 >= 0;
requires y1 >= 0 && y2 >= 0;
requires y1 == 0 || y2 == 0 || y1 > 0 && y2 > 0;
ensures \result >= 0;
ensures (y1 > 0 && y2 > 0) ==> \result > 0;
ensures (y1 > 0 && y2 > 0) ==> (\result <= y1 && \result <= y2);
ensures (y1 == 0 || y2 == 0) ==> \result == 0;
ensures (y1 <= 0 || y2 <= 0) ==> \result == 0;
ensures (\result == 0) <==> (y1 <= 0 || y2 <= 0);
assigns \nothing; */
int stub_B(int y1, int y2);

/*@ requires y2 >= 0;
requires y1 >= 0;
requires y1 >= 0 && y2 >= 0;
requires y1 == 0 || y2 == 0 || y1 > 0 && y2 > 0;
ensures \result >= 0;
ensures (y1 > 0 && y2 > 0) ==> \result > 0;
ensures (y1 > 0 && y2 > 0) ==> (\result <= y1 && \result <= y2);
ensures (y1 == 0 || y2 == 0) ==> \result == 0;
ensures (y1 <= 0 || y2 <= 0) ==> \result == 0;
ensures (\result == 0) <==> (y1 <= 0 || y2 <= 0);
assigns \nothing; */
int check_A_implies_B(int y1, int y2) {
    return stub_A(y1, y2);
}

/*@ requires y1 >= 0 && y2 >= 0;
  decreases y1 + y2;
  assigns \nothing; */
int check_B_implies_A(int y1, int y2) {
    return stub_B(y1, y2);
}
