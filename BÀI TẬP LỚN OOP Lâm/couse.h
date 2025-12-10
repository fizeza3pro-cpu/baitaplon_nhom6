#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include"time.h"
#include"list_giangvien.h"
#include"list_subject.h"
#include"list_time.h"
using namespace std;
class couse{
    protected:
    giangvien gv;
    int max_sv;
    int cur_sv;
    Time time;
    subject mon_hoc;
    string ma_mon_hoc;
    static int sl;
    public:
    couse(){
        max_sv = 20;
        cur_sv = 0;
        sl++;
        tusinhma();
    }
    couse(int max,giangvien a,Time b, subject c){
        gv = a;
        time = b;
        mon_hoc = c;
        max_sv = max;
        sl++;
        tusinhma();
    }
    int get_tin_chi()const{
        return mon_hoc.get_tin_chi();
    }
    virtual string get_data()const = 0;
    virtual string get_loai() const = 0; 
    virtual void nhap(giangvien gv_func,Time time_func,subject sub_func) = 0;    
    virtual bool nhap_du_lieu_file(list_giangvien &ds_gv,list_time &ds_time,list_subject &ds_sub,ifstream &f) = 0;     
    virtual void hienthi() = 0;    
    bool ktra_full();
    bool tang_sv();
    bool giam_sv();
    void tusinhma();  /* hàm tự sinh mã, đại khái sẽ tự sinh mã =))*/ 
    void fix_matusinh();
    // virtual void nhap_thong_tin_file(string file_name) = 0;
};                             