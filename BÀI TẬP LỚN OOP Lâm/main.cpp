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
int main() {
    list_sinhvien sv;
    list_giangvien gv;
    list_subject mon;
    list_couse lop;
    gv.lay_du_lieu_tu_file("D:/dulieugiangvien.txt");
    mon.lay_du_lieu_tu_file("D:/dulieumonhoc.txt");
    sv.lay_du_lieu_tu_file("D:/dulieusinhvien.txt");
    nghiepvu nv(lop,sv,gv,mon);
    nv.nhap_du_lieu_cho_couse();
    nv.them_mon_hoc("gv01","Kinh te chinh tri","D:/dulieulophoc.txt");
    lop.hienthidanhsach();
  //   nv.dang_ky_mon_hoc("sv001","MTA002");
  //   sinhvien * a = sv.tim_sinhvien_theo_id("sv001");
  //   a ->hienthithongtin();
  //   cout<<"----------------------------------------------------------"<<endl;
  //   lop.hienthidanhsach();
  // return 0;
}



