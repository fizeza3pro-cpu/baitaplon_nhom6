#include<iostream>
#include<stdlib.h>
#include"nghiepvu.h"
using namespace std;
void nghiepvu::them_mon_hoc(string ma_gv, string ten_mon, string file_name) {
    /* truyền vào hàm có thể là mã gv,... nhưng truyền cả đối tượng cho trực quan */
    giangvien* c = ds_gv.tim_giangvien_theo_id(ma_gv);
    if (c == nullptr) {
        cout << "⚠ Không tìm thấy giảng viên" << endl;
        return;
    }
    subject* e = ds_mon.tim_mon_theo_ten(ten_mon);
    if (e == nullptr) {
        cout << "⚠ Không tìm thấy môn học" << endl;
        return;
    }
    ds_lop.nhap_test(c, e, file_name);
    /*    phải thêm mã  lơp shocj vào cho mon, giangvien vs time */

}
void nghiepvu::dang_ky_lop_hoc(string id_sv, string ma_lop) {
    sinhvien* a = ds_sv.tim_sinhvien_theo_id(id_sv);
    if (a == nullptr) {
        cout << "⚠ Không tìm thấy sinh viên" << endl;
        return;
    }
    couse* b = ds_lop.tim_lop_theo_ma(ma_lop);
    if (b == nullptr) {
        cout << "⚠ Không tìm thấy lớp học" << endl;
        return;
    }
    if (b->ktra_full()) {
        cout << "⚠ Lớp học đã đầy , không thể đăng ký" << endl;
        return;
    }
    if (a->add_couse(b)) {
        b->tang_sv();
        phieu_dang_ky temp(a, b);
        ds_phieu_dky.push_back(temp);
        doi_mau_full(2);
        cout<<"✔ Đăng ký lớp học thành công!"<<endl;
    }else{
        doi_mau_full(4);
        cout<<"❌ Đăng ký môn học không thành công"<<endl;
    }   
    doi_mau_full(7);
}
void nghiepvu::huy_dang_ky_lop_hoc(string id_sv, string ma_lop) {
    sinhvien* a = ds_sv.tim_sinhvien_theo_id(id_sv);
    if (a == nullptr) {
        cout << "Khong tim thay sinh vien!" << endl;
        return;
    }
    couse* b = ds_lop.tim_lop_theo_ma(ma_lop);
    if (b == nullptr) {
        cout << "Khong tim thay lop hoc!" << endl;
        return;
    }
    for (int i = 0; i < ds_phieu_dky.size(); i++) {
        if (ds_phieu_dky[i].checkphieu(a, b)) {
            if (a->delete_couse(b)) {
                ds_phieu_dky.erase(ds_phieu_dky.begin() + i);
                b->giam_sv();
                cout << "huy dang ky thanh cong!";
            }
        }
        else {
            cout << "sinh vien chua dang ky lop nay!";
        }
    }
}
void nghiepvu::hienthi_ds_phieu_dky(){
    cout<<"─────────────────────────────────────LỊCH SỬ ĐĂNG KÝ────────────────────────────────────"<<"\n"<<endl;
    doi_mau_full(6); // Màu vàng cho tiêu đề nổi bật
    cout << "   " << left 
               << setw(19) << "Mã SV" 
               << setw(29) << "Họ và tên" 
               << setw(25) << "Lớp đăng ký" 
               << "Thời gian" << endl;
               doi_mau_full(7); // Trả về màu trắng cho dữ liệu
               cout<<"────────────────────────────────────────────────────────────────────────────────────────"<<endl;
    for(int i = 0;i<ds_phieu_dky.size();i++){
        ds_phieu_dky[i].hien_thi_phieu_dky();
        cout << "\n";
    }
    cout << "────────────────────────────────────────────────────────────────────────────────────────";
}
void nghiepvu::nhap_du_lieu_cho_couse(string file_name) {
    if (ds_lop.nhap_du_lieu_tu_file(ds_gv, ds_mon, file_name)) {
        cout << "nhap du lieu cho couse thanh cong!" << endl;
    }
}
void nghiepvu::thaydoithongtin_couse(string ma_lop, string file_name) {
    couse* lop = ds_lop.tim_lop_theo_ma(ma_lop);
    if (lop == nullptr) {
        cout << "ko tim thay lop hoc!";
    }
    else {
        system("cls");
        cout<<"╭──────────────────────DANH SÁCH THAY ĐỔI───────────────────╮"<<endl;
       cout<<"│"<<""<<setw(59)<<""<<"│"<<endl;
       cout<<"│"<<setw(6)<<""<<"1.Thay đổi giảng viên"<<setw(32)<<""<<"│"<<endl;
       cout<<"│"<<setw(6)<<""<<"2.Thay đổi môn học"<<setw(35)<<""<<"│"<<endl;
       cout<<"│"<<setw(6)<<""<<"3.Thay đổi số lượng sinh viên tối đa"<<setw(17)<<""<<"│"<<endl;
       cout<<"│"<<setw(6)<<""<<"4.Thay đổi thời gian học"<<setw(29)<<""<<"│"<<endl;
       cout<<"│"<<setw(6)<<""<<"Nhập lựa chọn của bạn: "<<setw(30)<<""<<"│"<<endl;
       cout<<"╰───────────────────────────────────────────────────────────╯"<<endl;
       gotoxy(30,6);
       int chose;
       cin>>chose;
       if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout<<"Nhập không hợp lệ!";
        return;
        }
        switch (chose)
        {
        case 1:
        {
            cin.ignore();
            string ma_gv;
            cout << "nhap ma giang vien muon doi: ";
            getline(cin, ma_gv);
            giangvien* gv = ds_gv.tim_giangvien_theo_id(ma_gv);
            if (gv == nullptr) {
                cout << "ko tim thay giang vien ";
            }
            else {
                cout << "THONG TIN GIANG VIEN:" << endl;
                gv->hienthithongtin_gv();
                if (gv == lop->get_gv()) {
                    cout << "giang vien dang day lop nay!";
                }
                else if (gv->kiemtra_trung_lich(lop->get_time())) {
                    cout << "giang vien bi trung lich , ko the doi";
                }
                else {
                    lop->set_giangvien(gv);
                    gv->them_couse_da_day_id(lop->get_ma_lop_hoc());
                    gv->them_lich_day(lop->get_time());
                    cout << "Thay đổi giảng viên thành công!";
                }
            }
        
        break;
        }
        case 2:
        {
            cin.ignore();
            if (lop->get_cur_sv() != 0) {
                cout << "lop da co nguoi dang ky, ko the thay doi mon hoc!";
            }
            else {
                cin.ignore();
                string ten_mon;
                cout << "nhap ten mon muon doi: ";
                getline(cin, ten_mon);
                subject* mon = ds_mon.tim_mon_theo_ten(ten_mon);
                if (mon == nullptr) {
                    cout << "ko ton tai mon hoc!";
                }
                else {
                    cout << "THONG TIN MON HOC: " << endl;
                    cout<<mon;
                    if (lop->get_mon_hoc() == mon) {
                        cout << "lop hoc dang day mon nay, ko the doi!";
                    }
                    else {
                        lop->set_mon(mon);
                        mon->add_ma_lop_hoc(lop->get_ma_lop_hoc());
                        cout << "thay doi mon hoc thanh cong!";
                    }
                }
            }
        }
        break;
        case 3:
        {
            int new_max;
            cout << "nhap so luong sinh vien toi da: ";
            cin >> new_max;
            if (new_max < lop->get_cur_sv()) {
                cout << "ko the duoi hoc sinh vien =))";
            }
            else {
                lop->set_max_sv(new_max);
                cout << "thay doi so luong sinh vien toi da thanh cong";
            }
        }
        break;
        case 4:
        {
            if (lop->get_cur_sv() != 0) {
                cout << "lop da co nguoi dang ky, ko the thay doi thoi gian!";
            }
            else {
                Time new_time;
                cout << "Nhập thời gian học mới: " << endl;
                new_time.nhap();
                giangvien* now = lop->get_gv();
                if (now->kiemtra_trung_lich(new_time)) {
                    cout << "Thời gian mới bị trùng lịch dạy của giảng viên, ko thể đổi!";
                }
                else {
                    lop->set_time(new_time);
                    now->xoa_lich_day(lop->get_time());
                    now->them_lich_day(new_time);
                    cout << "thay doi lich hoc thanh cong!";
                }
                pause();
                break;
            }
        default:
            cout << "Lựa chọn không hợp lệ";
            return;
            break;
        }

    }
    ds_lop.xuat_du_lieu_ra_file(file_name);
    cout<<"Cập nhật dữ liệu vào file thành công"<<endl;
}
} 

