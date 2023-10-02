// 競技プログラミング.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include<math.h>
#include <vector>
#include<algorithm>
#include <map>
#include<string>
#include<bitset>
using namespace std;




// -------------------
// ここから先は変更しない
// -------------------

// 各操作を行う関数を実装する

// AとBに共通して含まれる要素からなる集合を返す
bitset<50> intersection(bitset<50> A, bitset<50> B) {

    return A & B;

}
// AとBのうち少なくとも一方に含まれる要素からなる集合を返す
bitset<50> union_set(bitset<50> A, bitset<50> B) {
    return A | B;
}
// AとBのうちどちらか一方にだけ含まれる要素からなる集合を返す
bitset<50> symmetric_diff(bitset<50> A, bitset<50> B) {
    return A ^ B;
}
// Aから値xを除く
bitset<50> subtract(bitset<50> A, int x) {
    A.set(x, 0);
    return A;
}
// Aに含まれる要素に1を加える(ただし、要素49が含まれる場合は0になるものとする)
bitset<50> increment(bitset<50> A) {
    bitset<50> C = A << 1;
    if (A.test(49)) {
        C.set(0, 1);
    }
    return C;
}
// Aに含まれる要素から1を引く(ただし、要素0が含まれる場合は49になるものとする)
bitset<50> decrement(bitset<50> A) {
    bitset<50> C = A >> 1;
    if (A.test(0)) {
        C.set(49, 1);
    }
    return C;
}

// Sに値xを加える
bitset<50> add(bitset<50> S, int x) {
    S.set(x, 1);  // xビット目を1にする
    return S;
}

// 集合Sの内容を昇順で出力する(スペース区切りで各要素の値を出力する)
void print_set(bitset<50> S) {
    vector<int> cont;
    for (int i = 0; i < 50; i++) {
        if (S.test(i)) {
            cont.push_back(i);
        }
    }
    for (int i = 0; i < cont.size(); i++) {
        if (i > 0) cout << " ";
        cout << cont.at(i);
    }
    cout << endl;
}

// これより下は書き換えない

int main() {
    bitset<50> A, B;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        A = add(A, x);
    }
    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int x;
        cin >> x;
        B = add(B, x);
    }

    // 操作
    string com;
    cin >> com;

    if (com == "intersection") {
        print_set(intersection(A, B));
    }
    else if (com == "union_set") {
        print_set(union_set(A, B));
    }
    else if (com == "symmetric_diff") {
        print_set(symmetric_diff(A, B));
    }
    else if (com == "subtract") {
        int x;
        cin >> x;
        print_set(subtract(A, x));
    }
    else if (com == "increment") {
        print_set(increment(A));
    }
    else if (com == "decrement") {
        print_set(decrement(A));
    }
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
