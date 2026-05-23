#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

void foo66(int y) 
/*@

Require emp
Ensure emp
*/{

    int x;

    x = 4 * y;

   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (x == 4 * y) &&
    (x % 4 == 0) &&
    (x <= 4 * y@pre) &&
    (y <= y@pre) &&
    ((4 * y@pre > 0) => (x + 4 * ( y@pre - y ) == 4 * y@pre)) &&
    ((4 * y@pre > 0) => (forall (k:Z), 0 <= k < (y@pre - y) => 4 * (y@pre - k) > 0)) &&
    ((4 * y@pre > 0) => (x == 0 => y == 0)) &&
    ((4 * y@pre > 0) => (x > 0 <=> y > 0)) &&
    ((4 * y@pre > 0) => (x == 4 * (y@pre - (y@pre - y)))) &&
    ((4 * y@pre > 0) => (x == 4 * y@pre - 4 * (y@pre - y))) &&
    ((4 * y@pre > 0) => (x == 4 * y@pre && y == y@pre) || (x < 4 * y@pre && y < y@pre)) &&
    ((4 * y@pre > 0) => (x == 0 => (y == 0 && x == 4 * y@pre - 4 * y@pre))) &&
    ((4 * y@pre > 0) => (x >= 0 && y >= 0)) &&
    ((4 * y@pre > 0) => (x <= 4 * y@pre && y <= y@pre)) &&
    ((4 * y@pre > 0) => (x == 4 * y@pre - 4 * (y@pre - y))) &&
    ((4 * y@pre > 0) => (x == 0 || x >= 4)) &&
    ((4 * y@pre > 0) => (x / 4 == y)) &&
    ((4 * y@pre > 0) => (x == 0 => (y == 0 && y@pre >= 0))) &&
    ((4 * y@pre > 0) => (x % 4 == 0 && y@pre - y >= 0)) &&
    ((4 * y@pre > 0) => (x == 4 * y@pre - 4 * (y@pre - y) && y@pre - y == (4 * y@pre - x) / 4)) &&
    ((4 * y@pre > 0) => (x >= 0 => y >= 0)) &&
    ((4 * y@pre > 0) => (x == 0 <=> y == 0)) &&
    ((4 * y@pre > 0) => (x <= 4 * y@pre && y <= y@pre)) &&
    ((4 * y@pre > 0) => (x == 4 * y && y >= 0 && y <= y@pre)) &&
    ((4 * y@pre > 0) => (x == 4 * y@pre - 4 * (y@pre - y) && y@pre - y <= y@pre)) &&
    ((4 * y@pre > 0) => ((x == 0 && y == 0) || (x > 0 && y > 0))) &&
    ((4 * y@pre > 0) => (x == 4 * (y@pre - (y@pre - y)) && y@pre - y == (y@pre - y))) &&
    ((4 * y@pre > 0) => (x == 4 * y && x >= 0 && x <= 4 * y@pre)) &&
    ((4 * y@pre > 0) => (x == 0 => (x == 4 * y@pre - 4 * y@pre))) &&
    ((4 * y@pre > 0) => (x >= 0 && y >= 0 && y@pre >= y)) &&
    ((4 * y@pre > 0) => (x == 4 * y && y@pre - y == (4 * y@pre - x) / 4)) &&
    ((4 * y@pre > 0) => (x == 0 => y == 0 && x == 4 * y))
    */
    
    while (x > 0) {
        x -= 4;
        y--;
    }

  }