//=======================================================================================
//　C++
//　課題：ストリーム（出力・入力）
//　名前：柳瀬 拓臣
//=======================================================================================
#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
using namespace std;

int main()
{
	//================================================================
	// 出力
	//================================================================

	// 出力用のテキストファイルをオープン
	ofstream fout("myFile.txt", ios::app);

	// ファイルがオープンできたかどうかチェックする
	//assert(fout.is_open())
	//if (fout.fail())
	//if (!fout)
	if (!fout.is_open())
	{
		// エラー処理
		cout << "ファイルをオープンできませんでした！" << endl;

		// プログラムをエラー終了する
		return 1;
	}

	// ファイルに文字列を書き込む
	fout << "Hello World!" << endl;
	fout << "皆さん、こんにちは！" << endl;

	// ファイルをクローズ
	fout.close();
	cout << "ファイルに書き込みました！" << endl;

	//================================================================
	// 入力
	//================================================================

	string s;

	// 入力用のテキストファイルをオープン
	ifstream fin("myFile.txt");

	// ファイルがオープンできたかどうかチェックする
	//assert(fin.is_open())
	//if (fin.fail)
	//if (!fin)
	if (!fin.is_open())
	{
		// エラー処理
		cout << "ファイルをオープンできませんでした！" << endl;

		// プログラムをエラー終了する
		return 1;
	}

	// ファイルから１行ずつ読み出す
	while (getline(fin, s))
	{
		// 読み出した１行を画面に表示する
		cout << s << endl;
	}

	// ファイルをクローズ
	fin.close();

	//================================================================
	// プログラムを正常終了する
	//================================================================
	return 0;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// オープンモードの指定「 std::ios_base::openmode 」
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// app	  : 各書き込み（出力）の前に、ストリームの最後にシークする。
// ate	  : ストリームのオープン直後に、ストリームの最後にシークする。
// binary : 入出力をバイナリで行う。（テキストモードの反対）
// in	  : 入力のためにオープンする。
// out	  : 出力のためにオープンする。
// trunc  : 既存のストリームをオープンする際に、ストリームの内容を切り詰める。