void nghiepvu::tim_kiem_lop_hoc(){
       cout<<"╭───────────────────────TÌM KIẾM LỚP HỌC────────────────────╮"<<endl;
       cout<<"│"<<""<<setw(59)<<""<<"│"<<endl;
       cout<<"│"<<setw(6)<<""<<"1.Tìm kiếm lớp học theo môn học"<<setw(22)<<""<<"│"<<endl;
       cout<<"│"<<setw(6)<<""<<"2.Tìm kiếm lớp học theo mã lớp học"<<setw(19)<<""<<"│"<<endl;
       cout<<"│"<<setw(6)<<""<<"3.Tìm kiếm lớp học theo tên giảng viên"<<setw(15)<<""<<"│"<<endl;
       cout<<"│"<<setw(6)<<""<<"4.Tìm kiếm lớp học theo số tín chỉ"<<setw(19)<<""<<"│"<<endl;
       cout<<"│"<<setw(6)<<""<<"Nhập lựa chọn của bạn: "<<setw(30)<<""<<"│"<<endl;
       cout<<"╰───────────────────────────────────────────────────────────╯"<<endl;
       gotoxy(30,6);
       int temp;
       cin>>temp;
       if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout<<"Nhập không hợp lệ!";
        }
       switch (temp)
       {
       case 1:
       {
        system("cls");
        string temp;
        cout<<"Nhập vào tên môn học: "<<endl;
        cout<<"  ╭────────────────────────────────────────────────────────╮"<<endl;
        cout<<"  │"<<left<<setw(58)<<("⌕ ")<<"│"<<endl;
        cout<<"  ╰────────────────────────────────────────────────────────╯"<<endl;
        gotoxy(6,2);
        cin.ignore();
        getline(cin,temp);
        system("cls");
        doi_mau_full(10);
        cout<<"  ╭────────────────────────────────────────────────────────╮"<<endl;
        cout<<"  │"<<left<<setw(58 + getUTF8LenDiff(temp))<<("⌕ " + temp)<<"│"<<endl;
        cout<<"  ╰────────────────────────────────────────────────────────╯"<<endl;
        doi_mau_full(7);
        ds_lop.timkiem_ten(temp);
        break;
       }
       case 2:
       {
        system("cls");
        string temp;
        cout<<"Nhập vào mã lớp học: "<<endl;
        cout<<"  ╭────────────────────────────────────────────────────────╮"<<endl;
        cout<<"  │"<<left<<setw(58)<<("⌕ ")<<"│"<<endl;
        cout<<"  ╰────────────────────────────────────────────────────────╯"<<endl;
        gotoxy(6,2);
        cin.ignore();
        getline(cin,temp);
        system("cls");
        doi_mau_full(10);
        cout<<"  ╭────────────────────────────────────────────────────────╮"<<endl;
        cout<<"  │"<<left<<setw(58 + getUTF8LenDiff(temp))<<("⌕ " + temp)<<"│"<<endl;
        cout<<"  ╰────────────────────────────────────────────────────────╯"<<endl;
        doi_mau_full(7);
        couse *lop_temp = ds_lop.tim_lop_theo_ma(temp);
        if(lop_temp == nullptr){
            cout<<"Không tìm thấy lớp học!";
            break;
        }else{
            lop_temp->hienthi();
        }
        break;
       }
       case 3:
       {
        system("cls");
        string temp;
        cout<<"Nhập vào ID giảng viên: "<<endl;
        cout<<"  ╭────────────────────────────────────────────────────────╮"<<endl;
        cout<<"  │"<<left<<setw(58)<<("⌕ ")<<"│"<<endl;
        cout<<"  ╰────────────────────────────────────────────────────────╯"<<endl;
        gotoxy(6,2);
        cin.ignore();
        getline(cin,temp);
        system("cls");
        doi_mau_full(10);
        cout<<"  ╭────────────────────────────────────────────────────────╮"<<endl;
        cout<<"  │"<<left<<setw(58 + getUTF8LenDiff(temp))<<("⌕ " + temp)<<"│"<<endl;
        cout<<"  ╰────────────────────────────────────────────────────────╯"<<endl;
        doi_mau_full(7);
        hien_thi_lop_hoc_cua_gv(temp);
           break;
       }
       case 4:
       {
          system("cls");
        int temp;
        cout<<"Nhập vào số tín chỉ : "<<endl;
        cout<<"  ╭────────────────────────────────────────────────────────╮"<<endl;
        cout<<"  │"<<left<<setw(58)<<("⌕ ")<<"│"<<endl;
        cout<<"  ╰────────────────────────────────────────────────────────╯"<<endl;
        gotoxy(6,2);
        cin>>temp;    
        if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout<<"Nhập không hợp lệ!";
        cin.ignore();
        break;
        }   
        system("cls");
        doi_mau_full(10);
        cout<<"  ╭────────────────────────────────────────────────────────╮"<<endl;
        cout<<"  │"<<left<<setw(58 + getUTF8LenDiff(to_string(temp)))<<("⌕ " + to_string(temp))<<"│"<<endl;
        cout<<"  ╰────────────────────────────────────────────────────────╯"<<endl;
        doi_mau_full(7);
        ds_lop.hien_thi_lop_theo_tc(temp);
        cin.ignore();
        break;
       }
       
       default:
        break;
       }
}

