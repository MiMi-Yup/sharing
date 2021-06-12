#pragma once
#include "cong.h"
class cong_sucmanh :
    public cong
{
private:
    int sucdungsy;
public:
    cong_sucmanh() {
        sucdungsy = 0;
    }
    void input() {
        cout << "-----Cong suc manh--------\n";
        cout << "Nhap suc dung sy: "; cin >> sucdungsy;
    }
    void output() {
        cout << "-----Cong suc manh--------\n";
        cout << "Suc dung sy: " << sucdungsy;
    }
    bool quacong(Hoangtu& hoangtu) {
        int temp;
        if ((temp = hoangtu.get_sucmanh() - sucdungsy) < 0) {
            return false;
        }
        hoangtu.set(hoangtu.get_sotien(), temp, hoangtu.get_tritue());
        return true;
    }
};

