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
  list_giangvien b;
  list_subject c;
  a.lay_du_lieu_tu_file("D:/dulieuthoigianhoc.txt"); /* file này gửi zl nhé */
  b.lay_du_lieu_tu_file("D:/dulieugiangvien.txt");
  c.lay_du_lieu_tu_file("D:/dulieumonhoc.txt");
  online d;
  ifstream f("D:/dulieulophoc.txt");
  if(d.nhap_du_lieu_file(b,a,c,f)){
    cout<<"Nhap du lieu file thanh cong!"<<endl;
  d.hienthi();

 
  }
}