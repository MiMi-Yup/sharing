#pragma once
#include "cong.h"
class cong_hocthuat :
    public cong
{
private:
    int tritue;
public:
    cong_hocthuat() {
        tritue = 0;
    }
    void input() {
        cout << "------------Cong hoc thuat---------\n";
        cout << "Nhap tri tue: "; cin >> tritue;
    }
    void output() {
        cout << "------------Cong hoc thuat---------\n";
        cout << "Tri tue: " << tritue;
    }
    bool quacong(Hoangtu& hoangtu) {
        if (hoangtu.get_tritue() >= tritue) {
            return true;
        }
        return false;
    }
};

