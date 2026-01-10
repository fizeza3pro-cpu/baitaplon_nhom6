#include<iostream>
#include"list_giangvien.h"
#include<fstream>
#include<vector>    
using namespace std;
void list_giangvien::lay_du_lieu_tu_file(string file_name) {
    ifstream f(file_name);
    if (!f.is_open()) {
        cout << "Không mở được file!" << endl;
        return;
    }
    else {
        giangvien gv_temp;
        while (gv_temp.nhap_du_lieu_tu_file(f)) {
            ds_gv.push_back(gv_temp);
        }
        cout<<"Nhập thành công dữ liệu giảng viên từ "<<file_name<<" !"<<endl;
    }
    f.close();
}
void list_giangvien::hienthids_gv(){
    if (ds_gv.empty()) {
        cout << "Danh sách trống!" << endl;
    }
    cout<<"              ─────────────── ✦ ───────────────DANH SÁCH GIẢNG VIÊN─────────────── ✦ ───────────────"<<endl;
    for (int i = 0; i < ds_gv.size(); i++) {
        ds_gv[i].hienthithongtin_gv();
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

void list_giangvien::luu_du_lieu_vao_file(string file_name) {
    ofstream f(file_name); // Mở file ở chế độ ghi mới (ghi đè)
    if (!f.is_open()) {
        cout << "Không thể mở file để ghi!" << endl;
        return;
    }

    for (int i = 0; i < ds_gv.size(); i++) {
        ds_gv[i].ghi_du_lieu_vao_file(f);
        // Nếu không phải giảng viên cuối cùng thì mới xuống dòng
        //if (i < ds_gv.size() - 1) {
            f << endl;
        //}
    }
    f.close();
    cout << "Đã lưu thay đổi vào file: " << file_name << endl;
}

void list_giangvien::add_giangvien(string file_name){
    giangvien temp;
    temp.nhapthongtin();
    ds_gv.push_back(temp);
     ofstream f(file_name,ios::app);
    temp.ghi_du_lieu_vao_file(f);
    f<<"\n";
    f.close();
    cout<<"Đã thêm giảng viên vào file";

}
//lâm sửa lại hàm delete
bool list_giangvien::delete_giangvien(string ma,string file_name){
    for(int i = 0;i<ds_gv.size();i++){
        if(ds_gv[i].get_id() == ma){
            if(ds_gv[i].get_size_lop() >0){
                cout<<"Giảng viên này đang dạy lớp, không thể xoá!"<<endl;
                return false;
            }
            ds_gv.erase(ds_gv.begin() + i);
            luu_du_lieu_vao_file(file_name);
            return true;
        }
    }
    return false;
}
