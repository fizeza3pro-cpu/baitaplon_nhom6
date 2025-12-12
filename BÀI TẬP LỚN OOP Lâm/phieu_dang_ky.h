#include<iostream>
#include"list_couse.h"
#include"sinhvien.h"
#include<string>
using namespace std;
class phieu_dang_ky{
    private:
    sinhvien sv_dky;
    couse *mon_dky;
    string thoi_gian_dky;
    public:
    phieu_dang_ky()
    {
        thoi_gian_dky = "";//lỗi gì gì đấy
    }
    phieu_dang_ky(sinhvien a, couse *b, string c){
        sv_dky = a;
        mon_dky = b;
        thoi_gian_dky = c;
    }
    void tao_phieu_dky(sinhvien a,couse *b );
};
