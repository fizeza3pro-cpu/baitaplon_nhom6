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
    list_couse &ds_mon;
    list_sinhvien &ds_sv;
    list_time &ds_time;
    list_giangvien &ds_gv;
    list_subject &ds_mon;
    vector<phieu_dang_ky>ds_phieu_dky;
    public:
    // Sử dụng initializer list để khởi tạo tham chiếu
    nghiepvu(list_couse &dsm,list_sinhvien &dssv,Time &x,giangvien &y,subject &z)
    :ds_mon(dsm),ds_sv(dssv),a(x),b(y),c(z){};
    void them_mon_hoc(giangvien c,Time d,subject e);
    void dang_ky_mon_hoc(sinhvien &a,couse *b);


};