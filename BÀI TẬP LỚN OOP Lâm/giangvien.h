#pragma once
#include<iostream>
#include<vector>
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
    void hienthithongtin();
    void hienthi_mondangday();
    bool nhap_du_lieu_tu_file(ifstream &f);
    void them_couse_da_day_id(string ma_couse){
        couse_da_day.push_back(ma_couse);
    }
    string get_id()const{
        return id;
    }
    string get_name()const{
        return ten_giang_vien;
    }
   /*  get học vị các thứ phục vụ hiển thị về sau */
};