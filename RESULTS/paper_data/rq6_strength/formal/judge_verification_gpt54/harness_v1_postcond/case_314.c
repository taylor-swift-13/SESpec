#include <limits.h>



/*@requires radius >= 0;
  requires radius == 0;
  assigns \nothing;
  
  ensures \result >= 0;
  ensures radius > 0 ==> \result >= 0;
  ensures \result >= 0;*/
int stub_A(int radius);

/*@loop invariant rectangles == 0 || rectangles > 0;
            loop invariant diameterSquare == diameter * diameter;
            loop invariant diameterSquare == 4 * radius * radius;
            loop invariant diameter == 2 * radius;
            loop invariant b <= 2 * radius + 1;
            loop invariant a >= 1 && a <= 2 * radius;
            loop invariant a <= 2 * radius;
            loop invariant a <= 2 * radius + 1;
            loop invariant \forall integer l; 1 <= l < b ==> rectangles >= 0;
            loop invariant \forall integer l; 1 <= l < b ==> 0 <= rectangles;
            loop invariant \forall integer l; 1 <= l < b ==> (a * a + l * l) > diameterSquare || rectangles >= 0;
            loop invariant \forall integer l; 1 <= l < b ==> (a * a + l * l) <= diameterSquare ==> rectangles >= 0;
            loop invariant \forall integer l; 1 <= l < b ==> (a * a + l * l > diameterSquare) || rectangles >= 0;
            loop invariant \forall integer l; 1 <= l < b ==> (a * a + l * l > diameterSquare) || (a * a + l * l <= diameterSquare);
            loop invariant \forall integer l; 1 <= l < b ==> (a * a + l * l > diameterSquare || rectangles >= 0);
            loop invariant \forall integer l; 1 <= l < b ==> (a * a + l * l > diameterSquare || a >= 1);
            loop invariant \forall integer l; 1 <= l < b ==> (a * a + l * l > diameterSquare || a > 0);
            loop invariant \forall integer l; 1 <= l < b ==> (a * a + l * l > diameterSquare || a * a + l * l <= diameterSquare);
            loop invariant \forall integer l; 1 <= l < b ==> (a * a + l * l > diameterSquare || (a * a + l * l <= diameterSquare && rectangles >= 0));
            loop invariant \forall integer l; 1 <= l < b ==> (a * a + l * l <= diameterSquare || rectangles >= 0);
            loop invariant \forall integer l; 1 <= l < b ==> (a * a + l * l <= diameterSquare || a >= 1);
            loop invariant \forall integer l; 1 <= l < b ==> (a * a + l * l <= diameterSquare || a > 0);
            loop invariant \forall integer l; 1 <= l < b ==> (a * a + l * l <= diameterSquare ==> rectangles >= 1);
            loop invariant \forall integer l; 1 <= l < b ==> (a * a + l * l <= diameterSquare ==> rectangles >= 0);
            loop invariant \forall integer l; 1 <= l < b ==> ((a * a + l * l) > diameterSquare || rectangles >= 0);
            loop invariant \forall integer l; 1 <= l < b ==> ((a * a + l * l) > diameterSquare || (a * a + l * l) <= diameterSquare);
            loop invariant \forall integer l; 1 <= l < b ==> ((a * a + l * l) > diameterSquare ==> rectangles >= 0);
            loop invariant \forall integer l; 1 <= l < b ==> ((a * a + l * l) <= diameterSquare ==> rectangles >= 0);
            loop invariant \forall integer k; 1 <= k < b ==> (a * a + k * k > diameterSquare) || (rectangles >= 0);
            loop invariant \forall integer k; 1 <= k < a ==> rectangles >= 0;
            loop invariant \forall integer k; 1 <= k < a ==> diameterSquare == diameter * diameter;
            loop invariant \forall integer k; 1 <= k < a ==> diameterSquare == 4 * radius * radius;
            loop invariant \forall integer k; 1 <= k < a ==> diameter == 2 * radius;
            loop invariant \forall integer k; 1 <= k < a ==> a <= 2 * radius + 1;
            loop invariant \forall integer k; 1 <= k < a ==> \forall integer l; 1 <= l <= 2 * radius ==> (k*k + l*l <= diameterSquare ==> 0 <= rectangles);
            loop invariant \forall integer k; 1 <= k < a ==> \forall integer l; 1 <= l <= 2 * radius ==> (k * k + l * l > diameterSquare) || (k * k + l * l <= diameterSquare);
            loop invariant \forall integer k; 1 <= k < a ==> \forall integer l; 1 <= l <= 2 * radius ==> (k * k + l * l > diameterSquare || rectangles >= 0);
            loop invariant \forall integer k; 1 <= k < a ==> \forall integer l; 1 <= l <= 2 * radius ==> (k * k + l * l > diameterSquare || k * k + l * l <= diameterSquare);
            loop invariant \forall integer k; 1 <= k < a ==> \forall integer l; 1 <= l <= 2 * radius ==> (k * k + l * l > diameterSquare || (k * k + l * l <= diameterSquare && rectangles >= 0));
            loop invariant \forall integer k; 1 <= k < a ==> \forall integer l; 1 <= l <= 2 * radius ==> (k * k + l * l <= diameterSquare ==> rectangles >= 0);
            loop invariant \forall integer k; 1 <= k < a ==> \forall integer l; 1 <= l <= 2 * radius ==> ((k * k + l * l) <= diameterSquare ==> rectangles >= 0);
            loop invariant \forall integer k; 1 <= k < a ==> \forall integer l; 1 <= l < b ==> rectangles >= 0;
            loop invariant \forall integer k; 1 <= k < a ==> \forall integer l; 1 <= l < b ==> (k * k + l * l > diameterSquare || rectangles >= 0);
            loop invariant \forall integer k; 1 <= k < a ==> \forall integer l; 1 <= l < b ==> (k * k + l * l <= diameterSquare ==> rectangles >= 0);
            loop invariant \forall integer k; 1 <= k < a ==> \forall integer l; 1 <= l < b ==> ((k * k + l * l) <= diameterSquare ==> rectangles >= 0);
            loop invariant \forall integer k; 1 <= k < a ==> 1 <= b <= 2 * radius + 1;
            loop invariant \forall integer k; 1 <= k < a ==> 0 <= rectangles;
            loop invariant \forall integer k; 1 <= k < a ==> 0 <= b;
            loop invariant \forall integer k; 1 <= k < a ==> 0 <= a;
            loop invariant 1 <= b;
            loop invariant 1 <= a;
            loop invariant 0 <= rectangles;
            loop invariant 0 <= b;
            loop invariant 0 <= b * b;
            loop invariant 0 <= a;
            loop invariant 0 <= a * a;
            loop invariant 0 < a;
            loop assigns rectangles;
            loop assigns b;*/
