#include<iostream>
#include<fstream>
#include<map>
#include<vector>
#include<stdio.h>
#include<string.h>
using namespace std;

static map< string,vector<string> > location_shop_map;
void loadLocationShopMap()
{
	ifstream mapfile;
	mapfile.open("../../test/LOC_SHOP_MAP.txt");
	if(mapfile.is_open())
	{
		int flag = 0;
		string val;
		string key;
		vector<string> shops;
		while(!mapfile.eof())
		{
			flag = 1;
			getline(mapfile,val);
			char a[100]={};
			for(int i=0;i<val.size();i++)
				a[i] = val[i];
			char *p = strtok(a,",");
			while(p)
			{
				if(flag == 1)
				{
					key = p;
					flag = 0;
				}
				else
					shops.push_back(p);
				p = strtok(NULL,",");
			}
			location_shop_map.insert(std::pair< string,vector<string> >(key,shops));
			shops.clear();
		}


		// Uncomment below to print the map and the vector contents
		/*
		   for(map< string,vector<string> >::iterator ii=location_shop_map.begin(); ii != location_shop_map.end(); ++ii)
		   {
		   cout<<(*ii).first<<endl;
		   vector<string> vals = (*ii).second;
		   for(int i=0;i<vals.size();i++)
		   {
		   cout<<vals[i]<<"\t";
		   }
		   cout<<endl;
		   }
		 */
	}
	mapfile.close();
}

vector<string> getShopsForLocation(string loc)
{
	return location_shop_map.find(loc)->second;
}

int main()
{
	loadLocationShopMap();
	vector<string> vals = getShopsForLocation("BTMLayout");
	for(int i=0;i<vals.size();i++)
	{
		cout<<vals[i];
	}
}
