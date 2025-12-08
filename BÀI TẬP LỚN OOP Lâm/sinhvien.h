#pragma once
#include<iostream>
#include<string>
using namespace std;
class sinhvien{
    private:
    string name;
    string id;
    string gioi_tinh;
    int birth[3];
    int tuoi;
    string chuyen_nganh;
    string sdt;
    int khoa;
    int so_mon_dky;
    int max_tc;
    int cur_tc;
    string ds_ma_mon_dky[100];
    public:
    sinhvien(string a ,string b,string x,string y,string z,int c, int d, int e,int f,int t, int h,int k,int q){
        name = b;
        gioi_tinh = y;
        id = a;
        chuyen_nganh = x;
        sdt = z;
        birth[0] = c; birth[1] = d, birth[2] = e;
        tuoi = f;
        khoa = t;
        cur_tc = h;
        max_tc = k;
        so_mon_dky = q;
        for(int i = 0;i<100;i++){
            ds_ma_mon_dky[i] = "";
        }
    }
    sinhvien(){
        name = "";
        gioi_tinh = "";
        id = "";
        chuyen_nganh = "";
        sdt = "";
        birth[0] = 0; birth[1] = 0, birth[2] = 0;
        tuoi = 0;
        khoa = 0;
        max_tc = 30;
        cur_tc = 0;
        for(int i = 0;i<100;i++){
            ds_ma_mon_dky
            [i] = "";
        }
        so_mon_dky = 0;
    }
    string get_name()const{
        return name;
    }
    string get_ma()const{
        return id;
    }
    string get_dsma_mon(int i){
        return ds_ma_mon_dky[i];
    }
    int get_smdk(){
        return so_mon_dky;
    }
    void nhap();
    void hienthithongtin();
    bool dadangky( const string ma_mon);
    bool add_couse(const string ma_mon,int tin);
    bool delete_couse(const string ma_mon,int tin);
    friend class dangky_couse;
};