void nghiepvu::hien_thi_lop_hoc_cua_gv(string ma_gv){
    giangvien *gv_temp = ds_gv.tim_giangvien_theo_id(ma_gv);
        if(gv_temp == nullptr){
        cout<<"Không tồn tại giảng viên";
        return;
        }
        string hocvi;
        if(gv_temp ->get_hoc_vi() == "Tiến Sĩ"){
            hocvi = "TS";
        }else if(gv_temp ->get_hoc_vi() == "Giáo Sư"){
            hocvi ="GS";
        }else if(gv_temp ->get_hoc_vi() == "Phó Giáo Sư"){
            hocvi ="PGS";
        }else if (gv_temp ->get_hoc_vi() == "Thạc Sĩ"){
            hocvi = "ThS";
        }else hocvi = "";
        doi_mau_full(13);
        cout<<"╭──────────────────────────────────────────────────────────────╮"<<endl;
        cout<<"│"<<left<<setw(17)<<""<<setw(48 + getUTF8LenDiff(gv_temp->get_name()))<<("GIẢNG VIÊN  "+hocvi+"."+ gv_temp->get_name())<<"│"<<endl;
        cout<<"│"<<left<<setw(3)<<""<<setw(24)<<("Mã GV:" + gv_temp->get_id())<<setw(39 + getUTF8LenDiff(gv_temp->get_bo_mon()))<<("Bộ môn: " + gv_temp->get_bo_mon())<<"│"<<endl;
        cout<<"╰─────────────────DANH SÁCH LỚP HỌC ĐÃ DẠY─────────────────────╯"<<endl;
        cout<<endl;
        doi_mau_full(7);
        couse * couse_temp;
        for(int i = 0;i<gv_temp->get_size_lop();i++){
            couse_temp = ds_lop.tim_lop_theo_ma(gv_temp ->get_lop(i));
            //ĐOẠN NÀY CHẮC K CẦN CHECK VÌ TRONG VECTOR CHẮC CHẮN LÀ MÃ LỚP TỒN TẠI
            couse_temp->hienthi();
        }
        cout<<"Tìm thấy "<<gv_temp->get_size_lop()<<" kết quả";
}

