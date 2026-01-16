



/*@
  requires \valid(past);
  ensures
    ( 
      ( (Fabsx((past->Chim - past->Chim0) / past->dChimax) - 2.0 * Fabsx(past->dChimax / past->amax)) > 0.0 )
      ==> (
         past->tm1p == 2.0 * Fabsx(past->dChimax / past->amax) &&
         past->tm2p == 2.0 * Fabsx(past->dChimax / past->amax) + 
                       (Fabsx((past->Chim - past->Chim0) / past->dChimax) - 2.0 * Fabsx(past->dChimax / past->amax)) &&
         past->tm3p == 2.0 * (2.0 * Fabsx(past->dChimax / past->amax)) + 
                       (Fabsx((past->Chim - past->Chim0) / past->dChimax) - 2.0 * Fabsx(past->dChimax / past->amax))
      )
    )
    &&
    (
      ( (Fabsx((past->Chim - past->Chim0) / past->dChimax) - 2.0 * Fabsx(past->dChimax / past->amax)) <= 0.0 )
      ==> (
         past->tm1p == Sqrtx(2.0 * Fabsx((past->Chim - past->Chim0) / past->amax)) &&
         past->tm2p == Sqrtx(2.0 * Fabsx((past->Chim - past->Chim0) / past->amax)) &&
         past->tm3p == 2.0 * Sqrtx(2.0 * Fabsx((past->Chim - past->Chim0) / past->amax))
      )
    )
  ;
  assigns past->tm1p, past->tm2p, past->tm3p;
*/
void AccSinTrackInit(SMnvrData *past)
{
    float64 tacc;
    float64 tv;

    /* 计算加/减速段时间 */
    tacc = 2.0 * Fabsx(past->dChimax / past->amax);
    tv = Fabsx((past->Chim - past->Chim0) / past->dChimax) - tacc;

    /* 对无匀速段情况的处理 */
    if(tv <= 0.0)
    {
        tv = 0.0;

        tacc = Sqrtx(2.0 * Fabsx((past->Chim - past->Chim0) / past->amax));
    }

    /* 计算期望角速度轨迹的相对转折时间点tm1 */
    past->tm1p = tacc;

    /* 计算期望角速度轨迹的相对转折时间点tm2 */
    past->tm2p = tacc + tv;

    /* 计算期望角速度轨迹的相对转折时间点tm3 */
    past->tm3p = 2.0 * tacc + tv;

    return;
}

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

    /* 机动角度轨迹规划 */
    tm = past->tmA;
    if(tm < 0.0)  /* 机动开始前 tm < 0 */
    {
        past->Chi_Ref = past->Chim0;
    }
    /* 0 <= tm < tm1p */
    else if(tm < past->tm1p)  /* 加速段 */
    {
        past->Chi_Ref  = past->Chim0 + 0.5 * sign * past->amax * (0.5 * tm * tm - rff + rff * Cosx(f * tm));
    }
    /* tm1p <= tm < tm2p */
    else if(tm < past->tm2p)  /* 匀速段 */
    {
        past->Chi_Ref  = past->Chim0 +  0.5 * sign * past->amax * (tm * past->tm1p - 0.5 * past->tm1p * past->tm1p);
    }
    /* tm2p <= tm < tm3p */
    else if(tm < past->tm3p)  /* 减速段 */
    {
        past->Chi_Ref  = past->Chim0 - 0.5 * sign * past->amax * (0.5 * tm * tm - past->tm3p * tm + rff * Cosx(f * (tm - past->tm2p)) - rff + past->tm1p * past->tm1p + 0.5 * past->tm3p * (past->tm2p - past->tm1p));
    }
    /* tm >= tm3p */
    else  /* 机动到位后 */
    {
        past->Chi_Ref = past->Chim;
    }

    /* 机动角速度轨迹规划 */
    tm = past->tmA - dtv;
    if(tm < 0.0)  /* 机动开始前 tm < 0 */
    {
        past->dChi_Ref = 0.0;
    }
    /* 0 <= tm < tm1p */
    else if(tm < past->tm1p)  /* 加速段 */
    {
        past->dChi_Ref = 0.5 * sign * past->amax * (tm - rf * Sinx(f * tm));
    }
    /* tm1p <= tm < tm2p */
    else if(tm < past->tm2p)  /* 匀速段 */
    {
        past->dChi_Ref = 0.5 * sign * past->amax * past->tm1p;
    }
    /* tm2p <= tm < tm3p */
    else if(tm < past->tm3p)  /* 减速段 */
    {
        past->dChi_Ref = -0.5 * sign * past->amax * (tm - past->tm3p - rf * Sinx(f * (tm - past->tm2p)));
    }
    /* tm >= tm3p */
    else  /* 机动到位后 */
    {
        past->dChi_Ref = 0.0;
    }

    /* 机动角加速度轨迹规划 */
    tm = past->tmA + dtTr;
    if(tm < 0.0)  /* 机动开始前 tm < 0 */
    {
        past->acc_Ref = 0.0;
    }
    /* 0 <= tm < tm1p */
    else if(tm < past->tm1p)  /* 加速段 */
    {
        past->acc_Ref = 0.5 * sign * past->amax * (1.0 - Cosx(f * tm));
    }
    /* tm1p <= tm < tm2p */
    else if(tm < past->tm2p)  /* 匀速段 */
    {
        past->acc_Ref = 0.0;
    }
    /* tm2p <= tm < tm3p */
    else if(tm < past->tm3p)  /* 减速段 */
    {
        past->acc_Ref = -0.5 * sign * past->amax * (1.0- Cosx(f * (tm - past->tm2p)));
    }
    /* tm >= tm3p */
    else  /* 机动到位后 */
    {
        past->acc_Ref = 0.0;
    }

    return;
}