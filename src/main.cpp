#include "sorts.h"
using namespace std;

int main()
{		
		fstream fp("times.csv", std::ios::out);   //
		fp << "sort name,data type,size,time\n"; // Write the headers of the csv
		fp.close();			          //
		for (int i = 0; i < 50; i++)	          // Iterate over the strings in the dataset array
		{
			int a, b, size;
			string name;
			a = dataset[i].find_last_of('_');     	      //
			b = dataset[i].find_last_of('.');	      // Getting the size of the array to be filled
			size = stoi(dataset[i].substr(a + 1, b - a)); //
			name = dataset[i].substr(0, a);		      // Getting the name of the data type
			int* arr = new int[size];		      // 
			fstream temp("dataset/" + dataset[i], std::ios::in);// 
			int j = 0;					    // 
			while (temp >> arr[j]) 				    // Filling the array with the data.
			{						    // 
				j++;					    // 
			}						    // 
			temp.close();					    // 
			write_to_file(size, name, arr);			    // The timing happens in this function, definition is in sorts.cpp
			delete[] arr;					    // Taking care of memory
			
		}
	return 0;
}
