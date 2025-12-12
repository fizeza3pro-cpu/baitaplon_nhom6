#include<iostream>
#include<string>
#include"list_time.h"
#include"list_giangvien.h"
#include"list_sinhvien.h"
#include"list_subject.h"
#include"list_time.h"
#include<fstream>
#include"nghiepvu.h"
#include<stdlib.h>
using namespace std;
int couse::sl = 0;
int main() {
    list_sinhvien sv;
    list_time tm;
    list_giangvien gv;
    list_subject mon;
    list_couse lop;
    tm.lay_du_lieu_tu_file("D:/dulieuthoigianhoc.txt"); /* file này gửi zl nhé */
    gv.lay_du_lieu_tu_file("D:/dulieugiangvien.txt");
    mon.lay_du_lieu_tu_file("D:/dulieumonhoc.txt");
    sv.lay_du_lieu_tu_file("D:/dulieusinhvien.txt");
    nghiepvu nv(lop,sv,tm,gv,mon);
    nv.nhap_du_lieu_cho_couse();
    nv.dang_ky_mon_hoc("sv001","KT002");
    sinhvien * a = sv.tim_sinhvien_theo_id("sv001");
    a ->hienthithongtin();
    cout<<"----------------------------------------------------------"<<endl;
    lop.hienthidanhsach();
  return 0;

}



