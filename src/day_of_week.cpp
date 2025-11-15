#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdexcept>

using namespace std;

// 画面クリア（クロスプラットフォーム）
void clear_screen() {
#if defined(_WIN32) || defined(_WIN64)
    system("cls");
#else
    system("clear");
#endif
}

// yyyy-mm-dd をパース
void parse_ymd(const string& s, int& y, int& m, int& d) {
    char sep1 = 0, sep2 = 0;
    stringstream ss(s);
    ss >> y >> sep1 >> m >> sep2 >> d;
    if (ss.fail() || sep1 != '-' || sep2 != '-') {
        throw runtime_error("入力形式が不正です。 yyyy-mm-dd の形式で入力してください。");
    }
}

// 閏年判定
bool is_leap(int y) {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

// 月の日数
int days_in_month(int y, int m) {
    static int mdays[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (m == 2) return mdays[1] + (is_leap(y) ? 1 : 0);
    if (m >= 1 && m <= 12) return mdays[m-1];
    return 0;
}

// 日付の有効性
bool valid_date(int y, int m, int d) {
    return (m >= 1 && m <= 12 && d >= 1 && d <= days_in_month(y, m));
}

// 曜日計算（0=日曜）
int day_of_week(int y, int m, int d) {
    static int t[] = {0,3,2,5,0,3,5,1,4,6,2,4};
    if (m < 3) y--;
    return (y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;
}

int main() {
    try {
        clear_screen(); // ← 画面をクリア
        
        cout << "=========================================\n";
        cout << "        2つの日付の曜日比較ツール\n";
        cout << "        （入力形式： yyyy-mm-dd ）\n";
        cout << "=========================================\n\n";

        string a, b;
        cout << "日付A を入力してください : ";
        cin >> a;
        cout << "日付B を入力してください : ";
        cin >> b;

        int y1, m1, d1, y2, m2, d2;
        parse_ymd(a, y1, m1, d1);
        parse_ymd(b, y2, m2, d2);

        if (!valid_date(y1, m1, d1))
            throw runtime_error("日付A が存在しない日付です。");
        if (!valid_date(y2, m2, d2))
            throw runtime_error("日付B が存在しない日付です。");

        int w1 = day_of_week(y1, m1, d1);
        int w2 = day_of_week(y2, m2, d2);

        static vector<string> weekday_jp =
            {"日曜日","月曜日","火曜日","水曜日","木曜日","金曜日","土曜日"};

        cout << "\n-----------------------------------------\n";
        cout << "【判定結果】\n\n";
        cout << "■ 日付A（" << a << "） の曜日 : " << weekday_jp[w1] << "\n";
        cout << "■ 日付B（" << b << "） の曜日 : " << weekday_jp[w2] << "\n\n";

        if (w1 == w2)
            cout << "→ 結果：2つの日付は **同じ曜日** です。\n";
        else
            cout << "→ 結果：2つの日付は **異なる曜日** です。\n";

        cout << "-----------------------------------------\n";

    } catch (const exception& ex) {
        cerr << "\nエラー： " << ex.what() << "\n";
        return 1;
    }

    return 0;
}