void nghiepvu::hien_thi_lop_hoc_cua_sv(string ma_sv){
    sinhvien *sv_temp = ds_sv.tim_sinhvien_theo_id(ma_sv);
    if(sv_temp == nullptr){
        cout<<"Không tồn tại sinh viên";
    }else{
        string temp = to_string(sv_temp->get_cur_tc()) + "/" + to_string(sv_temp->get_max_tc());
        doi_mau_full(13);
        cout<<"╭──────────────────────────────────────────────────────────────╮"<<endl;
        cout<<"│"<<left<<setw(17)<<""<<setw(46 + getUTF8LenDiff(sv_temp->get_name()))<<("SINH VIÊN  "+ sv_temp->get_name())<<"│"<<endl;
        cout<<"│"<<left<<setw(3)<<""<<setw(30)<<("Mã SV:" + sv_temp->get_ma())<<setw(39 + getUTF8LenDiff(temp))<<("Số tín chỉ hiện tại: " + temp)<<"│"<<endl;
        cout<<"│"<<left<<setw(3)<<""<<setw(23)<<("Khoá:" +to_string(sv_temp->get_khoa()))<<setw(39 + getUTF8LenDiff(sv_temp->get_chuyen_nganh()))<<("Chuyên ngành: " + sv_temp->get_chuyen_nganh())<<"│"<<endl;
        cout<<"╰─────────────────DANH SÁCH LỚP HỌC ĐÃ ĐĂNG KÝ─────────────────╯"<<endl;
        cout<<endl;
        doi_mau_full(7);
        sv_temp ->hien_thi_lop_da_dky();
        cout<<"Tìm thấy "<<sv_temp->get_lop_size()<<" kết quả"<<endl;
    }
}

