#include <iostream>
#include <vector>
int main()
{
	std::vector<int*> vec;
	vec.push_back(new int);
	*vec[0]=2;
	int* pval = vec[0];
	vec.clear();
	std::cout<<*pval<<std::endl; // le int n'a pas été delete
	system("pause");
}