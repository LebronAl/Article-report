#pragma once
#include<fstream>
#include<iostream>
#include<sstream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>

extern std::map<int, double> sim;  //将文章索引与余弦距离关联

extern void getAverage(std::vector<std::vector<double>>& average, std::vector<std::vector<int>>& info_train, std::vector<std::vector<double>> &info_data);         //求每个用户的平均特征向量
extern void figure(std::vector<std::vector<int>>&result,std::vector<std::vector<double>>& average,std::vector<std::vector<int>> info_test,std::vector<std::vector<double>>& info_data);           //为每个用户推荐5篇文章