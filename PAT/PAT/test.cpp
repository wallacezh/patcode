#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;
bool check_valid(string src)
{
	for (size_t i = 0; i < src.size(); ++i)//src�к��зǷ��ַ�
	{
		if (!isdigit(src[i]) && src[i] != '.' && src[i] != '-')
			return false;
	}
	if (src.size())
	{
		if (src[0] == '-')
			src = src.substr(1);
	}
	if (src.size() == 0)
		return false;
	if (src[0] == '.')//û���������֣�����Ƿ�
		return false;

	if (count(src.begin(), src.end(), '.') > 1) //��������С����
		return false;
	else if (count(src.begin(), src.end(), '.') == 0)//û��С����
	{
		if (atoi(src.c_str()) < -1000 || atoi(src.c_str()) > 1000)
			return false;
		else
			return true;
	}
	else//���ҽ���һ��С����
	{
		string r1, r2;
		r1 = src.substr(0, src.find('.'));//��������
		if (src.find('.') < 1 << 30)
			r2 = src.substr(src.find('.') + 1);//С������
		if (r2.size() > 2)//���ȴ���2λ
			return false;
		if (atof(src.c_str()) > 1000.0
			|| atof(src.c_str()) < -1000.0)//�������ݷ�Χ
			return false;
		return true;
	}
}
int main()
{
	std::ios::sync_with_stdio(false);

	size_t cnt, i;
	string src;
	vector<string> v;

	cin >> cnt;
	//    string t[6]={"-","-1.1","0.111",
	//    "1.1.1","-1000","1000.1"};
	//    cnt=6;
	for (i = 0; i < cnt; ++i)
	{
		cin >> src;
		//        src=t[i];
		if (check_valid(src))
			v.push_back(src);
		else
			cout << "ERROR: " << src << " is not a legal number\n";
	}
	double sum = 0;
	for (i = 0; i < v.size(); ++i)
		sum += atof(v[i].c_str());
	if (v.size() > 1)
	{
		printf("The average of %lu numbers is %.2f\n",
			v.size(), sum / v.size());
	}
	else if (v.size() == 1)
		printf("The average of 1 number is %.2f\n", sum);
	else
		cout << "The average of 0 numbers is Undefined" << endl;
	return 0;
}