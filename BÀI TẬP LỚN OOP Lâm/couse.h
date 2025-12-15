#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include"time.h"
#include"list_giangvien.h"
#include"list_subject.h"
#include"list_time.h"
#include<vector>
using namespace std;
class couse{   
    private:
    giangvien * gv;
    Time time;
    int max_sv;
    int cur_sv;
    subject *mon_hoc;
    string ma_lop_hoc; /* thật ra là mã lớp học mới chuẩn */
    static int sl;
    public:
    couse(){
        max_sv = 20;
        cur_sv = 0;
        sl++;
        tusinhma();
    }
    couse(string u,subject*c,giangvien *a,int x,int y,int z,int p):time(x,y,z){
        ma_lop_hoc = u;
        cur_sv = 0;
        gv = a;
        mon_hoc = c;
        max_sv = p;
    }
    int get_tin_chi()const{
        return mon_hoc->get_tin_chi();
    }
    string get_ma_lop_hoc()const{
        return ma_lop_hoc;
    }
    Time get_time(){
        return time;
    }
    bool check_id_hop_le();
    static void cap_nhat_id(string id);
    virtual string get_data()const = 0;
    virtual string get_loai() const = 0; 
    virtual bool nhap(giangvien* gv_func,subject* sub_func) = 0;    
    // virtual bool nhap_du_lieu_file(list_giangvien &ds_gv,list_time &ds_time,list_subject &ds_sub,vector<string>a) = 0;  
    virtual bool xuat_du_lieu_file(string &line) = 0;  
    virtual void hienthi() = 0;    
    bool ktra_full();
    bool tang_sv();
    bool giam_sv();
    void tusinhma();  /* hàm tự sinh mã, đại khái sẽ tự sinh mã =))*/ 
    // virtual void nhap_thong_tin_file(string file_name) = 0;
};                             