#include<iostream>
#include"menu.h"
using namespace std;
void menu_nghiep_vu(list_couse &lop,list_giangvien &gv, list_sinhvien &sv, list_subject &mon,nghiepvu &nv){
    while(1){
    system("cls");
    string space = "                                     ";
    
    doi_mau_full(11); // Màu Cyan
    cout << "\n\n" << space << "╭──────────────────────────────────────────╮" << endl;
    cout << space << "│        HỆ THỐNG QUẢN LÝ ĐĂNG KÝ          │" << endl;
    cout << space << "╰──────────────────────────────────────────╯" << endl;

    doi_mau_full(14); // Màu Vàng cho nhóm 1
    cout << space << "  [ ĐĂNG KÝ HỌC TẬP ]" << endl;
    doi_mau_full(7);
    cout << space << "   1. Đăng ký lớp học" << endl;
    cout << space << "   2. Huỷ đăng ký lớp học" << endl;
    cout << space << "   3. Tìm kiếm lớp học" << endl;
    cout << space << "   11. Lịch sử đăng ký" << endl;

    doi_mau_full(10); // Màu Xanh lá cho nhóm 2
    cout << "\n" << space << "  [ TRA CỨU & HIỂN THỊ ]" << endl;
    doi_mau_full(7);
    cout << space << "   4. Lớp đã đăng ký (Sinh viên)" << endl;
    cout << space << "   5. Lớp đang dạy (Giảng viên)" << endl;
    cout << space << "   6. Lớp theo môn học" << endl;
    cout << space << "   7. Danh sách Lớp học" << endl;
    cout << space << "   8. Danh sách Giảng viên" << endl;
    cout << space << "   9. Danh sách Sinh viên" << endl;
    cout << space << "   10. Danh sách Môn học" << endl;

    doi_mau_full(12); // Màu Đỏ cho mục thoát
    cout << "\n" << space << "   0. THOÁT HỆ THỐNG" << endl;
    
    doi_mau_full(11);
    cout << space << "────────────────────────────────────────────" << endl;
    doi_mau_full(7);
    cout << space << "  Nhập lựa chọn của bạn: ";

    int chose;
    cin>>chose;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout<<"Nhập không hợp lệ!";
         pause();
        continue;
        
    }
    if(chose == 0) break;
    switch (chose){
    case 1:
    {
      system("cls");
      cin.ignore();
      string masv,ma_lop;
      cout<<"Nhập mã sinh viên: ";
      getline(cin,masv);
      cout<<"Nhập mã lớp học: ";
      getline(cin,ma_lop);
      nv.dang_ky_lop_hoc(masv,ma_lop);
      cin.get();
      break;
    }
    case 2:
    {
        system("cls");
        cin.ignore();
        string masv,ma_lop;
        cout<<"Nhập mã sinh viên: ";
        getline(cin,masv);
        cout<<"Nhập mã lớp học: ";
        getline(cin,ma_lop);
        nv.huy_dang_ky_lop_hoc(masv,ma_lop);
        cin.get();
        break;
    }
    case 3:
    {
      system("cls");
      nv.tim_kiem_lop_hoc();
      cin.get();
      break;
    }
    
    case 4:
    {
        system("cls");
        string masv;
        cout<<"Nhập mã sinh viên: ";
        cin.ignore();
        getline(cin,masv);
        system("cls");
        nv.hien_thi_lop_hoc_cua_sv(masv);
        pause();
    break;
    }
    case 5:
    {
        system("cls");
        string magv;
        cout<<"Nhập mã giảng viên: ";
        cin.ignore();
        getline(cin,magv);
        system("cls");
        nv.hien_thi_lop_hoc_cua_gv(magv);
        pause();
      break;
    }
    case 6:
    {
        system("cls");
        string malop;
        cout<<"Nhập mã môn học: ";
        cin.ignore();
        getline(cin,malop);
        system("cls");
        nv.hien_thi_lop_hoc_cua_mon_hoc(malop);
        pause();
      break;
    }
    case 7:
    {
        system("cls");
        lop.hienthidanhsach();
        cin.ignore();
        pause();
        break;
    }
    case 8:
    {
      system("cls");
        gv.hienthids_gv();
        cin.ignore();
        pause();
        break;
        break;
    }
    case 9:
    {
        break;
    }
    case 10:
    {
        system("cls");
        mon.hthi_ds_mon_hoc();
        cin.ignore();
        pause();
        break;
    }

    case 11:
    {
      system("cls");
      nv.hienthi_ds_phieu_dky();
      cin.ignore();
      cin.get();
      break;
    }
    default:
      break;
    }
}
}
void menu_quan_ly(list_couse &lop,list_giangvien &gv, list_sinhvien &sv, list_subject &mon,nghiepvu &nv){
    while(1){
    system("cls");
    string space = "                                     ";

    // --- HEADER QUẢN LÝ ---
    doi_mau_full(12); // Màu Đỏ (Cảnh báo/Admin)
    cout << "\n\n" << space << "╔══════════════════════════════════════════╗" << endl;
    cout << space << "║         BẢNG ĐIỀU KHIỂN QUẢN TRỊ         ║" << endl;
    cout << space << "╚══════════════════════════════════════════╝" << endl;

    // --- CÁC TÙY CHỌN THÊM/XÓA ---
   doi_mau_full(7); // Trắng
    cout << space << "   1. " << left << setw(24) << "Thêm lớp học"    << "2. Xoá lớp học" << endl;
    cout << space << "   3. " << left << setw(20) << "Thay đổi thông tin lớp học"     <<endl;  
   doi_mau_full(11); // Cyan cho Giảng viên
    cout <<"\n" << space << "   4. " << left << setw(23) << "Thêm giảng viên" << "5. Xoá giảng viên" << endl;  
   doi_mau_full(10); // Xanh lá cho Sinh viên
    cout  << space << "   6. " << left << setw(21) << "Thêm sinh viên"  << "7. Xoá sinh viên" << endl;   
   doi_mau_full(14); // Vàng cho Môn học
    cout   << space << "   8. " << left << setw(23) << "Thêm môn học"    << "9. Xoá môn học" << endl;
    // --- FOOTER ---
   doi_mau_full(8); // Màu xám
    cout << "\n" << space << "────────────────────────────────────────────" << endl;
   doi_mau_full(12);
    cout << space << "   0. QUAY LẠI MENU CHÍNH" << endl;
   doi_mau_full(7);
    cout << "\n" << space << "  Lệnh Admin > ";
    int chose;
    cin>>chose;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout<<"Nhập không hợp lệ!";
         pause();
        continue;
    }
    if(chose == 0) break;
    switch (chose)
    {
    case 1:
   {
      system("cls");
      cin.ignore();
      string magv,ten_sub;
      cout<<"nhap ma giang vien: ";
      getline(cin,magv);
      cout<<"nhap ten mon hoc:  ";
      getline(cin,ten_sub);
      nv.them_mon_hoc(magv,ten_sub,"D:/dulieulophoc.txt");
      cin.ignore();
      cin.get();
    break;
}
    case 3:
      {
      system("cls");
      cin.ignore();
      string ma_lop;
      cout<<"nhap ma lop muon sua: ";
      getline(cin,ma_lop);
      cin.ignore();
      nv.thaydoithongtin_couse(ma_lop,"D:/dulieulophoc.txt");
      cin.get();
      break;
    }
    case 2:
    {
      system("cls");
      cin.ignore();
      string ma_lop;
      cout<<"nhap ma lop muon xoa: ";
      getline(cin,ma_lop);
      if(lop.delete_lop_hoc(ma_lop,"D:/dulieulophoc.txt")){
        cout<<"Thanh cong!";
      }else{
        cout<<"ko thanh cong!";
      }
      cin.get();
      break;
    }
    case 4:
    {
      system("cls");
      cin.ignore();
      gv.add_giangvien("D:/dulieugiangvien.txt");
      pause();
      break;
    }
    case 5:
    {
      system("cls");
      string gv_xoa;
      cout<<"Nhập vào mã giảng viên muốn xoá: ";
      cin.ignore();
      getline(cin,gv_xoa);
      if(gv.delete_giangvien(gv_xoa,"D:/dulieugiangvien.txt")){
        cout<<"Xoá giảng viên thành công!";
      }else cout<<"Xoá giảng viên thất bại!";
      pause();
      break;
    }
    case 6:
    {
      break;
    }
    case 7:
    {
      break;
    }
    case 8:
    {
      system("cls");
      mon.add_mon_hoc("D:/dulieumonhoc.txt");
      pause();
      break;
    }
    case 9:
    {
      system("cls");
      string mon_xoa;
      cout<<"Nhập vào mã môn học muốn xoá: ";
      cin.ignore();
      getline(cin,mon_xoa);
      if(mon.xoa_mon_hoc_theo_ma(mon_xoa,"D:/dulieumonhoc.txt")){
        cout<<"Xoá môn học thành công!";
      }else cout<<"Xoá môn học thất bại!";
      pause();
      break;
    }
    default:
        break;
    }
}
}

