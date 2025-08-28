#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<fstream>

using namespace std;

struct stUserData
{
	string name;
	string id;
	string pincode;
	unsigned int phone;
	int balance;
};

namespace users_informations
{
	void ReadDataFromFile(vector<stUserData>&users)
	{
		stUserData user;
		string All_Data_ofUser;
		ifstream read_file("users_data.txt"),data("users_data.txt");
		if (!read_file.is_open())
		{
			cout << "Error opening file";
			return;
		}
		while (getline(read_file, All_Data_ofUser))
		{
			data >> user.name >> user.id >> user.balance >> user.pincode >> user.phone;
			users.push_back(user);
		}

	}


	stUserData string_2_struct(string dataline,string separator=" ")
	{
		stUserData st_data;
		vector<string>data;
		string single_data;
		while (short pos = dataline.find(separator) != string::npos)
		{
		    single_data = dataline.substr(0,pos);
			data.push_back(single_data);
			dataline.erase(0,pos);
		}
		data[5] = single_data;
		st_data.name = data[0];
		st_data.id= data[1];
		st_data.pincode= data[2];
		st_data.phone= stoi(data[3]);
		st_data.balance= stoi(data[4]);

		return st_data;
	}
	vector<stUserData> read_data(string filename)
	{
		fstream myfile;
		myfile.open(filename,ios::out|ios::app);
		if (!myfile.is_open())
		{
			cout << "the file doesn't open !!!";
			
		}

		vector<stUserData> vecinfo;
		string lineofData;
		while (getline(myfile >> ws, lineofData))
		{
			vecinfo.push_back(string_2_struct(lineofData));
			lineofData.clear();
		}

		return vecinfo;

	}

}

namespace handle_clients
{

	short find_client(string id,vector<stUserData>& usersvec)
	{
		for (int i=0; i < usersvec.size();i++)
		{
			if (usersvec[i].id == id)
			{
				return i;
			}
		}
		return -1;
	}





}
