


void foo66(int y) {

    int x;

    x = 4 * y;

    /*@
      loop invariant x == 4 * y;
      loop invariant x % 4 == 0;
      loop invariant x <= 4 * \at(y,Pre);
      loop invariant y <= \at(y,Pre);
      loop invariant (4 * \at(y,Pre) > 0) ==> (x + 4 * ( \at(y,Pre) - y ) == 4 * \at(y,Pre));
      loop invariant (4 * \at(y,Pre) > 0) ==> (\forall integer k; 0 <= k < (\at(y,Pre) - y) ==> 4 * (\at(y,Pre) - k) > 0);
      loop invariant (4 * \at(y,Pre) > 0) ==> (x == 0 ==> y == 0);
      loop invariant (4 * \at(y,Pre) > 0) ==> (x > 0 <==> y > 0);
      loop invariant (4 * \at(y,Pre) > 0) ==> (x == 4 * (\at(y,Pre) - (\at(y,Pre) - y)));
      loop invariant (4 * \at(y,Pre) > 0) ==> (x == 4 * \at(y,Pre) - 4 * (\at(y,Pre) - y));
      loop invariant (4 * \at(y,Pre) > 0) ==> (x == 4 * \at(y,Pre) && y == \at(y,Pre)) || (x < 4 * \at(y,Pre) && y < \at(y,Pre));
      loop invariant (4 * \at(y,Pre) > 0) ==> (x == 0 ==> (y == 0 && x == 4 * \at(y,Pre) - 4 * \at(y,Pre)));
      loop invariant (4 * \at(y,Pre) > 0) ==> (x >= 0 && y >= 0);
      loop invariant (4 * \at(y,Pre) > 0) ==> (x <= 4 * \at(y,Pre) && y <= \at(y,Pre));
      loop invariant (4 * \at(y,Pre) > 0) ==> (x == 4 * \at(y,Pre) - 4 * (\at(y,Pre) - y));
      loop invariant (4 * \at(y,Pre) > 0) ==> (x == 0 || x >= 4);
      loop invariant (4 * \at(y,Pre) > 0) ==> (x / 4 == y);
      loop invariant (4 * \at(y,Pre) > 0) ==> (x == 0 ==> (y == 0 && \at(y,Pre) >= 0));
      loop invariant (4 * \at(y,Pre) > 0) ==> (x % 4 == 0 && \at(y,Pre) - y >= 0);
      loop invariant (4 * \at(y,Pre) > 0) ==> (x == 4 * \at(y,Pre) - 4 * (\at(y,Pre) - y) && \at(y,Pre) - y == (4 * \at(y,Pre) - x) / 4);
      loop invariant (4 * \at(y,Pre) > 0) ==> (x >= 0 ==> y >= 0);
      loop invariant (4 * \at(y,Pre) > 0) ==> (x == 0 <==> y == 0);
      loop invariant (4 * \at(y,Pre) > 0) ==> (x <= 4 * \at(y,Pre) && y <= \at(y,Pre));
      loop invariant (4 * \at(y,Pre) > 0) ==> (x == 4 * y && y >= 0 && y <= \at(y,Pre));
      loop invariant (4 * \at(y,Pre) > 0) ==> (x == 4 * \at(y,Pre) - 4 * (\at(y,Pre) - y) && \at(y,Pre) - y <= \at(y,Pre));
      loop invariant (4 * \at(y,Pre) > 0) ==> ((x == 0 && y == 0) || (x > 0 && y > 0));
      loop invariant (4 * \at(y,Pre) > 0) ==> (x == 4 * (\at(y,Pre) - (\at(y,Pre) - y)) && \at(y,Pre) - y == (\at(y,Pre) - y));
      loop invariant (4 * \at(y,Pre) > 0) ==> (x == 4 * y && x >= 0 && x <= 4 * \at(y,Pre));
      loop invariant (4 * \at(y,Pre) > 0) ==> (x == 0 ==> (x == 4 * \at(y,Pre) - 4 * \at(y,Pre)));
      loop invariant (4 * \at(y,Pre) > 0) ==> (x >= 0 && y >= 0 && \at(y,Pre) >= y);
      loop invariant (4 * \at(y,Pre) > 0) ==> (x == 4 * y && \at(y,Pre) - y == (4 * \at(y,Pre) - x) / 4);
      loop invariant (4 * \at(y,Pre) > 0) ==> (x == 0 ==> y == 0 && x == 4 * y);
      loop assigns x, y;
    */
    while (x > 0) {
        x -= 4;
        y--;
    }
}
