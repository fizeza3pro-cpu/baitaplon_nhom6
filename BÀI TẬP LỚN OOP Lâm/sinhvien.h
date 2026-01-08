#pragma once
#include<iostream>
#include<vector>
#include"online.h"
#include"offline.h"
#include<fstream>
#include<string>
using namespace std;
class sinhvien {
private:
    string name;
    string id;
    string gioi_tinh;
    int birth[3];
    string chuyen_nganh;
    string sdt;
    int khoa;
    int max_tc;
    int cur_tc;
    vector<couse*>ds_mon_dky;
public:
    sinhvien(string a, string b, string x, string y, string z, int c, int d, int e, int t, int h, int k) {
        id = a;
        name = b;
        gioi_tinh = x;
        chuyen_nganh = y;
        sdt = z;
        birth[0] = c; birth[1] = d, birth[2] = e;
        khoa = t;
        cur_tc = h;
        max_tc = k;

    }
    sinhvien() {
        name = "";
        gioi_tinh = "";
        id = "";
        chuyen_nganh = "";
        sdt = "";
        birth[0] = 0; birth[1] = 0, birth[2] = 0;
        khoa = 0;
        max_tc = 30;
        cur_tc = 0;
    }
    string get_name()const {
        return name;
    }
    string get_ma()const {
        return id;
    }
// ---------lâm viết-----------
    void nhap();
    void hienthithongtin();
    bool dadangky(couse* mon);
    bool add_couse(couse* mon);
    bool delete_couse(couse* mon);
    void hien_thi_lop_da_dky();
     int get_lop_size() const{
        return ds_mon_dky.size();
    }
    bool check_lop_dky(couse *lop_temp){
        if(ds_mon_dky.empty()){
            return false;
        }
        for(int i = 0;i<ds_mon_dky.size();i++){
            if(ds_mon_dky[i] == lop_temp){
                return true;
            }
        }
        return false;
    }
    // ----------------------------

    bool nhap_du_lieu_tu_file(ifstream& f);
    void ghi_vao_file();
    string get_gioi_tinh() const { return gioi_tinh; }
    string get_sdt() const { return sdt; }
    string get_chuyen_nganh() const { return chuyen_nganh; }
    int get_birth(int i) const { return birth[i]; }
    int get_khoa() const { return khoa; }
    int get_cur_tc() const { return cur_tc; }
    int get_max_tc() const { return max_tc; }
    // vector<couse*> get_ds_mon_dky() const { return ds_mon_dky; }
};