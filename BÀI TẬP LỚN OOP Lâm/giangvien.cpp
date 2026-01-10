#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include"giangvien.h"
#include"UI.h"
using namespace std;
// void giangvien::nhapthongtin() {
//     cout << "\n=== NHAP THONG TIN GIANG VIEN ===\n";

//     // Nhập tên giảng viên
//     cout << "Nhap ten giang vien: ";
//     getline(cin, ten_giang_vien);

//     // Nhập giới tính với kiểm tra
//     while (true) {
//         cout << "Nhap gioi tinh (Nam/Nu): ";
//         getline(cin, gioi_tinh);
//         if (gioi_tinh == "Nam" || gioi_tinh == "Nu" ||
//             gioi_tinh == "nam" || gioi_tinh == "nu") {
//             // Chuẩn hóa: viết hoa chữ cái đầu
//             gioi_tinh[0] = toupper(gioi_tinh[0]);
//             break;
//         }
//         cout << "Gioi tinh khong hop le! Vui long nhap lai.\n";
//     }

//     // Nhập ngày sinh với kiểm tra
//     cout << "--- Nhap ngay sinh ---\n";

//     // Nhập năm
//     while (true) {
//         cout << "Nam sinh (1950-2005): ";
//         cin >> birth[2];
//         if (birth[2] >= 1950 && birth[2] <= 2005) break;
//         cout << "Nam sinh khong hop le! Vui long nhap lai.\n";
//     }

//     // Nhập tháng
//     while (true) {
//         cout << "Thang sinh (1-12): ";
//         cin >> birth[1];
//         if (birth[1] >= 1 && birth[1] <= 12) break;
//         cout << "Thang sinh khong hop le! Vui long nhap lai.\n";
//     }

//     // Nhập ngày với kiểm tra theo tháng
//     while (true) {
//         cout << "Ngay sinh: ";
//         cin >> birth[0];

//         bool hop_le = true;
//         if (birth[0] < 1) {
//             hop_le = false;
//         }
//         else {
//             // Kiểm tra ngày theo tháng
//             int ngay_max;
//             if (birth[1] == 4 || birth[1] == 6 || birth[1] == 9 || birth[1] == 11) {
//                 ngay_max = 30;
//             }
//             else if (birth[1] == 2) {
//                 // Kiểm tra năm nhuận
//                 bool nam_nhuan = (birth[2] % 4 == 0 && birth[2] % 100 != 0) ||
//                     (birth[2] % 400 == 0);
//                 ngay_max = nam_nhuan ? 29 : 28;
//             }
//             else {
//                 ngay_max = 31;
//             }

//             if (birth[0] > ngay_max) {
//                 hop_le = false;
//                 cout << "Thang " << birth[1] << " chi co toi da " << ngay_max << " ngay!\n";
//             }
//         }

//         if (hop_le) break;
//         cout << "Ngay sinh khong hop le! Vui long nhap lai.\n";
//     }

//     cin.ignore();  // Xóa bộ đệm
//     cout << "nhap hoc vi giang vien: ";
//     getline(cin, hoc_vi);
//     while (true) {
//         cout << "\nNhap so dien thoai (10-11 so): ";
//         getline(cin, sdt);

//         // Kiểm tra chỉ chứa số
//         bool valid = true;
//         for (char c : sdt) {
//             if (!isdigit(c)) {
//                 valid = false;
//                 break;
//             }
//         }

//         if (valid && sdt.length() >= 10 && sdt.length() <= 11) {
//             break;
//         }
//         cout << "So dien thoai khong hop le! Vui long nhap lai.\n";
//     }
//     cin.ignore();
//     cout << "nhap bo mon giang vien: ";
//     getline(cin, bo_mon);
// }

void giangvien::nhapthongtin() {
    cout << "\n--- NHAP THONG TIN GIANG VIEN ---\n";
    cout << "Nhap ID: ";
    getline(cin, id);
    cout << "Nhap ten: ";
    getline(cin, ten_giang_vien);
    cout << "Nhap gioi tinh: ";
    getline(cin, gioi_tinh);
    cout << "Nhap ngay thang nam sinh (cach nhau khoang trang): ";
    cin >> birth[0] >> birth[1] >> birth[2];
    cin.ignore(); // Xóa bộ nhớ đệm sau khi nhập số
    cout << "Nhap hoc vi: ";
    getline(cin, hoc_vi);
    cout << "Nhap so dien thoai: ";
    getline(cin, sdt);
    cout << "Nhap bo mon: ";
    getline(cin, bo_mon);

    //đoạn này là đc rồi, lớp học là do mình toạn, ko nhập đc cho giảng viên đâu
    // nhập couse và lịch dạy tương ứng
    // int n;
    // cout << "Giang vien nay day may lop? ";
    // cin >> n;
    // cin.ignore();

    // for (int i = 0; i < n; i++) {
    //     string ma_lop;
    //     cout << "Nhap ma lop thu " << i + 1 << ": ";
    //     getline(cin, ma_lop);
    //     couse_da_day.push_back(ma_lop);

    //     cout << "-> Nhap lich day cho lop " << ma_lop << ":" << endl;
    //     Time t;
    //     t.nhap(); // Goi ham nhap cua class Time
    //     cin.ignore();
    //     lich_day.push_back(t);
    // }

    // cout << "=> Da luu thong tin giang vien va lich day.\n";
}
//tùng lâm viết lại class hiển thị
void giangvien::hienthithongtin_gv() {
    int card_w = 64;
    string full_title = "[ GIẢNG VIÊN ] " + hoc_vi + ". " + ten_giang_vien;
    string lop_day = "Lớp đang giảng dạy: ";
    if(couse_da_day.empty()){
        lop_day += "TRỐNG";
    }else{
        for(int i = 0;i<couse_da_day.size();i++){
            lop_day += couse_da_day[i] + " ";
        }
    }
    doi_mau_full(11);
    cout << "\n  "<<space() <<  "╭──────────────────────────────────────────────────────────╮"<< endl;
    cout<<space() << "  " <<  "│" << "  ";
    doi_mau_full(14);
    cout << left << setw(card_w - 10+ getUTF8LenDiff(full_title)) << full_title;
    doi_mau_full(11);
    cout << "  " << "│"<< endl;
    cout<<space() << "  ├──────────────────────────────────────────────────────────┤" << endl;
    cout<<space()<< "  " << "│";
    doi_mau_full(7);
    cout << "  ID: " << left << setw(13) << id 
         << "Giới tính: " << left << setw(11 + getUTF8LenDiff(gioi_tinh)) << gioi_tinh 
         << "NS:  " << left << setw(12) << (to_string(birth[0]) + "/" + to_string(birth[1])+ "/" + to_string(birth[2]));
    doi_mau_full(11);
    cout << "│" << endl;
    cout<<space()<< "  " << "│";
    doi_mau_full(7);
    cout << "  Bộ môn: " << left << setw(31 + getUTF8LenDiff(bo_mon)) << bo_mon
         << "SĐT: "+sdt << "  ";
    doi_mau_full(11);
    cout << "│" << endl;
    doi_mau_full(11);
    cout<<space() << "  ├──────────────────────────────────────────────────────────┤" << endl;
    doi_mau_full(10);
    cout<<space() << "  │ "<< left << setw(card_w - 9 + getUTF8LenDiff(lop_day)) << lop_day;
    doi_mau_full(11);
    cout << "  " << "│" << endl;
     cout<<space() << "  ╰──────────────────────────────────────────────────────────╯" << endl;
    doi_mau_full(7); // Trả lại màu gốc
}

