#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include"time.h"
#include"list_giangvien.h"
#include"list_subject.h"
#include<vector>
using namespace std;
class couse {
private:
    giangvien* gv;
    Time time;
    int max_sv;
    int cur_sv;
    subject* mon_hoc;
    string ma_lop_hoc; /* thật ra là mã lớp học mới chuẩn */
    static int sl;
public:
    couse() {
        max_sv = 20;
        cur_sv = 0;
        sl++;
        tusinhma();
    }
    couse(string u, subject* c, giangvien* a, int x, int y, int z, int p) :time(x, y, z) {
        ma_lop_hoc = u;
        cur_sv = 0;
        gv = a;
        mon_hoc = c;
        max_sv = p;
    }
    // ------------getter------------
    int get_tin_chi()const {
        return mon_hoc->get_tin_chi();
    }
    string get_ma_lop_hoc()const {
        return ma_lop_hoc;
    }
    Time get_time() {
        return time;
    }
    giangvien* get_gv()const {
        return gv;
    }
    subject* get_mon_hoc()const {
        return mon_hoc;
    }
    int get_cur_sv()const {
        return cur_sv;
    }
    // -------------setter-------------
    void set_giangvien(giangvien* new_gv) {
        this->gv = new_gv;
    }
    void set_mon(subject* new_sub) {
        this->mon_hoc = new_sub;
    }
    void set_time(Time new_time) {
        this->time = new_time;
    }
    void set_max_sv(int new_max_sv) {
        this->max_sv = new_max_sv;
    }

    static void cap_nhat_id(string id);
    virtual void string_file(string &line) = 0;
    virtual string get_data()const = 0;
    virtual string get_loai() const = 0;
    virtual bool nhap(giangvien* gv_func, subject* sub_func);
    virtual bool xuat_du_lieu_file(string& line);
    virtual void hienthi();
    bool ktra_full();
    bool tang_sv();
    bool giam_sv();
    void tusinhma();  /* hàm tự sinh mã, đại khái sẽ tự sinh mã =))*/
    // virtual void nhap_thong_tin_file(string file_name) = 0;
};