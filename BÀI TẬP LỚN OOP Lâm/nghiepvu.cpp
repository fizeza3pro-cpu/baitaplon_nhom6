#include<iostream>
#include"nghiepvu.h"
using namespace std;
void nghiepvu::them_mon_hoc(string ma_gv,string ten_mon,string file_name){
 /* truyền vào hàm có thể là mã gv,... nhưng truyền cả đối tượng cho trực quan */
    giangvien* c = ds_gv.tim_giangvien_theo_id(ma_gv);
    if(c == nullptr) cout<<"ko tim thay giang vien"<<endl;
    subject *e = ds_mon.tim_mon_theo_ten(ten_mon);
    if(e == nullptr) cout<<"ko tim thay mon hoc"<<endl;
    ds_lop.nhap_test(c,e,file_name);
 /*    phải thêm mã  lơp shocj vào cho mon, giangvien vs time */
    
}
void nghiepvu::dang_ky_mon_hoc(string id_sv,string ma_lop){
    sinhvien * a = ds_sv.tim_sinhvien_theo_id(id_sv);
     if(a == nullptr){
        cout << "Khong tim thay sinh vien!" << endl;
        return;
    }
    couse *b = ds_lop.tim_lop_theo_ma(ma_lop);
      if(b == nullptr){
        cout << "Khong tim thay lop hoc!" << endl;
        return;
    }
    if(b->ktra_full()){
        cout<<"lop hoc da day, khong the dang ky!"<<endl;
        return;
    }
    if(a->add_couse(b)){
        b->tang_sv();
        phieu_dang_ky temp(a,b);
        ds_phieu_dky.push_back(temp);
        cout<<"dang ky mon hoc thanh cong!"<<endl;
    }else{
        cout<<"dang ky mon hoc khong thanh cong!"<<endl;
    }   
}
void nghiepvu::hienthi_ds_phieu_dky(){
    cout<<"-------Danh sach phieu dang ky-------"<<endl;
    for(int i = 0;i<ds_phieu_dky.size();i++){
        ds_phieu_dky[i].hien_thi_phieu_dky();
        cout<<"\n";
    }
}
void nghiepvu::nhap_du_lieu_cho_couse(string file_name){
    if(ds_lop.nhap_du_lieu_tu_file(ds_gv,ds_mon,file_name)){
        cout<<"nhap du lieu cho couse thanh cong!"<<endl;
    }
}
void nghiepvu::thaydoithongtin_couse(string ma_lop,string file_name){
    couse * lop = ds_lop.tim_lop_theo_ma(ma_lop);
    if(lop == nullptr){
        cout<<"ko tim thay lop hoc!";
    }else{
        int chose;
        cout<<"1.thay doi giang vien"<<endl;
        cout<<"2.thay doi mon hoc"<<endl;
        cout<<"3.thay doi so luong sinh vien toi da"<<endl;
        cout<<"4.thay doi thoi gian hoc"<<endl;
        cout<<"Lua chon cua ban: ";
        cin>>chose;
        switch (chose)
        {
        case 1:
        {
            cin.ignore();
            string ma_gv;
            cout<<"nhap ma giang vien muon doi: ";
            getline(cin,ma_gv);
            giangvien *gv = ds_gv.tim_giangvien_theo_id(ma_gv);
            if(gv == nullptr){
                cout<<"ko tim thay giang vien ";
            }else{
                cout<<"THONG TIN GIANG VIEN:"<<endl;
                gv->hienthithongtin();
                if(gv == lop->get_gv()){
                    cout<<"giang vien dang day lop nay!";
                }else if(gv->kra_trung_lich(lop->get_time())){
                    cout<<"giang vien bi trung lich , ko the doi";
                }else{
                    lop->set_giangvien(gv);
                    gv->them_couse_da_day_id(lop->get_ma_lop_hoc());
                    cout<<"thay doi giang vien thanh cong";
            }
            
        } 
    }
            break;
        case 2:
        {
        if(lop->get_cur_sv() != 0 ){
            cout<<"lop da co nguoi dang ky, ko the thay doi mon hoc!";
        }else{
            cin.ignore();
            string ten_mon;
            cout<<"nhap ten mon muon doi: ";
            getline(cin,ten_mon);
            subject *mon = ds_mon.tim_mon_theo_ten(ten_mon);
            if(mon == nullptr){
                cout<<"ko ton tai mon hoc!";
            }else{
                cout<<"THONG TIN MON HOC: "<<endl;
                mon->hienthithongtin();
                if(lop->get_mon_hoc() == mon){
                    cout<<"lop hoc dang day mon nay, ko the doi!";
                }else{
                    lop->set_mon(mon);
                    mon->add_ma_lop_hoc(lop->get_ma_lop_hoc());
                    cout<<"thay doi mon hoc thanh cong!";
                }   
            }
        }
    }
            break;
        case 3:
        {
        int new_max;
        cout<<"nhap so luong sinh vien toi da: ";
        cin>>new_max;
        if(new_max < lop->get_cur_sv()){
            cout<<"ko the duoi hoc sinh vien =))";
        }else{
            lop->set_max_sv(new_max);
            cout<<"thay doi so luong sinh vien toi da thanh cong";
        }
    }
            break;
        case 4:
        {
         if(lop->get_cur_sv() != 0 ){
            cout<<"lop da co nguoi dang ky, ko the thay doi thoi gian!";
        }else{
            Time new_time;
            cout<<"nhap thoi gian hoc moi: "<<endl;
            new_time.nhap();
            giangvien *now = lop->get_gv();
            if(now->kra_trung_lich(new_time)){
                cout<<"thoi gian moi bi trung lich giang vien, ko the doi";
            }else{
                lop->set_time(new_time);
                now->xoa_lich_day(lop->get_time());
                now->them_lich_day(new_time);
                cout<<"thay doi lich hoc thanh cong!";
            }      
            break;
        }
        default:
        cout<<"lua cho khong hop le";
            break;
        }

    }
}
    ds_lop.xuat_du_lieu_ra_file(file_name);
    cout<<"cap nhat du lieu vao file thanh cong"<<endl;
}