#include<iostream>
#include"list_couse.h"
#include"list_sinhvien.h"
#include"list_time.h"
#include"list_giangvien.h"
#include"list_subject.h"
#include"phieu_dang_ky.h"
using namespace std;
class nghiepvu{
    private:
    list_couse &ds_lop;
    list_sinhvien &ds_sv;
    list_time &ds_time;
    list_giangvien &ds_gv;
    list_subject &ds_mon;
    vector<phieu_dang_ky>ds_phieu_dky;
    public:
    // Sử dụng initializer list để khởi tạo tham chiếu
    nghiepvu(list_couse &dsl,list_sinhvien &dssv,list_time &dst,list_giangvien &dsgv,list_subject &dsm)
    :ds_mon(dsm),ds_sv(dssv),ds_lop(dsl),ds_time(dst),ds_gv(dsgv) {};
    void them_mon_hoc(giangvien c,Time d,subject e,string file_name);
    void dang_ky_mon_hoc(sinhvien &a,couse *b);
};