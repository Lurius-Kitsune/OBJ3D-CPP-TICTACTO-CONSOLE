#pragma once
#include "UserInteraction.h"

static int RandomInt(const u_int& _max, const u_int& _min)
{
    random_device _rSeed;
    mt19937 _gen(_rSeed());
    uniform_int_distribution<> distr(_min, _max);

    return distr(_gen);
}