int stub_B(int radius);

/*@loop invariant rectangles == 0 || rectangles > 0;
            loop invariant diameterSquare == diameter * diameter;
            loop invariant diameterSquare == 4 * radius * radius;
            loop invariant diameter == 2 * radius;
            loop invariant b <= 2 * radius + 1;
            loop invariant a >= 1 && a <= 2 * radius;
            loop invariant a <= 2 * radius;
            loop invariant a <= 2 * radius + 1;
            loop invariant \forall integer l; 1 <= l < b ==> rectangles >= 0;
            loop invariant \forall integer l; 1 <= l < b ==> 0 <= rectangles;
            loop invariant \forall integer l; 1 <= l < b ==> (a * a + l * l) > diameterSquare || rectangles >= 0;
            loop invariant \forall integer l; 1 <= l < b ==> (a * a + l * l) <= diameterSquare ==> rectangles >= 0;
            loop invariant \forall integer l; 1 <= l < b ==> (a * a + l * l > diameterSquare) || rectangles >= 0;
            loop invariant \forall integer l; 1 <= l < b ==> (a * a + l * l > diameterSquare) || (a * a + l * l <= diameterSquare);
            loop invariant \forall integer l; 1 <= l < b ==> (a * a + l * l > diameterSquare || rectangles >= 0);
            loop invariant \forall integer l; 1 <= l < b ==> (a * a + l * l > diameterSquare || a >= 1);
            loop invariant \forall integer l; 1 <= l < b ==> (a * a + l * l > diameterSquare || a > 0);
            loop invariant \forall integer l; 1 <= l < b ==> (a * a + l * l > diameterSquare || a * a + l * l <= diameterSquare);
            loop invariant \forall integer l; 1 <= l < b ==> (a * a + l * l > diameterSquare || (a * a + l * l <= diameterSquare && rectangles >= 0));
            loop invariant \forall integer l; 1 <= l < b ==> (a * a + l * l <= diameterSquare || rectangles >= 0);
            loop invariant \forall integer l; 1 <= l < b ==> (a * a + l * l <= diameterSquare || a >= 1);
            loop invariant \forall integer l; 1 <= l < b ==> (a * a + l * l <= diameterSquare || a > 0);
            loop invariant \forall integer l; 1 <= l < b ==> (a * a + l * l <= diameterSquare ==> rectangles >= 1);
            loop invariant \forall integer l; 1 <= l < b ==> (a * a + l * l <= diameterSquare ==> rectangles >= 0);
            loop invariant \forall integer l; 1 <= l < b ==> ((a * a + l * l) > diameterSquare || rectangles >= 0);
            loop invariant \forall integer l; 1 <= l < b ==> ((a * a + l * l) > diameterSquare || (a * a + l * l) <= diameterSquare);
            loop invariant \forall integer l; 1 <= l < b ==> ((a * a + l * l) > diameterSquare ==> rectangles >= 0);
            loop invariant \forall integer l; 1 <= l < b ==> ((a * a + l * l) <= diameterSquare ==> rectangles >= 0);
            loop invariant \forall integer k; 1 <= k < b ==> (a * a + k * k > diameterSquare) || (rectangles >= 0);
            loop invariant \forall integer k; 1 <= k < a ==> rectangles >= 0;
            loop invariant \forall integer k; 1 <= k < a ==> diameterSquare == diameter * diameter;
            loop invariant \forall integer k; 1 <= k < a ==> diameterSquare == 4 * radius * radius;
            loop invariant \forall integer k; 1 <= k < a ==> diameter == 2 * radius;
            loop invariant \forall integer k; 1 <= k < a ==> a <= 2 * radius + 1;
            loop invariant \forall integer k; 1 <= k < a ==> \forall integer l; 1 <= l <= 2 * radius ==> (k*k + l*l <= diameterSquare ==> 0 <= rectangles);
            loop invariant \forall integer k; 1 <= k < a ==> \forall integer l; 1 <= l <= 2 * radius ==> (k * k + l * l > diameterSquare) || (k * k + l * l <= diameterSquare);
            loop invariant \forall integer k; 1 <= k < a ==> \forall integer l; 1 <= l <= 2 * radius ==> (k * k + l * l > diameterSquare || rectangles >= 0);
            loop invariant \forall integer k; 1 <= k < a ==> \forall integer l; 1 <= l <= 2 * radius ==> (k * k + l * l > diameterSquare || k * k + l * l <= diameterSquare);
            loop invariant \forall integer k; 1 <= k < a ==> \forall integer l; 1 <= l <= 2 * radius ==> (k * k + l * l > diameterSquare || (k * k + l * l <= diameterSquare && rectangles >= 0));
            loop invariant \forall integer k; 1 <= k < a ==> \forall integer l; 1 <= l <= 2 * radius ==> (k * k + l * l <= diameterSquare ==> rectangles >= 0);
            loop invariant \forall integer k; 1 <= k < a ==> \forall integer l; 1 <= l <= 2 * radius ==> ((k * k + l * l) <= diameterSquare ==> rectangles >= 0);
            loop invariant \forall integer k; 1 <= k < a ==> \forall integer l; 1 <= l < b ==> rectangles >= 0;
            loop invariant \forall integer k; 1 <= k < a ==> \forall integer l; 1 <= l < b ==> (k * k + l * l > diameterSquare || rectangles >= 0);
            loop invariant \forall integer k; 1 <= k < a ==> \forall integer l; 1 <= l < b ==> (k * k + l * l <= diameterSquare ==> rectangles >= 0);
            loop invariant \forall integer k; 1 <= k < a ==> \forall integer l; 1 <= l < b ==> ((k * k + l * l) <= diameterSquare ==> rectangles >= 0);
            loop invariant \forall integer k; 1 <= k < a ==> 1 <= b <= 2 * radius + 1;
            loop invariant \forall integer k; 1 <= k < a ==> 0 <= rectangles;
            loop invariant \forall integer k; 1 <= k < a ==> 0 <= b;
            loop invariant \forall integer k; 1 <= k < a ==> 0 <= a;
            loop invariant 1 <= b;
            loop invariant 1 <= a;
            loop invariant 0 <= rectangles;
            loop invariant 0 <= b;
            loop invariant 0 <= b * b;
            loop invariant 0 <= a;
            loop invariant 0 <= a * a;
            loop invariant 0 < a;
            loop assigns rectangles;
            loop assigns b;*/
int check_A_implies_B(int radius) {
    return stub_A(radius);
}

/*@requires radius >= 0;
  requires radius == 0;
  assigns \nothing;
  
  ensures \result >= 0;
  ensures radius > 0 ==> \result >= 0;
  ensures \result >= 0;*/
int check_B_implies_A(int radius) {
    return stub_B(radius);
}
