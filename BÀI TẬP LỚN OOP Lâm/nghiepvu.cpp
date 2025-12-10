#include<iostream>
#include"nghiepvu.h"
using namespace std;
void nghiepvu::them_mon_hoc(giangvien c,Time d,subject e){
 /* truyền vào hàm có thể là mã gv,... nhưng truyền cả đối tượng cho trực quan */
    ds_mon.nhap_test(c,d,e);
    
}
void nghiepvu::dang_ky_mon_hoc(sinhvien &a,couse *b){
    if(b->ktra_full()){
        cout<<"lop hoc da day, khong the dang ky!"<<endl;
        return;
    }
    if(a.add_couse(b)){
        b->tang_sv();
        phieu_dang_ky temp;
        temp.tao_phieu_dky(a,b);
        ds_phieu_dky.push_back(temp);
        cout<<"dang ky mon hoc thanh cong!"<<endl;
    }else{
        cout<<"dang ky mon hoc khong thanh cong!"<<endl;
    }   
}