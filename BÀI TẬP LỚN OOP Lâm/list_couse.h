#pragma once
#include<iostream>
#include"online.h"
#include"offline.h"
using namespace std;
class list_couse{
    private:
    int cnt;
    couse *p[100];
    public:
    list_couse(){
        cnt = 0;
        for(int i = 0;i<100;i++){
            p[i] = nullptr;
        }
    }
    void nhapdanhsach(string file_name);
    void xuatdanhsach();
    bool timkiem_ten(string ten_mon);
    bool timkiem_ma(string ma);
    void nhapfile(string file_name );
    couse * getp(int i){
        return p[i];
    }
    friend class dangky_couse;
    friend class tkb;
};