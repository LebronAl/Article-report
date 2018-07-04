#include"stdafx.h"
#include"rwFile.h"
using namespace std;

void readInfo(string filename, vector<vector<int>>& info_train)
{
	ifstream inFile(filename);
	if (inFile.fail())
	{
		cerr << "找不到" << filename << endl;
		exit(-1);
	}
	string lineStr;
	vector<int>tempArray;
	int number = 0;
	while (getline(inFile, lineStr))
	{
		int r = lineStr.find_first_of(',');
		string str = lineStr.substr(0, r);
		stringstream numberTemp;
		numberTemp << str;
		numberTemp >> number;
		if (info_train.size() < number)
		{
			str = lineStr.substr(r + 1);
			numberTemp.clear();
			numberTemp << str;
			numberTemp >> number;
			tempArray.push_back(number - 1);
			info_train.push_back(tempArray);
			tempArray.clear();
		}
		else
		{
			numberTemp.clear();
			str = lineStr.substr(r + 1);
			numberTemp << str;
			numberTemp >> number;
			info_train[info_train.size() - 1].push_back(number - 1);
		}
	}
	inFile.close();
}

void readData(string filename, vector<vector<double>>& info_data)
{
	ifstream inFile(filename);
	if (inFile.fail())
	{
		cerr << "找不到" << filename << endl;
		exit(-1);
	}
	string lineArray;
	vector<double>tempArray;
	double number = 0;
	while (getline(inFile, lineArray))
	{
		stringstream numbersTemp;
		numbersTemp << lineArray;
		string str;
		while (getline(numbersTemp, str, ' '))
		{
			stringstream numberTemp;
			numberTemp << str;
			numberTemp >> number;
			tempArray.push_back(number);
		}
		double sum = 0;
		for (int i = 0; i < tempArray.size(); i++)
		{
			sum += tempArray[i] * tempArray[i];
		}
		sum = sqrt(sum);
		for (int i = 0; i < tempArray.size(); i++)
		{
			tempArray[i] /= sum;
		}
		info_data.push_back(tempArray);
		tempArray.clear();
	}
	//for (int i = 0; i < info_data.size(); i++)
	//{
	//	if (info_data[i].size() != info_data[0].size())
	//		info_data[i].resize(info_data[0].size(), 0);
	//}
	inFile.close();
}

void writeResult(std::string filename, std::vector<std::vector<int>>&result)
{
	ofstream outFile(filename);
	if (outFile.fail())
	{
		cerr << "输出文件出错！" << endl;
		exit(-1);
	}
	for (int i = 0; i < result.size(); i++)
	{
		outFile << result[i][0]<<",";
		for (int j = 1; j < 5; j++)
		{
			outFile << result[i][j] << ";";
		}
		outFile << result[i][5] << endl;
	}
	outFile.close();
}

