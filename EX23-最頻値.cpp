// 競技プログラミング.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include<math.h>
#include <vector>
#include<algorithm>
#include <map>
using namespace std;

int main() {

	int N;
	cin >> N;

	vector<int> vec(N);
	map<int, int> mode;

	for (int i = 0; i < N; i++) {
		cin >> vec.at(i);
	}

	for (int x : vec) {
		//配列vecの中身を一つずつとりだしてmap変数modeのkeyに同一のものがないか判断
		if (mode.count(x)) {
			//keyが存在するならkeyの中の値(value）をインクリメント
			mode.at(x)++;
		}
		else{
			//ないなら、その配列vecの特定要素で新しくkeyを作り、それが一個あることを示すため1で初期化
			//mode.at(x)は書いてあることはおんなじだが、例えばkey値”3”が存在しないのにkey"3"に数値を代入しようとするとエラーになる
			//mode[x]の書き方は存在しないkeyに代入するときvalueの型の初期値が代入されるのでえらーにならない　
			mode[x] = 1;
		}
	}

	int max_mode = 0;
	int max_key = 0;

	for (int x : vec) {
		if (mode.at(x) > max_mode) {
			max_mode = mode.at(x);
			max_key = x;
		}
	}

	cout << max_key << " " << max_mode << endl;


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
