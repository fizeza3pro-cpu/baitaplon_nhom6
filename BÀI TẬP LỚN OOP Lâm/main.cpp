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
  nghiepvu a;
  a.nhap_du_lieu_tu_all_file();
  a.dang_ky_mon_hoc("sv001","KT001");
  a.hienthi_ds_phieu_dky();
  return 0;
}