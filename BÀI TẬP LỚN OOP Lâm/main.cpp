#include<iostream>
#include<string>
#include"list_time.h"
#include"list_giangvien.h"
#include"list_subject.h"
#include"list_time.h"
#include<fstream>
#include"nghiepvu.h"
#include<stdlib.h>
using namespace std;
int couse::sl = 0;
int main(){
  list_time a;
  list_sinhvien e;
  list_giangvien b;
  list_subject c;
  a.lay_du_lieu_tu_file("D:/dulieuthoigianhoc.txt"); /* file này gửi zl nhé */
  b.lay_du_lieu_tu_file("D:/dulieugiangvien.txt");
  c.lay_du_lieu_tu_file("D:/dulieumonhoc.txt");
  list_couse d;
  if(d.nhap_du_lieu_tu_file(b,a,c,"D:/dulieulophoc.txt")){
    cout<<"Nhap du lieu file thanh cong!"<<endl;
  }
  nghiepvu nv(d,e,a,b,c);
  nv.them_mon_hoc(b.get_giangvien(1),a.get_time(1),c.get_subject(1),"D:/dulieulophoc.txt");
  return 0;
}