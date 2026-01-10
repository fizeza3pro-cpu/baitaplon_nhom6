
#include<iostream>
#include<string>
#include"subject.h"
#include"UI.h"
using namespace std;

bool subject::nhap_du_lieu_tu_file(ifstream& f) {
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
    if (a.size() < 4) return false;
    ma_mon_hoc = a[0];
    ten_mon_hoc = a[1];
    so_tin_chi = stoi(a[2]);
    so_buoi = stoi(a[3]);
    return true;
}
//Lâm thêm hàm này
void subject::ghi_du_lieu_vao_file(string file_name){
    ofstream f(file_name,ios::app);
    if (!f.is_open()){
        cout<<"Lỗi không mở đc file!";
        return;
    }
    string line = to_file_string();
    f<<line<<endl;
    cout<<"Cập nhật dữ liệu vào file thành công!";
    f.close();
}

string subject::to_file_string() const {
    // 1. Lưu thông tin cơ bản
    string s = ma_mon_hoc + "|" + ten_mon_hoc + "|" + to_string(so_tin_chi) + "|" + to_string(so_buoi);

    // 2. Lưu nối tiếp các mã lớp học vào sau(Lâm sửa: không cần thiết vì có thể truy xuất lớp học này trong chương trình, ko cần xuất ra file lmj)
    // for (const string& ma : ma_lop_hoc) {
    //     s += "|" + ma;
    // }
    return s;
}

bool subject::xoa_ma_lop_hoc(string ma_lop) {
    for (int i = 0; i < ma_lop_hoc.size(); i++) {
        if (ma_lop_hoc[i] == ma_lop) {
            ma_lop_hoc.erase(ma_lop_hoc.begin() + i);
            //cout << "Đã xóa mã lớp học " << ma_lop << " khỏi danh sách lớp học của môn " << ten_mon_hoc << endl;
            return true;
        }
    }
    return false;
}
    // ===== NẠP CHỒNG TOÁN TỬ =====
    ostream& operator<<(ostream & os, const subject & s) {
        os << "• Mã môn: " << left << setw(15 + getUTF8LenDiff(s.ma_mon_hoc)) << s.ma_mon_hoc
            << "  Tên môn: " << setw(45 + getUTF8LenDiff(s.ten_mon_hoc)) << s.ten_mon_hoc
            << "  Số tín chỉ: " << setw(2) << s.so_tin_chi
            << "  Số buổi: " << setw(2) << s.so_buoi<<endl;

        if (!s.ma_lop_hoc.empty()) {
            doi_mau_full(10);
            os << "  Các lớp đang mở: [ ";
            for (const string& ma : s.ma_lop_hoc)
                os << ma << " ";
            os << "]";
        }else{
        doi_mau_full(12);
        os << "  Các lớp đang mở: [Trống]";
    }
    doi_mau_full(7);
    os<<endl;
    return os;
}

    istream& operator>>(istream & is, subject & s) {
        cin.ignore();
        cout << "Nhập mã môn học: ";
        getline(is, s.ma_mon_hoc);

        cout << "Nhập tên môn học: ";
        getline(is, s.ten_mon_hoc);

        cout << "Nhập số tín chỉ: ";
        is >> s.so_tin_chi;

        cout << "Nhập số buổi học: ";
        is >> s.so_buoi;
        is.ignore();
        return is;
    }

