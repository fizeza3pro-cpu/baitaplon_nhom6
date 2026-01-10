#pragma once
#include<iostream>
#include<vector>
#include"time.h"
#include<fstream>
#include<string>
using namespace std;
class giangvien{
    private:
    string id;
    string ten_giang_vien;
    string gioi_tinh;
    int birth[3];
    string hoc_vi;
    string sdt;
    string bo_mon;
    vector<string>couse_da_day;
    vector<Time>lich_day;
    public:
    giangvien(string a0,string a , string b, string c, string d,string d2,int e, int f, int g){
        id = a0;
        ten_giang_vien = a;
        gioi_tinh = b;
        hoc_vi = c;
        sdt = d;
        bo_mon = d2;
        birth[0] = e;
        birth[1] = f;
        birth[2] = g;
    }
    giangvien(){
        id = "chua xac dinh";
        ten_giang_vien = "chua xac dinh";
        gioi_tinh = "chua xac dinh";
        hoc_vi = "chua xac dinh";
        sdt = "chua xac dinh";
        bo_mon = "chua xac dinh";
       birth[0] = 0;
        birth[1] = 0;
        birth[2] = 0;
    }
    void nhapthongtin();
    void hienthithongtin_gv();
    // void hienthi_mondangday();
    bool nhap_du_lieu_tu_file(ifstream &f);
    void ghi_du_lieu_vao_file(ofstream& f);
    void them_couse_da_day_id(string ma_couse);
    bool xoa_couse_da_day_id(string ma_lop);
    bool check_lop_dang_day(string ma_lop);
    string get_id()const{
        return id;
    }
    string get_lop(int i)const{
        if(i>=0 && i<couse_da_day.size()){
            return couse_da_day[i];
        }
        return "";
    }
    int get_size_lop(){
        return couse_da_day.size();
    }
    string get_name()const{
        return ten_giang_vien;
    }
    string get_hoc_vi()const{
        return hoc_vi;
    }
    string get_bo_mon()const{
        return bo_mon;
    }
    bool kiemtra_trung_lich(Time a);
    void them_lich_day(Time a);
    bool xoa_lich_day(Time a);
   /*  get học vị các thứ phục vụ hiển thị về sau */
};