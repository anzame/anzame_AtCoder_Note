// 競技プログラミング.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include<math.h>
#include <vector>
#include<algorithm>
#include <map>
#include<string>
using namespace std;

// 以下に、24時間表記の時計構造体 Clock を定義する

// Clock構造体のメンバ変数を書く
//   int hour    時間を表す (0~23の値をとる)
//   int minute  分を表す   (0~59の値をとる)
//   int second  秒を表す   (0~59の値をとる)
struct Clock {
	int hour;
	int minute;
	int second;
	// メンバ関数 set の定義を書く
	//	 関数名: set
	//   引数: int h, int m, int s (それぞれ時、分、秒を表す)
	//   返り値: なし
	//   関数の説明:
	//     時・分・秒を表す3つの引数を受け取り、
	//     それぞれ、メンバ変数 hour, minute, second に代入する
	void set(int h, int m, int s) {
		hour = h;
		minute = m;
		second = s;
	}
	// メンバ関数 to_str の定義を書く
	//   関数名: to_str
	//   引数: なし
	//   返り値: string型
	//   関数の仕様:
	//     メンバ変数が表す時刻の文字列を返す
	//     時刻の文字列は次のフォーマット
	//     "HH:MM:SS"
	//     HH、MM、SSはそれぞれ時間、分、秒を2桁で表した文字列
	string to_str() {
		string to_str_hour;
		string to_str_minute;
		string to_str_second;
		string time_str;

		//1桁の数値に0を付け足して二桁にする
		if (hour < 10) {
			to_str_hour = "0" + to_string(hour);
		}
		else {
			to_str_hour = to_string(hour);
		}

		if (minute < 10) {
			to_str_minute = "0" + to_string(minute);
		}
		else {
			to_str_minute = to_string(minute);
		}

		if (second < 10) {
			to_str_second = "0" + to_string(second);
		}
		else {
			to_str_second = to_string(second);
		}

		time_str = to_str_hour + ":" + to_str_minute + ":" + to_str_second;
		return time_str;
	}
	// メンバ関数 shift の定義を書く
	//   関数名: shift
	//   引数: int diff_second
	//   返り値: なし
	//   関数の仕様:
	//     diff_second 秒だけメンバ変数が表す時刻を変更する(ただし、日付やうるう秒は考えない)
	//     diff_second の値が負の場合、時刻を戻す
	//     diff_second の値が正の場合、時刻を進める
	//     diff_second の値は -86400 ~ 86400 の範囲を取とりうる
	void shift(int diff_second) {
		//diff_secondが0以上かそうでないかで条件分け
		if (diff_second >= 0) {
			while (diff_second > 0) {
				
				//一秒ずつカウント
				diff_second -= 1;
				second += 1;

				//secondが60になったら1分増やして0秒に戻す
				if (second >= 60) {
					second = 0;
					minute += 1;
				}
				//minuiteが60になったら1時間増やして0分に戻す
				if (minute >= 60) {
					minute = 0;
					hour += 1;
				}
				//hourが24になったら0時0分0秒に戻す
				if (hour >= 24) {
					second = 0;
					minute = 0;
					hour = 0;
				}
				
			}
		}
		//diff_secondが負数なら一秒ずつ戻す
		else if (diff_second < 0) {
			while (diff_second < 0) {
				
				//一秒ずつカウント
				diff_second += 1;
				second -= 1;

				//secondがマイナスになったら1分減らして59秒にする
				if (second < 0) {
					second = 59;
					minute -= 1;
				}
				//minuteがマイナスになったら1時間減らして59分にする
				if (minute < 0) {
					minute = 59;
					hour -= 1;
				}
				//hourがマイナスになったら23:59:59にする
				if (hour < 0) {
					second = 59;
					minute = 59;
					hour = 23;
				}
				
			}
		}
	}

};







// -------------------
// ここから先は変更しない
// -------------------

int main() {
	// 入力を受け取る
	int hour, minute, second;
	cin >> hour >> minute >> second;
	int diff_second;
	cin >> diff_second;

	// Clock構造体のオブジェクトを宣言
	Clock clock;

	// set関数を呼び出して時刻を設定する
	clock.set(hour, minute, second);

	// 時刻を出力
	cout << clock.to_str() << endl;

	// 時計を進める(戻す)
	clock.shift(diff_second);

	// 変更後の時刻を出力
	cout << clock.to_str() << endl;
}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
