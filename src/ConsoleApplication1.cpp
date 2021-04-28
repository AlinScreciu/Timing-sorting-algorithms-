#include "sorts.h"
using namespace std;

int main()
{	
		fstream fp("times.csv", std::ios::out);
		fp << "sort name,data type,size,time,\n";
		fp.close();
		for (int i = 0; i < 50; i++)
		{
			int a, b, size;
			string name;
			a = dataset[i].find_last_of('_');
			b = dataset[i].find_last_of('.');
			size = stoi(dataset[i].substr(a + 1, b - a));
			name = dataset[i].substr(0, a);
			int* arr = new int[size];
			fstream temp("dataset/" + dataset[i], std::ios::in);
			int j = 0;
			while (temp >> arr[j]) 
			{
				j++;
			}
			temp.close();
			write_to_file(size, name, arr);
			delete[] arr;
			
		}
	return 0;
}
