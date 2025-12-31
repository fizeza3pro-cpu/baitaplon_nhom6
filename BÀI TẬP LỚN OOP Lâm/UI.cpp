#include "ui.h"

// #define NOMINMAX        // tránh xung đột min/max
#undef byte            // 🔥 DÒNG QUAN TRỌNG NHẤT xoá định nghĩa byte của
#include <windows.h>
#include <iostream>
#include <limits>
using namespace std;
// 0 = Black      8 = Gray
// 1 = Blue       9 = Light Blue
// 2 = Green      10 = Light Green
// 3 = Aqua       11 = Light Aqua
// 4 = Red        12 = Light Red
// 5 = Purple     13 = Light Purple
// 6 = Yellow     14 = Light Yellow
// 7 = White      15 = Bright White
// void setColor(Color c) {
//     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
// }

// void println(const std::string& s, Color c) {
//     HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
//     CONSOLE_SCREEN_BUFFER_INFO csbi;
//     GetConsoleScreenBufferInfo(h, &csbi);

//     setColor(c);
//     std::cout << s << std::endl;
//     SetConsoleTextAttribute(h, csbi.wAttributes);
// }
void doi_mau_full(int x) {
    HANDLE mau;
    mau = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(mau, x);
}
void drawTitle(){
    std::cout << R"(

   _____                        ___           _     __           __  _         
  / ___/__  __ _________ ___   / _ \___ ___ _(_)__ / /________ _/ /_(_)__  ___ 
 / /__/ _ \/ // / __(_-</ -_) / , _/ -_) _ `/ (_-</ __/ __/ _ `/ __/ / _ \/ _ \
 \___/\___/\_,_/_/ /___/\__/ /_/|_|\__/\_, /_/___/\__/_/  \_,_/\__/_/\___/_//_/
                                      /___/                                  

)";
}
void chuanhoa(int x){
    SetConsoleOutputCP(x);
    SetConsoleCP(x);
}
int getUTF8LenDiff(std::string s) {
    int diff = 0;
    for (unsigned char c : s) {
        // Trong UTF-8, các byte phụ của ký tự có dấu luôn bắt đầu bằng 10xxxxxx (nhị phân)
        // tương đương với giá trị từ 128 đến 191
        if (c >= 128 && c <= 191) diff++;
    }
    return diff;
}
void gotoxy(int x, int y) {
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
// void form_tim_kiem(string &search){
//         cout<<"  ╭────────────────────────────────────────────────────────╮"<<endl;
//         cout<<"  │"<<left<<setw(58)<<("⌕ ")<<"│"<<endl;
//         cout<<"  ╰────────────────────────────────────────────────────────╯"<<endl;
//         gotoxy(6,2);
//         cin.ignore();
//         getline(cin,search);
//         system("cls");
//         doi_mau_full(10);
//         cout<<"  ╭────────────────────────────────────────────────────────╮"<<endl;
//         cout<<"  │"<<left<<setw(58 + getUTF8LenDiff(search))<<("⌕ " + temp)<<"│"<<endl;
//         cout<<"  ╰────────────────────────────────────────────────────────╯"<<endl;
//         doi_mau_full(7);
// }
void pause() {
    cout << "\nNhan Enter de tiep tuc...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // char c;
    // do {
    //     c = cin.get();
    // } while (c != '\n');
}