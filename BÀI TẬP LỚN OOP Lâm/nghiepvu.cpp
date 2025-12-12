#include<iostream>
#include"nghiepvu.h"
using namespace std;
void nghiepvu::them_mon_hoc(string ma_gv,string thoi_gian,string ten_mon,string file_name){
 /* truyền vào hàm có thể là mã gv,... nhưng truyền cả đối tượng cho trực quan */
    giangvien c = ds_gv.tim_giangvien_theo_id(ma_gv);
    Time d = ds_time.tim_kip_hoc_theo_tg(thoi_gian);
    subject e = ds_mon.tim_mon_theo_ten(ten_mon);
    ds_lop.nhap_test(c,d,e,file_name);
 /*    phải thêm mã  lơp shocj vào cho mon, giangvien vs time */
    
}
void nghiepvu::dang_ky_mon_hoc(string id_sv,string ma_lop){
    sinhvien a = ds_sv.tim_sinhvien_theo_id(id_sv);
    couse *b = ds_lop.tim_lop_theo_ma(ma_lop);
    if(b->ktra_full()){
        cout<<"lop hoc da day, khong the dang ky!"<<endl;
        return;
    }
    if(a.add_couse(b)){
        b->tang_sv();
        phieu_dang_ky temp(a,b);
        ds_phieu_dky.push_back(temp);
        cout<<"dang ky mon hoc thanh cong!"<<endl;
    }else{
        cout<<"dang ky mon hoc khong thanh cong!"<<endl;
    }   
}
void nghiepvu::hienthi_ds_lop_hoc(){
    ds_lop.hienthidanhsach();
}
void nghiepvu::hienthi_ds_sv(){
    ds_sv.xuatds();
}   
void nghiepvu::hienthi_ds_gv(){
    ds_gv.hienthids();
}
void nghiepvu::hienthi_ds_mon_hoc(){
    ds_mon.xuatds();
}
void nghiepvu::hienthi_ds_thoi_gian_hoc(){
    ds_time.hienthids();
}
void nghiepvu::hienthi_ds_phieu_dky(){
    cout<<"-------Danh sach phieu dang ky-------"<<endl;
    for(int i = 0;i<ds_phieu_dky.size();i++){
        ds_phieu_dky[i].hien_thi_phieu_dky();
        cout<<"\n";
    }
}
void nghiepvu::nhap_du_lieu_tu_all_file(){
    ds_gv.lay_du_lieu_tu_file("D:/dulieugiangvien.txt");
    ds_time.lay_du_lieu_tu_file("D:/dulieuthoigianhoc.txt");
    ds_mon.lay_du_lieu_tu_file("D:/dulieumonhoc.txt");
    ds_sv.lay_du_lieu_tu_file("D:/dulieusinhvien.txt");
    ds_lop.nhap_du_lieu_tu_file(ds_gv,ds_time,ds_mon,"D:/dulieulophoc.txt");
}
