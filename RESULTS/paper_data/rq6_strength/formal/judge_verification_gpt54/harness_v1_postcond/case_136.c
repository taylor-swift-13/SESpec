#include <limits.h>



/*@assigns \nothing;
  ensures (0 <= \old(x)) ==> (\result == -1 || (\result * \result) <= \old(x));
  ensures (!(0 <= \old(x))) ==> (\result == -1);
  ensures (0 <= \old(x)) ==> (\result >= -1);*/
int stub_A(int x);

/*@loop invariant r <= x;
        loop invariant r < x + 1;
        loop invariant r + 1 <= x + 1;
        loop invariant l == ans + 1 || ans == -1;
        loop invariant l <= r + 2 || ans == -1;
        loop invariant ans == -1 || l == ans + 1;
        loop invariant ans == -1 || l == ans + 1 || l <= r + 1;
        loop invariant ans == -1 || l <= x + 1;
        loop invariant ans == -1 || l <= r + 1;
        loop invariant ans == -1 || l <= ans + 1;
        loop invariant ans == -1 || l - 1 <= ans;
        loop invariant ans == -1 || l - 1 <= ans + 1;
        loop invariant ans == -1 || ans <= x;
        loop invariant ans == -1 || ans <= x + 1;
        loop invariant ans == -1 || ans <= x && (long)ans * ans <= (long)x;
        loop invariant ans == -1 || ans <= r;
        loop invariant ans == -1 || ans <= r + 1;
        loop invariant ans == -1 || ans <= r + 1 && (long)ans * ans <= (long)x;
        loop invariant ans == -1 || ans <= l;
        loop invariant ans == -1 || ans <= l + r + 1;
        loop invariant ans == -1 || ans <= l + 1;
        loop invariant ans == -1 || ans < x + 1;
        loop invariant ans == -1 || ans < r + 2;
        loop invariant ans == -1 || ans < r + 1;
        loop invariant ans == -1 || ans < l;
        loop invariant ans == -1 || ans < l <= x + 1;
        loop invariant ans == -1 || ans < l + 2;
        loop invariant ans == -1 || ans < l + 1;
        loop invariant ans == -1 || ans < l && r <= x;
        loop invariant ans == -1 || ans < l && l <= x + 1;
        loop invariant ans == -1 || ans < l && ans <= r + 1;
        loop invariant ans == -1 || ans < l && (long)ans * ans <= (long)x;
        loop invariant ans == -1 || ans * ans <= x;
        loop invariant ans == -1 || (long)ans * ans <= x;
        loop invariant ans == -1 || (long)ans * ans <= x && ans < l;
        loop invariant ans == -1 || (long)ans * ans <= x && ans < l && ans <= r + 1;
        loop invariant ans == -1 || (long)ans * ans <= (long)x;
        loop invariant ans == -1 || (long)ans * ans <= (long)x && ans <= r + 1;
        loop invariant ans == -1 || (long)ans * ans <= (long)x && ans <= l;
        loop invariant ans == -1 || (long)ans * ans <= (long)x && ans < l;
        loop invariant ans == -1 || (long)ans * ans <= (long)x && ans < l + 1;
        loop invariant ans == -1 || (long)ans * ans <= (long)x && ans < l && ans <= r + 1;
        loop invariant ans == -1 || ((long)ans * ans <= x && ans < l);
        loop invariant ans == -1 || ((long)ans * ans <= (long)x);
        loop invariant ans == -1 || ((long)ans * ans <= (long)x && ans < l);
        loop invariant ans == -1 || ((long)ans * ans <= (long)x && ans < l && ans <= r + 1);
        loop invariant ans < l;
        loop invariant ans < l + 1;
        loop invariant ans + 1 <= l;
        loop invariant 0 <= l;
        loop invariant -1 <= ans;
        loop invariant (ans == -1) || ans <= r + 1;
        loop invariant (ans == -1) || ans < l;
        loop invariant (ans == -1) || (long)ans * ans <= (long)x;
        loop invariant (ans == -1) || (l == ans + 1);
        loop invariant (ans == -1) || ((long)ans * ans <= x);
        loop invariant (ans == -1) || ((long)ans * ans <= (long)x);
        loop invariant (ans == -1) || ((long)ans * ans <= (long)x && ans < l);
        loop invariant (ans == -1) || ((long)ans * ans <= (long)x && ans < l && ans <= r + 1);
        loop assigns r;
        loop assigns l;
        loop assigns ans;*/
