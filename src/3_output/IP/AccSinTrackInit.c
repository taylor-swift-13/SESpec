


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