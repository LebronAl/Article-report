#pragma once
#include<fstream>
#include<iostream>
#include<sstream>
#include<vector>
#include<string>

extern void readInfo(std::string filename, std::vector<std::vector<int>> & info_train);       //读取词向量
extern void readData(std::string filename, std::vector<std::vector<double>> & info_data);       //读取test和train数据
extern void writeResult(std::string filename , std::vector<std::vector<int>>&result);          //输出结果文件