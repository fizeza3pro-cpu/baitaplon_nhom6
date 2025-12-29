#include<iostream>
#include"list_couse.h"
#include"sinhvien.h"
#include<ctime>
#include<iomanip>
#include<string>
using namespace std;
class phieu_dang_ky {
private:
    sinhvien* sv_dky;
    couse* lop_dky;
    string thoi_gian_dky;
public:
    phieu_dang_ky()
    {
        thoi_gian_dky = "";//lỗi gì gì đấy
    }
    phieu_dang_ky(sinhvien* a, couse* b) {
        sv_dky = a;
        lop_dky = b;
        thoi_gian_dky = lay_tg_thuc();
    }
    // void tao_phieu_dky(sinhvien a,couse *b );
    void hien_thi_phieu_dky();
    string lay_tg_thuc();
    string to_string2(int x);
    bool checkphieu(sinhvien* a, couse* b);
};
