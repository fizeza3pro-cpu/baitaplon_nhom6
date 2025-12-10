#pragma once
#include<iostream>
#include<vector>
#include"online.h"
#include"offline.h"
#include<fstream>
#include<string>
using namespace std;
class sinhvien{
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
    sinhvien(string a ,string b,string x,string y,string z,int c, int d, int e,int t, int h,int k){
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
    sinhvien(){
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
    string get_name()const{
        return name;
    }
    string get_ma()const{
        return id;
    }

    void nhap();
    void hienthithongtin();
    bool dadangky(couse * mon);
    bool add_couse(couse * mon);
    bool delete_couse(couse * mon);
    bool nhap_du_lieu_tu_file(ifstream &f);
};