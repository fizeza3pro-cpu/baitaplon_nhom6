#pragma once
#include<iostream>
#include"giangvien.h"
#include<vector>
using namespace std;
class list_giangvien {
private:
    vector<giangvien>ds_gv;
public:
    void hienthids_gv();
    giangvien* tim_giangvien_theo_id(string ma_gv);
    void lay_du_lieu_tu_file(string file_name);
    // void luu_du_lieu_vao_file_continue(string file_name);
    void luu_du_lieu_vao_file(string file_name);
    void add_giangvien(string file_name);
   bool delete_giangvien(string ma,string file_name);
    giangvien get_giangvien(int i) {
        return ds_gv[i];
    }
     int get_size() {
        return ds_gv.size();
    }
};