#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include"phieu_dang_ky.h"
#include"UI.h"
using namespace std;
// void phieu_dang_ky::tao_phieu_dky(sinhvien a,couse* b){
//     sv_dky = a;
//     lop_dky = b;
//     thoi_gian_dky = "12/06/2024"; /* chua xac dinh thoi gian dang ky */  
// }
string phieu_dang_ky::to_string2(int x) {
    return (x < 10 ? "0" : "") + to_string(x);
}
string phieu_dang_ky::lay_tg_thuc() {
    time_t now = time(0);
    tm* lmt = localtime(&now);
    string thoi_gian;
    thoi_gian = to_string2(lmt->tm_hour) + ":" + to_string2(lmt->tm_min)
        + ":" + to_string2(lmt->tm_sec) + " " + to_string(lmt->tm_mday) + "/"
        + to_string(lmt->tm_mon + 1) + "/" + to_string(1900 + lmt->tm_year);
    return thoi_gian;
}

void phieu_dang_ky::hien_thi_phieu_dky(){
    int do_lech = getUTF8LenDiff(sv_dky->get_name());
    cout << "   " << left
        << setw(18) << sv_dky->get_ma()
        << setw(25 + do_lech) << sv_dky->get_name()
        << setw(20) << (lop_dky->get_ma_lop_hoc())
        << thoi_gian_dky << endl;
}
bool phieu_dang_ky::checkphieu(sinhvien* a, couse* b) {
    if (sv_dky == a && lop_dky == b) {
        return true;
    }
    return false;
}
string phieu_dang_ky::string_file(){
    string temp = sv_dky->get_ma()+"|"+lop_dky->get_ma_lop_hoc()+"|"+thoi_gian_dky;
    return temp;

}

void phieu_dang_ky::ghi_tiep_vao_file(string file_name){
    ofstream f(file_name,ios::app);
    if (!f.is_open()){
        cout<<"Lỗi không mở đc file!";
        return;
    }
    f<<string_file()<<endl;
    f.close();
}
// void phieu_dang_ky::nhap_du_lieu_tu_file(ifstream &f){
    

// }

