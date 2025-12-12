#pragma once
#include<iostream>
#include"online.h"
#include"offline.h"
#include<vector>
using namespace std;
class list_couse{
    private:
    vector<couse*>p;
    public:
    void nhap_test(giangvien &gv_func,Time &time_func,subject &sub_func,string file_name);
    // void nhapdanhsach(string file_name);
    void hienthidanhsach();
    // bool timkiem_ten(string ten_mon);
    // bool timkiem_ma(string ma);
    // void nhapfile(string file_name );
    couse * get_p(int i){
        return p[i];
    }
    couse* tim_lop_theo_ma(string ma);
    bool nhap_du_lieu_tu_file(list_giangvien &ds_gv,list_time &ds_time,list_subject &ds_sub,string file_name);
    void add_couse(couse *a){
        p.push_back(a);
    }
    void delete_course(int i){
    if (i < 0 || i >= p.size()) return;
    p.erase(p.begin() + i);
}
};