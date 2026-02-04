
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
void AccSinTrackInit(SMnvrData *past)
{
    float64 tacc;
    float64 tv;

    tacc = 2.0 * Fabsx(past->dChimax / past->amax);
    tv = Fabsx((past->Chim - past->Chim0) / past->dChimax) - tacc;

    if(tv <= 0.0)
    {
        tv = 0.0;
        tacc = Sqrtx(2.0 * Fabsx((past->Chim - past->Chim0) / past->amax));
    }

    past->tm1p = tacc;
    past->tm2p = tacc + tv;
    past->tm3p = 2.0 * tacc + tv;

    return;
}

/*@
  requires \valid(past);
  requires past->tm1p != 0.0;
  ensures 
    (past->F_Init_Trajectory == 1 ==> past->F_Init_Trajectory == 0) &&
    (\result == \old(\result)) &&

    // Chi_Ref depends on tm = past->tmA and segment intervals on tm1p, tm2p, tm3p
    (   past->tmA < 0.0 ==> past->Chi_Ref == past->Chim0
     && (0.0 <= past->tmA && past->tmA < past->tm1p) ==>
          past->Chi_Ref == past->Chim0 + 0.5 * Sgn2(past->Chim - past->Chim0) * past->amax *
              (0.5 * past->tmA * past->tmA - 1.0/( (DBL_PI/past->tm1p)*(DBL_PI/past->tm1p)) + 1.0/( (DBL_PI/past->tm1p)*(DBL_PI/past->tm1p)) * Cosx((DBL_PI/past->tm1p) * past->tmA))
     && (past->tm1p <= past->tmA && past->tmA < past->tm2p) ==>
          past->Chi_Ref == past->Chim0 + 0.5 * Sgn2(past->Chim - past->Chim0) * past->amax *
              (past->tmA * past->tm1p - 0.5 * past->tm1p * past->tm1p)
     && (past->tm2p <= past->tmA && past->tmA < past->tm3p) ==>
          past->Chi_Ref == past->Chim0 - 0.5 * Sgn2(past->Chim - past->Chim0) * past->amax *
              (0.5 * past->tmA * past->tmA - past->tm3p * past->tmA 
               + 1.0/((DBL_PI/past->tm1p)*(DBL_PI/past->tm1p)) * Cosx((DBL_PI/past->tm1p)*(past->tmA - past->tm2p))
               - 1.0/((DBL_PI/past->tm1p)*(DBL_PI/past->tm1p)) 
               + past->tm1p*past->tm1p 
               + 0.5 * past->tm3p * (past->tm2p - past->tm1p))
     && (past->tmA >= past->tm3p) ==>
          past->Chi_Ref == past->Chim

    ) &&

    // dChi_Ref depends on tm = past->tmA - dtv on the same segments
    (   (past->tmA - dtv) < 0.0 ==> past->dChi_Ref == 0.0
     && (0.0 <= (past->tmA - dtv) && (past->tmA - dtv) < past->tm1p) ==>
          past->dChi_Ref == 0.5 * Sgn2(past->Chim - past->Chim0) * past->amax *
                          ((past->tmA - dtv) - 1.0/(DBL_PI/past->tm1p) * Sinx((DBL_PI/past->tm1p)*(past->tmA - dtv)))
     && (past->tm1p <= (past->tmA - dtv) && (past->tmA - dtv) < past->tm2p) ==>
          past->dChi_Ref == 0.5 * Sgn2(past->Chim - past->Chim0) * past->amax * past->tm1p
     && (past->tm2p <= (past->tmA - dtv) && (past->tmA - dtv) < past->tm3p) ==>
          past->dChi_Ref == -0.5 * Sgn2(past->Chim - past->Chim0) * past->amax *
               ((past->tmA - dtv) - past->tm3p - 1.0/(DBL_PI/past->tm1p) * Sinx((DBL_PI/past->tm1p)*((past->tmA - dtv) - past->tm2p)))
     && (past->tmA - dtv) >= past->tm3p ==>
          past->dChi_Ref == 0.0
    ) &&

    // acc_Ref depends on tm = past->tmA + dtTr on same segments
    (   (past->tmA + dtTr) < 0.0 ==> past->acc_Ref == 0.0
     && (0.0 <= (past->tmA + dtTr) && (past->tmA + dtTr) < past->tm1p) ==>
          past->acc_Ref == 0.5 * Sgn2(past->Chim - past->Chim0) * past->amax * (1.0 - Cosx((DBL_PI/past->tm1p)*(past->tmA + dtTr)))
     && (past->tm1p <= (past->tmA + dtTr) && (past->tmA + dtTr) < past->tm2p) ==>
          past->acc_Ref == 0.0
     && (past->tm2p <= (past->tmA + dtTr) && (past->tmA + dtTr) < past->tm3p) ==>
          past->acc_Ref == -0.5 * Sgn2(past->Chim - past->Chim0) * past->amax * (1.0 - Cosx((DBL_PI/past->tm1p)*((past->tmA + dtTr) - past->tm2p)))
     && (past->tmA + dtTr) >= past->tm3p ==>
          past->acc_Ref == 0.0
    );
  assigns
    past->F_Init_Trajectory,
    past->Chi_Ref,
    past->dChi_Ref,
    past->acc_Ref;
*/
void AccSinTrackCalculate(SMnvrData *past, float64 dtv, float64 dtTr)
{
    float64 f;
    float64 rf;
    float64 rff;
    float64 sign;
    float64 tm;

    if(past->F_Init_Trajectory == 1)
    {
        past->F_Init_Trajectory = 0;
        AccSinTrackInit(past);
    }

    f = DBL_PI / past->tm1p;
    sign = Sgn2(past->Chim - past->Chim0);
    rf = 1.0 / f;
    rff = 1.0 / (f * f);

    tm = past->tmA;
    if(tm < 0.0)
    {
        past->Chi_Ref = past->Chim0;
    }
    else if(tm < past->tm1p)
    {
        past->Chi_Ref  = past->Chim0 + 0.5 * sign * past->amax * (0.5 * tm * tm - rff + rff * Cosx(f * tm));
    }
    else if(tm < past->tm2p)
    {
        past->Chi_Ref  = past->Chim0 +  0.5 * sign * past->amax * (tm * past->tm1p - 0.5 * past->tm1p * past->tm1p);
    }
    else if(tm < past->tm3p)
    {
        past->Chi_Ref  = past->Chim0 - 0.5 * sign * past->amax * (0.5 * tm * tm - past->tm3p * tm + rff * Cosx(f * (tm - past->tm2p)) - rff + past->tm1p * past->tm1p + 0.5 * past->tm3p * (past->tm2p - past->tm1p));
    }
    else
    {
        past->Chi_Ref = past->Chim;
    }

    tm = past->tmA - dtv;
    if(tm < 0.0)
    {
        past->dChi_Ref = 0.0;
    }
    else if(tm < past->tm1p)
    {
        past->dChi_Ref = 0.5 * sign * past->amax * (tm - rf * Sinx(f * tm));
    }
    else if(tm < past->tm2p)
    {
        past->dChi_Ref = 0.5 * sign * past->amax * past->tm1p;
    }
    else if(tm < past->tm3p)
    {
        past->dChi_Ref = -0.5 * sign * past->amax * (tm - past->tm3p - rf * Sinx(f * (tm - past->tm2p)));
    }
    else
    {
        past->dChi_Ref = 0.0;
    }

    tm = past->tmA + dtTr;
    if(tm < 0.0)
    {
        past->acc_Ref = 0.0;
    }
    else if(tm < past->tm1p)
    {
        past->acc_Ref = 0.5 * sign * past->amax * (1.0 - Cosx(f * tm));
    }
    else if(tm < past->tm2p)
    {
        past->acc_Ref = 0.0;
    }
    else if(tm < past->tm3p)
    {
        past->acc_Ref = -0.5 * sign * past->amax * (1.0- Cosx(f * (tm - past->tm2p)));
    }
    else
    {
        past->acc_Ref = 0.0;
    }

    return;
}
