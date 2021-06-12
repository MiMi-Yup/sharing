#pragma once
#include "cong.h"
class cong_giaothuong :
    public cong
{
private:
    int sohang, dongia;
public:
    cong_giaothuong() {
        sohang = 0;
        dongia = 0;
    }
    void input() {
        cout << "--------Cong giao thuong------\n";
        cout << "Nhap so hang: "; cin >> sohang;
        cout << "Nhap don gia: "; cin >> dongia;
    }
    void output() {
        cout << "--------Cong giao thuong------\n";
        cout << "So hang: "; cin >> sohang;
        cout << "Don gia: "; cin >> dongia;
        cout << "Mat tien: " << sohang * dongia;
    }
    bool quacong(Hoangtu& hoangtu) {
        int temp;
        if ((temp=hoangtu.get_sotien() - sohang * dongia) < 0) {
            return false;
        }
        hoangtu.set(temp, hoangtu.get_sucmanh(), hoangtu.get_tritue());
        return true;
    }
};

