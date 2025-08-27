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

}

