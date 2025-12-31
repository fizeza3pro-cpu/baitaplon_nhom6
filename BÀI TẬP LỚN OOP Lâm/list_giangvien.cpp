#include<iostream>
#include"list_giangvien.h"
#include<fstream>
#include<vector>    
using namespace std;
void list_giangvien::lay_du_lieu_tu_file(string file_name) {
    ifstream f(file_name);
    if (!f.is_open()) {
        cout << "ko mo dc file!" << endl;
        return;
    }
    else {
        giangvien gv_temp;
        while (gv_temp.nhap_du_lieu_tu_file(f)) {
            ds_gv.push_back(gv_temp);
        }
    }
    f.close();
}
void list_giangvien::hienthids() {
    cout << "-------Danh sach giang vien-------" << endl;
    for (int i = 0; i < ds_gv.size(); i++) {
        ds_gv[i].hienthithongtin();
        cout << "\n";
    }
}
giangvien* list_giangvien::tim_giangvien_theo_id(string ma_gv) {
    for (int i = 0; i < ds_gv.size(); i++) {
        if (ds_gv[i].get_id() == ma_gv) {
            return &ds_gv[i];
        }
    }
    return nullptr;
}
