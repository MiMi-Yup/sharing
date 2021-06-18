#pragma once
#include "NV.h"
class NVCN :
    public NV
{
private:
    int songaylamviec;
public:
    NVCN() {
        songaylamviec = 0;
    }
    NVCN(string name, Date birth, Date start, bool gioitinh, string address, int salary, int songaylamviec) :NV(name, birth, start, gioitinh, address, salary) {
        this->songaylamviec = songaylamviec;
        this->salary = songaylamviec * 500000;
        if (songaylamviec < 22) {
            salary *= 0.9f;
        }
    }
    void input() {
        NV::input();
        cout << "So ngay lam viec trong thang: "; cin >> songaylamviec; cout << endl;
        this->salary = songaylamviec * 500000;
        if (songaylamviec < 22) {
            salary *= 0.9f;
        }
        cin.ignore();
    }
    void output() {
        NV::output();
        cout << "So ngay lam viec trong thang: " << songaylamviec << "\n";
    }
};

