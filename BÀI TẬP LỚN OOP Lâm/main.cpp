#include<iostream>
#include<string>
// #include"UI.h"
#include<fstream>
#include"nghiepvu.h"
#include<stdlib.h>
using namespace std;
int main() {
  // SetConsoleOutputCP(65001);
    list_sinhvien sv;
    list_giangvien gv;
    list_subject mon;
    list_couse lop;
    gv.lay_du_lieu_tu_file("D:/dulieugiangvien.txt");
    mon.lay_du_lieu_tu_file("D:/dulieumonhoc.txt");
    sv.lay_du_lieu_tu_file("D:/dulieusinhvien.txt");
    nghiepvu nv(lop,sv,gv,mon);
    nv.nhap_du_lieu_cho_couse("D:/dulieulophoc.txt");
    nv.dang_ky_mon_hoc("sv001","MTA006");
    nv.thaydoithongtin_couse("MTA006","D:/dulieulophoc.txt");
    lop.hienthidanhsach();
}



