#pragma once
#include<iostream>
#include"giangvien.h"
#include<vector>
using namespace std;
class list_giangvien {
private:
    vector<giangvien>ds_gv;
public:
    void hienthids();
    giangvien* tim_giangvien_theo_id(string ma_gv);
    void lay_du_lieu_tu_file(string file_name);
    void add_giangvien(giangvien a) {
        ds_gv.push_back(a);
    }
    void delete_giangvien(int i) {
        if (i < 0 || i >= ds_gv.size()) return;
        ds_gv.erase(ds_gv.begin() + i);
    }
    giangvien get_giangvien(int i) {
        return ds_gv[i];
    }
};