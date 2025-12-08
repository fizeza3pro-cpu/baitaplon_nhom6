#pragma once
#include<iostream>
#include"sinhvien.h"
#include"list_couse.h"
#include<string.h>
using namespace std;
class tkb{
    private:
    struct buoihoc{
        string ma_mon_hoc;
        string ten_mon_hoc;
        int date[3];
        int tiet_begin;
        int tiet_end;
        string dia_diem;
        string loai;
    };
    buoihoc bh[100];
    int sl_bh;
    public:
    tkb(int sl_bh = 0):sl_bh(sl_bh){};
    void taotkb(sinhvien &sv,list_couse &b);
    void hienthi(sinhvien &sv);
    void sapxep();
};
        