void menu_chinh(list_couse &lop,list_giangvien &gv, list_sinhvien &sv, list_subject &mon,nghiepvu &nv){
    while(1){
    system("cls");
    doi_mau_full(14);
    drawTitle();
    doi_mau_full(11); // Màu Cyan
    string space = "                                     ";
    cout << space << "╔═══════════════════════════════════════════════╗" << endl;
    cout << space << "║       HỆ THỐNG QUẢN LÝ ĐĂNG KÝ LỚP HỌC        ║" << endl;
    cout << space << "╠═══════════════════════════════════════════════╣" << endl;

    // --- CÁC LỰA CHỌN ---
    doi_mau_full(10); // Xanh lá cho User
    cout << space << "║   [1] NGHIỆP VỤ HỆ THỐNG (Dành cho SV/GV)     ║" << endl;
    cout << space << "║                                               ║" << endl;  
    doi_mau_full(12); // Đỏ/Hồng cho Quản lý
    cout << space << "║   [2] NGHIỆP VỤ QUẢN LÝ (Dành cho Admin)      ║" << endl;
    cout << space << "║                                               ║" << endl;
    doi_mau_full(8); // Xám cho Thoát
    cout << space << "║   [0] THOÁT CHƯƠNG TRÌNH                      ║" << endl;
    cout << space << "║                                               ║" << endl;
    
    doi_mau_full(15); // Trắng
    cout << space << "║  >> Nhập lựa chọn của bạn:                    ║"<<endl;
    doi_mau_full(11);
    cout << space << "╚═══════════════════════════════════════════════╝" << endl;
    gotoxy(66,17);
    int chose;
    cin>>chose;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout<<"Nhập không hợp lệ!";
        pause();
        continue;


    }
    if(chose == 0) break;
    switch (chose)
    {
    case 1:
    menu_nghiep_vu(lop,gv,sv,mon,nv);
        break;
    case 2:
    menu_quan_ly(lop,gv,sv,mon,nv);
        break;
    default:
        break;
    }
}
}
