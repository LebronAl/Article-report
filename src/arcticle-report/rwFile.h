#pragma once
#include<fstream>
#include<iostream>
#include<sstream>
#include<vector>
#include<string>

extern void readInfo(std::string filename, std::vector<std::vector<int>> & info_train);       //��ȡ������
extern void readData(std::string filename, std::vector<std::vector<double>> & info_data);       //��ȡtest��train����
extern void writeResult(std::string filename , std::vector<std::vector<int>>&result);          //�������ļ