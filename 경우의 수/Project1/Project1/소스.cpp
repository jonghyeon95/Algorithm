#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
using namespace std;

int func1(vector<int>& vec)
{
	int count = 0;
	vector<string> sto;
	sort(vec.begin(), vec.end());
	do
	{
		string str = "";
		for (int i = 0; i < vec.size(); i++)
		{
			str += to_string(vec[i]);
		}
		sto.push_back(str);
	} while (next_permutation(vec.begin(), vec.end()));

	return sto.size();
}

vector<string> dfs;
set<string> setdgs;
void findfunc(vector<int>& vec, vector<bool> check, int row, vector<int> numvec)
{
	check[row] = true;
	numvec.push_back(vec[row]);

	if (numvec.size() == vec.size())
	{
		string str = "";
		for (int i = 0; i < numvec.size(); i++)
		{
			str += to_string(numvec[i]);
		}
		dfs.push_back(str);
		setdgs.insert(str);
		return;
	}

	for (int i = 0; i < vec.size(); i++)
	{
		if (check[i] == false)
			findfunc(vec, check, i, numvec);
	}
}
int func2(vector<int>& vec)
{
	vector<bool> check(vec.size(), false);
	vector<int> numvec;
	for (int i = 0; i < vec.size(); i++)
	{
		findfunc(vec, check, i, numvec);
	}

	return dfs.size();
}

int main()
{
	vector<int> vec1 = { 1,1,1 };

	cout << func1(vec1) << endl;
	cout << func2(vec1) << endl;
	cout << setdgs.size() << endl;

}