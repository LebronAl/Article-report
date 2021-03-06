// 第二次数算大作业.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"rwFile.h"
#include"Figure.h"
using namespace std;

map<int, double> sim;

int main()
{
	string filename_train = "user-info-train.txt";
	string filename_test = "user-info-test.txt";
	string filename_article = "feature_article.txt";
	string filename_result = "result.txt";

	vector<vector<int>> info_train;
	vector<vector<int>> info_test;
	vector<vector<double>> info_data;

	cout << "读取用户信息中......" << endl;
	readInfo(filename_train, info_train);
	readInfo(filename_test, info_test);

	cout << "读取文章词向量中......" << endl;
	readData(filename_article, info_data);

	cout << "正在计算每个用户的特征向量......" << endl;
	vector<vector<double>> average;
	getAverage(average, info_train, info_data);

	cout << "正在计算推荐结果......" << endl;
	vector<vector<int>> result;
	figure(result,average,info_test,info_data);

	cout << "正在输出结果......" << endl;
	writeResult(filename_result, result);

	cout << "程序结束！" << endl;

	system("pause");
    return 0;
}

