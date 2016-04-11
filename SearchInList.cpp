#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
vector<string> source_list;

bool find_in_source_list(string item)
{
	for(int i=0;i<source_list.size();i++)
        {
        	if(source_list[i] == item)
			return true;
        }
	return false;
}

int main()
{
	// Populating source data
	fstream input_file;
	input_file.open("input_list.txt");
	while(!input_file.eof())
	{
		string data;
		getline(input_file, data);
		//cout << data << endl;
		source_list.push_back(data);
	}
	input_file.close();
	
	// Printing source data
	cout << "This is source data" << endl;
	for(int i=0;i<source_list.size();i++)
	{
		cout << source_list[i] << ", ";
	}
	cout << endl << endl;

	fstream search_list;
	search_list.open("search_list.txt");
	while(!search_list.eof())
	{
		string search_item;
		getline(search_list,search_item);
		cout << "Searching for item: " << search_item << endl;
		//if(source_list.find(search_item))
		if(find_in_source_list(search_item))
		{
			cout << search_item << " found in source data.";
		}
		cout << endl << endl;
	}

	search_list.close();
	return 0;
}
