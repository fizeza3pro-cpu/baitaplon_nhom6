#include<iostream>
#include"list_couse.h"
#include"list_sinhvien.h"
#include"list_giangvien.h"
#include"list_subject.h"
#include"phieu_dang_ky.h"
#include"UI.h"
using namespace std;
class nghiepvu{
    private:
    list_couse &ds_lop;
    list_sinhvien &ds_sv;
    list_giangvien &ds_gv;
    list_subject &ds_mon;
    vector<phieu_dang_ky>ds_phieu_dky;
    public:
    // Sử dụng initializer list để khởi tạo tham chiếu
    nghiepvu(list_couse &dsl,list_sinhvien &dssv,list_giangvien &dsgv,list_subject &dsm)
    :ds_mon(dsm),ds_sv(dssv),ds_lop(dsl),ds_gv(dsgv) {};
    void them_mon_hoc(string ma_gv,string ten_mon,string file_name);
    void dang_ky_lop_hoc(string id_sv,string ma_lop);
    void huy_dang_ky_lop_hoc(string id_sv,string ma_lop);
    void hienthi_ds_phieu_dky();
    void nhap_du_lieu_cho_couse(string file_name);
    void thaydoithongtin_couse(string ma_lop,string file_name);
    void tim_kiem_lop_hoc();
    void hien_thi_lop_hoc_cua_gv(string ma_gv);
    void hien_thi_lop_hoc_cua_mon(string sub_name);
};