#include <limits.h>



/*@requires \valid(&x[0] + (0..x_len-1));
  requires \forall integer i; 0 <= i < x_len ==> 0 <= x[i] <= 100;
  requires \valid(&y[0] + (0..y_len-1));
  requires \forall integer i; 0 <= i < y_len ==> 0 <= y[i] <= 100;
  assigns \nothing;
  ensures x_len == \old(x_len);
  ensures y_len == \old(y_len);
  ensures \forall integer i; 0 <= i < x_len ==> x[i] == \old(x[i]);
  ensures \forall integer i; 0 <= i < y_len ==> y[i] == \old(y[i]);
  ensures \result == 1 ==> (\old(x_len) == \old(y_len) && \forall integer i; 0 <= i < \old(x_len) ==> \old(x[i]) == \old(y[\old(x_len) - 1 - i]));
  ensures \result == 0 ==> (\old(x_len) != \old(y_len) || \exists integer i; 0 <= i < \old(x_len) && \old(x[i]) != \old(y[\old(x_len) - 1 - i]));
  ensures 0 <= \result <= 1;*/
int stub_A(int * x, int x_len, int * y, int y_len);

/*@loop invariant \forall integer k; index <= k < x_len ==> k < x_len;
        loop invariant x_len == y_len;
        loop invariant index == x_len || x[index] == y[x_len - 1 - index] || x[index] != y[x_len - 1 - index];
        loop invariant index == x_len || x[index] != y[x_len - 1 - index] || x[index] == y[x_len - 1 - index];
        loop invariant index == x_len ==> \forall integer k; 0 <= k < x_len ==> x[k] == y[x_len - 1 - k];
        loop invariant index == 0 || y[y_len - index] == x[index - 1];
        loop invariant index == 0 || y[y_len - 1 - (index - 1)] == x[index - 1];
        loop invariant index == 0 || y[x_len - index] == x[index - 1];
        loop invariant index == 0 || y[x_len - 1 - (index - 1)] == x[index - 1];
        loop invariant index == 0 || x[index-1] == y[x_len - index];
        loop invariant index == 0 || x[index - 1] == y[y_len - index];
        loop invariant index == 0 || x[index - 1] == y[y_len - 1 - (index - 1)];
        loop invariant index == 0 || x[index - 1] == y[x_len - index];
        loop invariant index == 0 || x[index - 1] == y[x_len - 1 - (index - 1)];
        loop invariant index == 0 || x[index - 1] != y[x_len - index] || x[index - 1] == y[x_len - index];
        loop invariant index == 0 || x[index - 1] != y[x_len - 1 - index] || x[index - 1] == y[x_len - 1 - index];
        loop invariant index <= x_len ==> x_len - 1 - index >= -1;
        loop invariant index <= x_len ==> x_len - 1 - index < x_len;
        loop invariant index < x_len ==> x_len - 1 - index < x_len;
        loop invariant index < x_len ==> x[index] == y[x_len - 1 - index] || x[index] != y[x_len - 1 - index];
        loop invariant index < x_len ==> x[index] != y[x_len - 1 - index] || x[index] == y[x_len - 1 - index];
        loop invariant \forall integer k; index <= k < x_len ==> x[k] == x[k];
        loop invariant \forall integer k; index <= k < x_len ==> 0 <= k < x_len;
        loop invariant \forall integer k; 0 <= k < index ==> y[y_len - 1 - k] == x[k];
        loop invariant \forall integer k; 0 <= k < index ==> y[x_len - 1 - k] == x[k];
        loop invariant \forall integer k; 0 <= k < index ==> x[k] == y[y_len - 1 - k];
        loop invariant \forall integer k; 0 <= k < index ==> x[k] == y[x_len - 1 - k];
        loop invariant \forall integer k; 0 <= k < index ==> x[k] != y[x_len - 1 - k] || x[k] == y[x_len - 1 - k];
        loop invariant \forall integer k; 0 <= k < index ==> x[k] != y[x_len - 1 - k] ==> \false;
        loop invariant 0 <= index;
        loop assigns index;*/
int stub_B(int * x, int x_len, int * y, int y_len);

