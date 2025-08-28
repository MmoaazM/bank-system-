#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<iomanip>
using namespace std;

struct stUserData
{
	string name;
	string id;
	string pincode;
	string phone;
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

	void PrintUsers(vector<stUserData>& users)
	{
		cout << "\n\t\t\tAll users in the program\n";
		cout << "\t\t      ============================";

		cout <<left << setw(16)  << "\n\nNAME "<<" | "
			 <<left << setw(15)  << "ID"<< " | "
			 <<left << setw(15)  << "BALANCE"<<" | "
			 <<left << setw(15)  << "PINCODE"<<" | "
			 <<left << setw(15)  << "PHONE"<<" | \n";
		cout << "****************************************************************************************\n";


		for (int i = 0;i < users.size();i++)
		{
			cout <<left<< setw(15) << users[i].name << "| ";
			cout << left << setw(15) << users[i].id << " | ";
			cout << left << setw(15) << users[i].balance << " | ";
			cout << left << setw(15) << users[i].pincode << " | ";
			cout << left << setw(15) << users[i].phone << " | ";
			cout << "\n________________________________________________________________________________________\n\n";
		}
	}

	vector<stUserData> DeleteUser(vector<stUserData>& users)
	 {
		string UserId; short index; vector<stUserData> UsersAfterDelete;
		cout << "Choose the ID of user you want to delete : ";  cin >> UserId;
		/// send UserId to find function 
		if (index != -1)
		{
			cout << "Are you sure you want to delete this user ? : ";
		}
		for (int k = 0;k < users.size();k++)
		{
			if (index != k)
			{
				UsersAfterDelete.push_back(users[k]);
			}
		}
		return UsersAfterDelete;

	 }
}

