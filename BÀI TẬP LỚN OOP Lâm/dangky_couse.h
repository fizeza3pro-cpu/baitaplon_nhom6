#include<iostream>
#include"list_couse.h"
#include"sinhvien.h"
#include<string>
using namespace std;
class dangky_couse{
    private:
    list_couse &ds_mon;
    sinhvien *sv[100];
    int slsv;
    struct chitiet_dky{
        string masv;
        string ma_mon_dky;
        bool trangthai;
    };
    chitiet_dky dsdk[100];
    int sl_dsdk;
    public:
    dangky_couse(list_couse & ds_mon,int n = 0,int m = 0):ds_mon(ds_mon),slsv(n),sl_dsdk(m){};
    bool dangkymonhoc(string ma_mon,string ma_sv);
    bool huymonhoc(string ma_mon,string ma_sv);
    void danhsach_mondky(string ma_sv);
    void full_ds_monhoc(string ma_sv);
    void add_sv(sinhvien *a);
    void add_sv_file(string data);

};
helllo