/*@loop invariant \forall integer k; index <= k < x_len ==> k < x_len;
        loop invariant x_len == y_len;
        loop invariant index == x_len || x[index] == y[x_len - 1 - index] || x[index] != y[x_len - 1 - index];
        loop invariant index == x_len || x[index] != y[x_len - 1 - index] || x[index] == y[x_len - 1 - index];
        loop invariant index == x_len ==> \forall integer k; 0 <= k < x_len ==> x[k] == y[x_len - 1 - k];
        loop invariant index == 0 || y[y_len - index] == x[index - 1];
        loop invariant index == 0 || y[y_len - 1 - (index - 1)] == x[index - 1];
        loop invariant index == 0 || y[x_len - index] == x[index - 1];
        loop invariant index == 0 || y[x_len - 1 - (index - 1)] == x[index - 1];
        loop invariant index == 0 || x[index-1] == y[x_len - index];
        loop invariant index == 0 || x[index - 1] == y[y_len - index];
        loop invariant index == 0 || x[index - 1] == y[y_len - 1 - (index - 1)];
        loop invariant index == 0 || x[index - 1] == y[x_len - index];
        loop invariant index == 0 || x[index - 1] == y[x_len - 1 - (index - 1)];
        loop invariant index == 0 || x[index - 1] != y[x_len - index] || x[index - 1] == y[x_len - index];
        loop invariant index == 0 || x[index - 1] != y[x_len - 1 - index] || x[index - 1] == y[x_len - 1 - index];
        loop invariant index <= x_len ==> x_len - 1 - index >= -1;
        loop invariant index <= x_len ==> x_len - 1 - index < x_len;
        loop invariant index < x_len ==> x_len - 1 - index < x_len;
        loop invariant index < x_len ==> x[index] == y[x_len - 1 - index] || x[index] != y[x_len - 1 - index];
        loop invariant index < x_len ==> x[index] != y[x_len - 1 - index] || x[index] == y[x_len - 1 - index];
        loop invariant \forall integer k; index <= k < x_len ==> x[k] == x[k];
        loop invariant \forall integer k; index <= k < x_len ==> 0 <= k < x_len;
        loop invariant \forall integer k; 0 <= k < index ==> y[y_len - 1 - k] == x[k];
        loop invariant \forall integer k; 0 <= k < index ==> y[x_len - 1 - k] == x[k];
        loop invariant \forall integer k; 0 <= k < index ==> x[k] == y[y_len - 1 - k];
        loop invariant \forall integer k; 0 <= k < index ==> x[k] == y[x_len - 1 - k];
        loop invariant \forall integer k; 0 <= k < index ==> x[k] != y[x_len - 1 - k] || x[k] == y[x_len - 1 - k];
        loop invariant \forall integer k; 0 <= k < index ==> x[k] != y[x_len - 1 - k] ==> \false;
        loop invariant 0 <= index;
        loop assigns index;*/
int check_A_implies_B(int * x, int x_len, int * y, int y_len) {
    return stub_A(x, x_len, y, y_len);
}

/*@requires \valid(&x[0] + (0..x_len-1));
  requires \forall integer i; 0 <= i < x_len ==> 0 <= x[i] <= 100;
  requires \valid(&y[0] + (0..y_len-1));
  requires \forall integer i; 0 <= i < y_len ==> 0 <= y[i] <= 100;
  assigns \nothing;
  ensures x_len == \old(x_len);
  ensures y_len == \old(y_len);
  ensures \forall integer i; 0 <= i < x_len ==> x[i] == \old(x[i]);
  ensures \forall integer i; 0 <= i < y_len ==> y[i] == \old(y[i]);
  ensures \result == 1 ==> (\old(x_len) == \old(y_len) && \forall integer i; 0 <= i < \old(x_len) ==> \old(x[i]) == \old(y[\old(x_len) - 1 - i]));
  ensures \result == 0 ==> (\old(x_len) != \old(y_len) || \exists integer i; 0 <= i < \old(x_len) && \old(x[i]) != \old(y[\old(x_len) - 1 - i]));
  ensures 0 <= \result <= 1;*/
int check_B_implies_A(int * x, int x_len, int * y, int y_len) {
    return stub_B(x, x_len, y, y_len);
}
