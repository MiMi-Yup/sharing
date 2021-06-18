#pragma once
#include "SV.h"
class SVDH :
    public SV
{
private:
    string thesis_name;
    float thesis_score;
public:
    SVDH();
    SVDH(int, string, string, int, float, string, float);
    void input();
    void output();
    bool passed();
};

