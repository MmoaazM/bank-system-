#pragma once
#include"header2.h"


namespace validation
{
	string LowerTheWord(string& word)
	{
		for (char& letter : word)
		{
			letter=tolower(letter);
		}
		return word;
	}

	string YesAndNo_Validation()
	{
		bool pass = 0;
		string answer;  bool ThereIsDigit = 0;
		do 
		{
			
			getline(cin, answer);

			for (char& letter : answer)
			{
				if (isdigit(letter)||isspace(letter)||ispunct(letter))
				{
					cout << "Wrong input , please write you answer correctly : ";
					ThereIsDigit = 1;
					break;
				}
			}
			if (ThereIsDigit) 
			{
				ThereIsDigit = 0; continue;
			}

			answer = validation::LowerTheWord(answer);
			if (answer != "yes" && answer != "no")
			{
				cout << "Wrong input , please write you answer correctly : ";
			}
			else 
			{
				pass = 1;
			}
		} while (!pass);

		return answer;
		
	}
}



namespace users_information
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

	void PrintUsers(vector<stUserData>& users)
	{
		cout << "\n\t\t\tAll users in the program\n";
		cout << "\t\t      ============================";

		cout << left << setw(16) << "\n\nNAME " << " | "
			<< left << setw(15) << "ID" << " | "
			<< left << setw(15) << "BALANCE" << " | "
			<< left << setw(15) << "PINCODE" << " | "
			<< left << setw(15) << "PHONE" << " | \n";
		cout << "****************************************************************************************\n";


		for (int i = 0;i < users.size();i++)
		{
			cout << left << setw(15) << users[i].name << "| ";
			cout << left << setw(15) << users[i].id << " | ";
			cout << left << setw(15) << users[i].balance << " | ";
			cout << left << setw(15) << users[i].pincode << " | ";
			cout << left << setw(15) << users[i].phone << " | ";
			cout << "\n________________________________________________________________________________________\n\n";
		}
	}

	vector<stUserData> DeleteUser(vector<stUserData>& users)
	{
		string UserId; short index = 0; vector<stUserData>UsersAfterDelete; string again;
		do {
			
			index = handle_clients::find_client( users,UserId);

			cout << "Are you sure you want to delete this user ( yes or no ) ? : ";
			string answer = validation::YesAndNo_Validation();

			if (answer == "yes")
			{
				for (int k = 0;k < users.size();k++)
				{
					if (index != k)
					{
						UsersAfterDelete.push_back(users[k]);
					}
				}
				cout << "The User Has Been Deleted Successfully .";
			}
			else
			{
				continue;
			}

			cout << "\nDo You Want To Delete another user (yes or no ) ? : ";

			again = validation::YesAndNo_Validation();

		} while (again == "yes");

		return UsersAfterDelete;

	}
}