int stub_B(int x);

/*@loop invariant r <= x;
        loop invariant r < x + 1;
        loop invariant r + 1 <= x + 1;
        loop invariant l == ans + 1 || ans == -1;
        loop invariant l <= r + 2 || ans == -1;
        loop invariant ans == -1 || l == ans + 1;
        loop invariant ans == -1 || l == ans + 1 || l <= r + 1;
        loop invariant ans == -1 || l <= x + 1;
        loop invariant ans == -1 || l <= r + 1;
        loop invariant ans == -1 || l <= ans + 1;
        loop invariant ans == -1 || l - 1 <= ans;
        loop invariant ans == -1 || l - 1 <= ans + 1;
        loop invariant ans == -1 || ans <= x;
        loop invariant ans == -1 || ans <= x + 1;
        loop invariant ans == -1 || ans <= x && (long)ans * ans <= (long)x;
        loop invariant ans == -1 || ans <= r;
        loop invariant ans == -1 || ans <= r + 1;
        loop invariant ans == -1 || ans <= r + 1 && (long)ans * ans <= (long)x;
        loop invariant ans == -1 || ans <= l;
        loop invariant ans == -1 || ans <= l + r + 1;
        loop invariant ans == -1 || ans <= l + 1;
        loop invariant ans == -1 || ans < x + 1;
        loop invariant ans == -1 || ans < r + 2;
        loop invariant ans == -1 || ans < r + 1;
        loop invariant ans == -1 || ans < l;
        loop invariant ans == -1 || ans < l <= x + 1;
        loop invariant ans == -1 || ans < l + 2;
        loop invariant ans == -1 || ans < l + 1;
        loop invariant ans == -1 || ans < l && r <= x;
        loop invariant ans == -1 || ans < l && l <= x + 1;
        loop invariant ans == -1 || ans < l && ans <= r + 1;
        loop invariant ans == -1 || ans < l && (long)ans * ans <= (long)x;
        loop invariant ans == -1 || ans * ans <= x;
        loop invariant ans == -1 || (long)ans * ans <= x;
        loop invariant ans == -1 || (long)ans * ans <= x && ans < l;
        loop invariant ans == -1 || (long)ans * ans <= x && ans < l && ans <= r + 1;
        loop invariant ans == -1 || (long)ans * ans <= (long)x;
        loop invariant ans == -1 || (long)ans * ans <= (long)x && ans <= r + 1;
        loop invariant ans == -1 || (long)ans * ans <= (long)x && ans <= l;
        loop invariant ans == -1 || (long)ans * ans <= (long)x && ans < l;
        loop invariant ans == -1 || (long)ans * ans <= (long)x && ans < l + 1;
        loop invariant ans == -1 || (long)ans * ans <= (long)x && ans < l && ans <= r + 1;
        loop invariant ans == -1 || ((long)ans * ans <= x && ans < l);
        loop invariant ans == -1 || ((long)ans * ans <= (long)x);
        loop invariant ans == -1 || ((long)ans * ans <= (long)x && ans < l);
        loop invariant ans == -1 || ((long)ans * ans <= (long)x && ans < l && ans <= r + 1);
        loop invariant ans < l;
        loop invariant ans < l + 1;
        loop invariant ans + 1 <= l;
        loop invariant 0 <= l;
        loop invariant -1 <= ans;
        loop invariant (ans == -1) || ans <= r + 1;
        loop invariant (ans == -1) || ans < l;
        loop invariant (ans == -1) || (long)ans * ans <= (long)x;
        loop invariant (ans == -1) || (l == ans + 1);
        loop invariant (ans == -1) || ((long)ans * ans <= x);
        loop invariant (ans == -1) || ((long)ans * ans <= (long)x);
        loop invariant (ans == -1) || ((long)ans * ans <= (long)x && ans < l);
        loop invariant (ans == -1) || ((long)ans * ans <= (long)x && ans < l && ans <= r + 1);
        loop assigns r;
        loop assigns l;
        loop assigns ans;*/
int check_A_implies_B(int x) {
    return stub_A(x);
}

/*@assigns \nothing;
  ensures (0 <= \old(x)) ==> (\result == -1 || (\result * \result) <= \old(x));
  ensures (!(0 <= \old(x))) ==> (\result == -1);
  ensures (0 <= \old(x)) ==> (\result >= -1);*/
int check_B_implies_A(int x) {
    return stub_B(x);
}
