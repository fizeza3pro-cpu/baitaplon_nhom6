#pragma once
#include <iostream>
#include"nghiepvu.h"
#include"UI.h"
#include<stdlib.h>
using namespace std;
const string FILE_LOP_HOC = "D://dulieulophoc.txt";
const string FILE_MON_HOC = "D://dulieumonhoc.txt";
const string FILE_SINH_VIEN = "D://dulieusinhvien.txt";
const string FILE_PHIEU_DKY = "D://dangky.txt";
const string FILE_GIANG_VIEN = "D:/dulieugiangvien.txt";
void menu_chinh(list_couse &lop,list_giangvien &gv, list_sinhvien &sv, list_subject &mon,nghiepvu &nv);
void menu_nghiep_vu(list_couse &lop,list_giangvien &gv, list_sinhvien &sv, list_subject &mon,nghiepvu &nv);
void menu_quan_ly(list_couse &lop,list_giangvien &gv, list_sinhvien &sv, list_subject &mon,nghiepvu &nv);
