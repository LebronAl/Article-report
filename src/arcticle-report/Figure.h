#pragma once
#include<fstream>
#include<iostream>
#include<sstream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>

extern std::map<int, double> sim;  //���������������Ҿ������

extern void getAverage(std::vector<std::vector<double>>& average, std::vector<std::vector<int>>& info_train, std::vector<std::vector<double>> &info_data);         //��ÿ���û���ƽ����������
extern void figure(std::vector<std::vector<int>>&result,std::vector<std::vector<double>>& average,std::vector<std::vector<int>> info_test,std::vector<std::vector<double>>& info_data);           //Ϊÿ���û��Ƽ�5ƪ����