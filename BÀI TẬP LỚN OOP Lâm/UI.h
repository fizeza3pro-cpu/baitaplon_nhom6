// #pragma once
// #define _HAS_STD_BYTE 0
// #include<iostream>
// #include<conio.h>
// #include<windows.h>
// #include <thread>
// using namespace std;
// // Thay doi kich thuoc cua so console (pixel)
// class ui{
//        enum Color {
//         DEFAULT = 7,
//         GREEN   = 10,
//         RED     = 12,
//         YELLOW  = 14,
//         BLUE    = 9
//     };
//         // 2️⃣ Các hàm static → gọi bằng UI::
//     static void setColor(Color color);
//     static void print(const std::string& text, Color color = DEFAULT);
//     static void println(const std::string& text, Color color = DEFAULT);


// };
// void loading() {
//     cout << "Loading";
//     for(int i=0;i<3;i++){
//         cout << ".";
//         cout.flush();
//         this_thread::sleep_for(chrono::milliseconds(300));
//     }
//     cout<<endl;
// }
// inline void resizeConsole(int width, int height){
//     HWND console = GetConsoleWindow();
//     RECT r;
//     GetWindowRect(console, &r);
//     MoveWindow(console, r.left, r.top, width, height, TRUE);
// }
// void gotoxy(int x, int y) {
//     COORD coord;
//     coord.X = x - 1;
//     coord.Y = y - 1;
    
//     HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
//     SetConsoleCursorPosition(consoleHandle, coord);
// }
// void doi_mau_full(int x) {
//     HANDLE mau;
//     mau = GetStdHandle(STD_OUTPUT_HANDLE);
//     SetConsoleTextAttribute(mau, x);
// }
// void doimau_string(const string& text, int color) {
//     HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//     CONSOLE_SCREEN_BUFFER_INFO csbi;
//     WORD currentColor;
    
//     GetConsoleScreenBufferInfo(hConsole, &csbi);
//     currentColor = csbi.wAttributes;
    
//     SetConsoleTextAttribute(hConsole, color);
//     cout << text;
//     SetConsoleTextAttribute(hConsole, currentColor);
// }
// void doimau_f(int color, const char* format, ...) {
//     HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//     CONSOLE_SCREEN_BUFFER_INFO csbi;
//     WORD currentColor;
    
//     // Lấy màu hiện tại
//     GetConsoleScreenBufferInfo(hConsole, &csbi);
//     currentColor = csbi.wAttributes;
    
//     // Đặt màu mới
//     SetConsoleTextAttribute(hConsole, color);
    
//     // In với định dạng
//     va_list args;
//     va_start(args, format);
//     vprintf(format, args);
//     va_end(args);
    
//     // Trở về màu cũ
//     SetConsoleTextAttribute(hConsole, currentColor);
// }
#pragma once
#include <string>
#include<iomanip>
#include<iostream>

namespace UI {
    enum Color {
        DEFAULT = 7,
        RED = 12,
        GREEN = 10,
        YELLOW = 14
    };
    void doi_mau_full(int x);
    void setColor(Color c);
    void println(const std::string& s, Color c = DEFAULT);
    void drawTitle();
    void chuanhoa(int x);
    int getUTF8LenDiff(std::string s);
};
