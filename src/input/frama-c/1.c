

int abs(int val) {
    if(val < 0) return -val;
    return val;
}

void moo1(int a) {
    int b = abs(-42);
    //@ assert b == 42;
    int c = abs(42);
    //@ assert c == 42;
    int d = abs(a);
    int e = abs(-997);

}

/*@
  requires \valid(past);
  requires past->amax != 0.0;
  requires past->dChimax != 0.0;
  ensures 
    \let tacc = 2.0 * Fabsx(past->dChimax / past->amax);
    \let tv = Fabsx((past->Chim - past->Chim0) / past->dChimax) - tacc;
    ((tv > 0.0 &&
      past->tm1p == tacc &&
      past->tm2p == tacc + tv &&
      past->tm3p == 2.0 * tacc + tv)
     ||
     (tv <= 0.0 &&
      past->tm1p == Sqrtx(2.0 * Fabsx((past->Chim - past->Chim0) / past->amax)) &&
      past->tm2p == Sqrtx(2.0 * Fabsx((past->Chim - past->Chim0) / past->amax)) &&
      past->tm3p == 2.0 * Sqrtx(2.0 * Fabsx((past->Chim - past->Chim0) / past->amax))));
  assigns past->tm1p, past->tm2p, past->tm3p;
*/
void AccSinTrackInit(SMnvrData *past);