void giangvien::hienthi_mondangday() {
    cout << "\n   LICH GIANG DAY CHI TIET: " << ten_giang_vien << endl;
    cout << "========================================================" << endl;

    if (couse_da_day.empty()) {
       cout << "  Hien tai giang vien chua duoc phan cong lop nao." << endl;
    }
    else {
       for (size_t i = 0; i < couse_da_day.size(); i++) {
           cout << " + Lop: " << couse_da_day[i] << endl;
           bool co_lich = false;
           if (i < lich_day.size()) {
               cout << "   -> Buoi hoc: ";
               lich_day[i].hienthithongtin();
               cout << endl;
               co_lich = true;
                }

           if (!co_lich) {
               cout << "   -> (Chua sap xep lich cu the)" << endl;
               }
            }
        }
    }

bool giangvien::nhap_du_lieu_tu_file(ifstream& f) {
    vector<string> a;
    string line;
    string temp = "";
    if (!getline(f, line)) {
        return false;
    }
    if (line.empty()) return false;
    for (char c : line) {
        if (c == '|') {
            a.push_back(temp);
            temp = "";
        }
        else {
            temp += c;
        }
    }
    a.push_back(temp);
    temp = "";
    if (a.size() != 9) return false;
    id = a[0];
    ten_giang_vien = a[1];
    gioi_tinh = a[2];
    hoc_vi = a[3];
    sdt = a[4];
    bo_mon = a[5];
    birth[0] = stoi(a[6]);
    birth[1] = stoi(a[7]);
    birth[2] = stoi(a[8]);
    return true;
}


bool giangvien::kiemtra_trung_lich(Time a) {
    for (int i = 0; i < lich_day.size(); i++) {
        if (lich_day[i].ktra_trung_lich(a))
            return true;
    }
    return false;
}

void giangvien::them_lich_day(Time a) {
    if (!kiemtra_trung_lich(a)) {
        lich_day.push_back(a);
        cout << "Đã thêm lịch thành công!" << endl;
    }
    else cout << "Không thêm được lịch vì đã trùng." <<endl;
}

bool giangvien::xoa_couse_da_day_id(string ma_lop){
    for(int i = 0;i<couse_da_day.size();i++){
        if(couse_da_day[i] == ma_lop){
            couse_da_day.erase(couse_da_day.begin()+i);
            cout<<"Đã xoá lớp học "<<ma_lop<<" khỏi danh sách lớp đã dạy của giảng viên "<<ten_giang_vien<<endl;
            return true;
        }
    }
    return false;
}

bool giangvien::xoa_lich_day(Time a){
    for(int i = 0;i<lich_day.size();i++){
        if(lich_day[i] == a){
            lich_day.erase(lich_day.begin()+i);
            cout<<"Đã xoá lớp học khỏi lịch dạy của giảng viên "<<ten_giang_vien<<endl;
            return true;
        }
    }
    return false;
}
bool giangvien:: check_lop_dang_day(string ma_lop) {
    for (int i = 0; i < couse_da_day.size(); i++) {
        if (couse_da_day[i] == ma_lop) {
            return true;
        }
    }
    return false;
}
void giangvien::them_couse_da_day_id(string ma_lop) {
    for (int i = 0; i < couse_da_day.size(); i++) {
        if (couse_da_day[i] == ma_lop) {
            return;
        }
    }
    couse_da_day.push_back(ma_lop);
    cout << "Đã thêm lớp học " << ma_lop << " vào danh sách môn đã dạy của giảng viên " << ten_giang_vien << endl;
}

void giangvien::ghi_du_lieu_vao_file(ofstream& f) {
    if (f.is_open()) {
        f << id << "|"
            << ten_giang_vien << "|"
            << gioi_tinh << "|"
            << hoc_vi << "|"
            << sdt << "|"
            << bo_mon << "|"
            << birth[0] << "|"
            << birth[1] << "|"
            << birth[2];
        // Không in dấu xuống dòng
    }
}