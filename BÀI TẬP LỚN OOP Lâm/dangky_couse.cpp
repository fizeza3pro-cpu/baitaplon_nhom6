#include<iostream>
#include<string>
#include"dangky_couse.h"
using namespace std;
bool dangky_couse::dangkymonhoc(string ma_mon,string ma_sv){
    couse *mon = nullptr;
    sinhvien *sv_now = nullptr;
    for(int i = 0;i<ds_mon.cnt;i++){
        if(ds_mon.p[i]->getma_mon_hoc() == ma_mon){
            mon = ds_mon.p[i];
        }
    }
    if(!mon){
        cout<<"ko tim thay mon hoc(loi khoi tao con tro trong dangky_couse)!"<<endl;
        return false;
    }
    for(int i = 0;i< slsv;i++){
        if(sv[i] -> id == ma_sv ){
            sv_now = sv[i];
        }
    }
    if(!sv_now){
        cout<<"ko tim thay sinh vien (loi khoi tao con tro trong dangky_couse)!"<<endl;
        return false;
    }
    if(sv_now->dadangky(ma_mon)){
        cout<<"ban da dang ki mon nay roi"<<endl;
        return false;
    }
    if(sv_now->add_couse(ma_mon,mon->get_tin()) && mon->tang_sv()){
        dsdk[sl_dsdk].masv = ma_sv;
        dsdk[sl_dsdk].ma_mon_dky = ma_mon;
        dsdk[sl_dsdk].trangthai = true;
        sl_dsdk++;
        // cout<<"DANG KY THANH CONG!"<<endl;
        return true;
    }
    // cout<<"Dang ky that bai! "<<endl;
    return false;
}
bool dangky_couse::huymonhoc(string ma_mon,string ma_sv){
    couse *mon = nullptr;
     sinhvien *sv_now = nullptr;
    for(int i = 0;i<ds_mon.cnt;i++){
        if(ds_mon.p[i]->getma_mon_hoc() == ma_mon){
            mon = ds_mon.p[i];
        }
    }
    if(!mon){
        cout<<"ko tim thay mon hoc!"<<endl;
        return false;
    }
    for(int i = 0;i< slsv;i++){
        if(sv[i] -> id == ma_sv ){
            sv_now = sv[i];
        }
    }
    if(!sv_now){
        cout<<"ko tim thay sinh vien (loi khoi tao con tro trong dangky_couse)!"<<endl;
        return false;
    }
    if(!sv_now->dadangky(ma_mon)){
        cout<<"ban chua dang ky mon hoc nay, ko the huy!"<<endl;
        return false;
    }else{
        if(sv_now->delete_couse(ma_mon,mon->get_tin()) && mon ->giam_sv()){
           /*can xuy ly cai dsdk kia o day nhe!*/
           for(int i = 0; i<sl_dsdk;i++){
            if(dsdk[i].ma_mon_dky == ma_mon && dsdk[i].masv == ma_sv){
                for(int j = i;j<sl_dsdk-1;j++){
                    dsdk[j] = dsdk[j+1];
                }
                dsdk[sl_dsdk-1].ma_mon_dky = "";
                dsdk[sl_dsdk-1].masv = "";
                dsdk[sl_dsdk-1].trangthai= false;
                sl_dsdk--;
            }
           }
            return true;
        }
    }
    return false;
}
void dangky_couse::danhsach_mondky(string ma_sv){
    int dem = 0;
     sinhvien *sv_now = nullptr;
    for(int i = 0;i< slsv;i++){
        if(sv[i] -> id == ma_sv ){
            sv_now = sv[i];
        }
    }
    if(!sv_now){
        cout<<"ko tim thay sinh vien (loi khoi tao con tro trong dangky_couse)!"<<endl;
        return;
    }
    for(int i = 0; i< sv_now->so_mon_dky;i++){
        if(ds_mon.timkiem_ma(sv_now->ds_ma_mon_dky[i])){
            dem++;
        }
    }
    cout<<"Da dang ky tong cong "<<dem<<" mon hoc"<<endl;
}
void dangky_couse::add_sv(sinhvien *a){
    sv[0] = a;
    slsv++;
}
void dangky_couse::full_ds_monhoc(string ma_sv){
    sinhvien * sv_now = nullptr;
    couse *mon = nullptr;
    bool check_dky;
    for(int i = 0;i<slsv;i++){
        if(sv[i]->id == ma_sv){
            sv_now = sv[i];
        }
    }
    cout<<"xin chao :"<<sv_now->name<<endl;
    cout<<"---------DANH SACH MON HOC: -------------"<<endl;
    for(int i = 0;i<ds_mon.cnt;i++){
        mon = ds_mon.p[i];
        check_dky = false;
        for(auto &dk : dsdk ){
            if(dk.ma_mon_dky == mon->getma_mon_hoc() && dk.masv == ma_sv && dk.trangthai){
                check_dky = true;
            }
        }
        mon->hienthi();
        if(check_dky){
            cout<<"    Tinh trang: [ DA DANG KY ]  "<<"\t";
        }else{
            cout<<"    Tinh trang: [ CHUA DANG KY ]"<<"\t";;
        }
        if(mon->ktra_full()){
            cout<<"[FULL]"<<endl;
        }else{
             cout<<"[CON TRONG]"<<endl;
        }
        cout<<"\n";
    }
}
void add_sv_file(string data){

}

       



        
        
    

