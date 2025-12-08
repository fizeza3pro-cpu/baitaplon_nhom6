#include<iostream>
#include<string>
#include"thoikhoabieu.h"
using namespace std;
void tkb::taotkb(sinhvien &sv,list_couse &b){
     sl_bh = sv.get_smdk();
        couse * mon = nullptr;
        for(int i = 0;i<sv.get_smdk();i++){
            for(int j = 0;j<b.cnt;j++ ){
                if(sv.get_dsma_mon(i) == b.p[j]->getma_mon_hoc()){
                    mon = b.p[j];
                }
            }
            bh[i].ma_mon_hoc = mon->getma_mon_hoc();
            bh[i].ten_mon_hoc = mon->getten_mon_hoc();
            bh[i].date[0] = mon->get_time_int("d");
            bh[i].date[1] = mon->get_time_int("m");
            bh[i].date[2] = mon->get_time_int("y");
            bh[i].tiet_begin = mon->get_time_int("tiet_dau");
            bh[i].tiet_end = mon->get_time_int("tiet_cuoi");
            bh[i].loai = mon->get_loai();
            bh[i].dia_diem = mon->get_data();
        }
}
void tkb::sapxep(){
    for(int i = 0;i<sl_bh;i++){
        for(int j = 0;j<sl_bh-i-1;j++){
            if(bh[j].date[2]>bh[j+1].date[2]){
                swap(bh[j],bh[j+1]);
            }else if(bh[j].date[2] == bh[j+1].date[2]){
                if(bh[j].date[1]>bh[j+1].date[1]){
                    swap(bh[j],bh[j+1]);
                }else if(bh[j].date[1]==bh[j+1].date[1]){
                    if(bh[j].date[0]>bh[j+1].date[0]){
                    swap(bh[j],bh[j+1]);
                }else if(bh[j].date[0] == bh[j+1].date[0]){
                    if(bh[j].date[0]>bh[j+1].date[0]){
                    swap(bh[j],bh[j+1]);
                }else if(bh[j].tiet_end >bh[j+1].tiet_end){
                    swap(bh[j],bh[j+1]);
                }
            }
        }
    }
}
    }
}
void tkb::hienthi(sinhvien &sv){
    cout<<"\t"<<sv.get_ma()<<"\t"<<sv.get_name()<<"\t"<<"Khoa 60"<<endl;
    cout<<"---------------THOI KHOA BIEU ----------------"<<endl;
    for(int i = 0;i<sl_bh;i++){
        cout<<"[-] Ngay "<<bh[i].date[0]<<" Thang "<<bh[i].date[1]<<" Nam "<<bh[i].date[2]<<"\t"<<"Tiet: "<<bh[i].tiet_begin<<"-"<<bh[i].tiet_end<<endl;
        cout<<"  ("<<bh[i].loai<<")"<<"\t"<<bh[i].ten_mon_hoc<<"\t"<<bh[i].ma_mon_hoc<<"\t"<<bh[i].dia_diem<<endl;
        cout<<"\n";
    }
}