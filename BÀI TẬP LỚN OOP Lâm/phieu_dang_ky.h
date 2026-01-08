#pragma once
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
        sv_dky = nullptr;
        lop_dky = nullptr;
        thoi_gian_dky = "Không xác định";//lỗi gì gì đấy
    }
    phieu_dang_ky(sinhvien* a, couse* b,string tg) {
        sv_dky = a;
        lop_dky = b;
        thoi_gian_dky = tg;
    }
    void tao_phieu_dky(sinhvien* a,couse *b ){
        sv_dky = a;
        lop_dky = b;
        thoi_gian_dky = lay_tg_thuc();
    }
    void hien_thi_phieu_dky();
    string lay_tg_thuc();
    string to_string2(int x);
    string string_file();
    bool checkphieu(sinhvien* a, couse* b);
    void ghi_tiep_vao_file(string file_name);
    void nhap_du_lieu_tu_file(ifstream &f);
};