void nghiepvu::hien_thi_lop_hoc_cua_mon_hoc(string ma_mon){
    subject *mon_temp = ds_mon.tim_mon_theo_ma(ma_mon);
    if(mon_temp == nullptr){
        cout<<"Không tồn tại môn học";
    }else{
        doi_mau_full(13);
        cout<<"╭──────────────────────────────────────────────────────────────╮"<<endl;
        cout<<"│"<<left<<setw(17)<<""<<setw(48 + getUTF8LenDiff(mon_temp->get_ten()))<<("MÔN HỌC  "+ mon_temp->get_ten())<<"│"<<endl;
        cout<<"│"<<left<<setw(3)<<""<<setw(30)<<("Mã môn:" + mon_temp->get_ma_mon())<<setw(34 + getUTF8LenDiff(to_string(mon_temp->get_tin_chi())))
        <<("Số tín: " + to_string(mon_temp->get_tin_chi()))<<"│"<<endl;
        cout<<"╰───────────────────────DANH SÁCH LỚP HỌC──────────────────────╯"<<endl;
        cout<<endl;
        doi_mau_full(7);
        couse * couse_temp;
        for(int i = 0;i<mon_temp->get_size_lop();i++){
            couse_temp = ds_lop.tim_lop_theo_ma(mon_temp ->get_lop(i));
            //ĐOẠN NÀY CHẮC K CẦN CHECK VÌ TRONG VECTOR CHẮC CHẮN LÀ MÃ LỚP TỒN TẠI
            couse_temp->hienthi();
        }
        cout<<"Tìm thấy "<<mon_temp->get_size_lop()<<" kết quả";
    }
}



