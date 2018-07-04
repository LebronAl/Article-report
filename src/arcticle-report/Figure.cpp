#include"stdafx.h"
#include"Figure.h"
using namespace std;

int cmp(int& x, int& y)
{
	return sim[x] > sim[y];
}

//void getAverage(vector<vector<double>>& average, vector<vector<int>>& info_train, vector<vector<double>>& info_data)
//{
//	for (int i = 0; i < info_train.size(); i++)
//	{
//		vector<double> tempArray(info_data[0].size(), 0);
//		int k = 0, j;
//		for (j = info_train[i][k]; k < info_train[i].size(); )
//		{
//			if (info_data[j].size() == info_data[0].size())               //特征向量少的不统计
//			{
//				for (int z = 0; z < info_data[j].size(); z++)
//				{
//					tempArray[z] += info_data[j][z];
//				}
//			}
//			if (k == info_train[i].size() - 1)
//			{
//				break;
//			}
//			else
//			{
//				j = info_train[i][++k];
//			}
//		}
//		double sum = 0;
//		for (int i = 0; i < tempArray.size(); i++)
//		{
//			sum += tempArray[i] * tempArray[i];
//		}
//		sum = sqrt(sum);
//		for (int i = 0; i < tempArray.size(); i++)
//		{
//			tempArray[i] /= sum;
//		}
//		average.push_back(tempArray);
//		tempArray.clear();
//	}
//}

//double match(int n,int m,std::vector<std::vector<int>> &info_train,vector<vector<double>>& info_data)
//{
//	int k = 0, j;
//	double sum = 0;
//	for (j = info_train[n][k]; k < info_train[n].size(); )
//	{
//		double s = 0;
//		for (int z = 0; z < info_data[j].size(); z++)
//		{
//			s += (info_data[m][z] * info_data[j][z]);
//		}
//		sum += (1 - s);
//		if (k == info_train[n].size() - 1)
//			break;
//		else
//		{
//			j = info_train[n][++k];
//		}
//	}
//	return sum;
//}
//
//
//void figure(vector<vector<int>>&result, vector<vector<int>> info_test, std::vector<std::vector<int>> &info_train,vector<vector<double>>& info_data)
//{
//	for (int i = 0; i < info_test.size(); i++)
//	{
//		vector<int> tempArray;
//		int k = 0, j;
//		for (j = info_test[i][k]; k < info_test[i].size(); )
//		{
//			double s = match(i, j, info_train, info_data);
//			sim.insert(pair<int, double>(j, s));
//			if (k == info_test[i].size() - 1)
//				break;
//			else
//			{
//				j = info_test[i][++k];
//			}
//		}
//		sort(info_test[i].begin(), info_test[i].end(), cmp);
//		tempArray.push_back(i + 1);
//		for (int j = 0; j < 5; j++)
//		{
//			tempArray.push_back(info_test[i][j] + 1);
//		}
//		result.push_back(tempArray);
//		tempArray.clear();
//		sim.clear();
//	}
//}

void getAverage(vector<vector<double>>& average, vector<vector<int>>& info_train, vector<vector<double>>& info_data)
{
	for (int i = 0; i < info_train.size(); i++)
	{
		vector<double> tempArray(info_data[0].size(), 0);
		int k = 0, j;
		for (j = info_train[i][k]; k < info_train[i].size(); )
		{
			for (int z = 0; z < info_data[j].size(); z++)
			{
				tempArray[z] += info_data[j][z];
			}
			if (k == info_train[i].size() - 1)
			{
				break;
			}
			else
			{
				j = info_train[i][++k];
			}
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
		average.push_back(tempArray);
		tempArray.clear();
	}
}

void figure(vector<vector<int>>&result, vector<vector<double>>& average, vector<vector<int>> info_test, vector<vector<double>>& info_data)
{
	for (int i = 0; i < info_test.size(); i++)
	{
		vector<int> tempArray;
		int k = 0, j;
		for (j = info_test[i][k]; k < info_test[i].size(); )
		{
			double s = 0;
			for (int z = 0; z < info_data[j].size(); z++)
			{
				s += (info_data[j][z] * average[i][z]);
			}
			sim.insert(pair<int, double>(j, s));
			if (k == info_test[i].size() - 1)
				break;
			else
			{
				j = info_test[i][++k];
			}
		}
		sort(info_test[i].begin(), info_test[i].end(), cmp);
		tempArray.push_back(i + 1);
		for (int j = 0; j < 5; j++)
		{
			tempArray.push_back(info_test[i][j] + 1);
		}
		result.push_back(tempArray);
		tempArray.clear();
		sim.clear();
	}
}