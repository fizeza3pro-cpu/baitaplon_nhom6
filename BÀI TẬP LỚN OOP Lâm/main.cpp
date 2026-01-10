#include<iostream>
#include<string>
#include"UI.h"
#include<fstream>
#include"nghiepvu.h"
#include"menu.h"
using namespace std;
int main() {
    srand(time(NULL));
    chuanhoa(65001);
    list_sinhvien sv;
    list_giangvien gv;
    list_subject mon;
    list_couse lop;
    gv.lay_du_lieu_tu_file(FILE_GIANG_VIEN);
    mon.lay_du_lieu_tu_file(FILE_MON_HOC);
    sv.lay_du_lieu_tu_file(FILE_SINH_VIEN);
    // loading();
    nghiepvu nv(lop, sv, gv, mon);
    nv.nhap_du_lieu_cho_couse(FILE_LOP_HOC);
    nv.nhap_du_lieu_file_phieu_dky(FILE_PHIEU_DKY);
    pause();
    menu_chinh(lop,gv,sv,mon,nv);
}