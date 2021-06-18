#pragma once
#include "SV.h"
class SVCD :
    public SV
{
private:
    float graduation_score;
public:
    SVCD();
    SVCD(int, string, string, int, float, float);
    void input();
    void output();
    bool passed();
};

