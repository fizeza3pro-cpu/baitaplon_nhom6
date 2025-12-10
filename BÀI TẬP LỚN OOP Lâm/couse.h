#pragma once
#include<iostream>
#include<string>
#include"time.h"
using namespace std;
class couse{   
    private:
    string gv;
    int tc;
    Time time;
    int max_sv;
    int cur_sv;
    static int sl;
    protected:
    string ten_mon_hoc;
    string ma_mon_hoc;
    public:
    couse(){
        ma_mon_hoc = "";
        ten_mon_hoc = "";
        gv = "";
        max_sv = 0;
        cur_sv = 0;
        sl++;
        tusinhma();
    }
    couse(int a, int b, int c,int d,int e, string y, string z,int m,int n,int p ):
    time(a,b,c,d,e){
        ma_mon_hoc = "";
        ten_mon_hoc = y;
        gv = z;
        tc = m;
        max_sv = p;
        cur_sv = n;
        sl++;
        tusinhma();
    }
    string getten_mon_hoc() const{
        return ten_mon_hoc;
    }
    string getma_mon_hoc()const{   /*getter nhieu ko bao dam tinh dong goi ? fix dc thi tot*/
        return ma_mon_hoc;
    }
    string get_gv()const{
        return gv;
    }
    string get_time()const{
        string time_get;
        time_get = to_string(time.tiet_begin) + "|" + to_string(time.tiet_end) + "|" +to_string( time.d) + 
        "|" +  to_string(time.m) + "|" + to_string(time.y);
        return time_get;
    }
    int get_tc()const{
        return tc;
    }
    int get_cursv()const{
        return cur_sv;
    }
    int get_maxsv()const{
        return max_sv;
    }
    int get_tin()const{
        return tc;
    }
    int get_time_int(string x)const{
        if(x == "tiet_dau"){
            return time.tiet_begin;
        }
        if(x == "tiet_cuoi"){
            return time.tiet_end;
        }
        if(x == "d"){
            return time.d;
        }
        if(x == "m"){
            return time.m;
        }
        if(x == "y"){
            return time.y;
        }
        return 3636;
    }
    virtual string get_loai() const = 0; 
    virtual string get_data() const = 0; 
    virtual void nhap() = 0;         /*<-- 2 hàm thực hiện đa hình */
    virtual void hienthi() = 0;    /*  <--- */
    bool ktra_full();
    bool tang_sv();
    bool giam_sv();
    void tusinhma();  /* hàm tự sinh mã, đại khái sẽ tự sinh mã =))*/ 
    void fix_matusinh();
};                             