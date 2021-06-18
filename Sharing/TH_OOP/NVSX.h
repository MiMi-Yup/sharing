#pragma once
#include "NV.h"
class NVSX :
    public NV
{
private:
    int soluongsanpham;
public:
    NVSX() {
        soluongsanpham = 0;
    }
    NVSX(string name, Date birth, Date start, bool gioitinh, string address, int salary, int soluongsanpham) :NV(name, birth, start, gioitinh, address, salary) {
        this->soluongsanpham = soluongsanpham;
        this->salary = soluongsanpham * 60000;
        if (soluongsanpham < 230) {
            salary *= 0.92f;
        }
    }
    void input() {
        NV::input();
        cout << "So luong san pham trong thang: "; cin >> soluongsanpham; cout << endl;
        this->salary = soluongsanpham * 60000;
        if (soluongsanpham < 230) {
            salary *= 0.92f;
        }
        cin.ignore();
    }
    void output() {
        NV::output();
        cout << "So ngay lam viec trong thang: " << soluongsanpham << "\n";
    }
};

