#pragma once

#include"mutual.h"

namespace validation
{
	string LowerTheWord(string& word)
	{
		for (char& letter : word)
		{
			letter = tolower(letter);
		}
		return word;
	}

	string YesAndNo_Validation(bool first=0)
	{
		
		bool pass = 0;
		string answer="";  bool ThereIsDigit = 0;
		do
		{
			if (first == 1)
			{
				cin.ignore(numeric_limits<streamsize>::max(), '\n');first = 0;
			}
				
		        getline(cin, answer);
			
		

			for (char& letter : answer)
			{
				if (isdigit(letter) || isspace(letter) || ispunct(letter))
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

	short valid_choice(short from = 1, short to = 6)
	{

		short choice;
		cin >> choice;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(500, '\n');
			cout << "Enter it correctly:";
			cin >> choice;
		}
		while (choice < from || choice > to)
		{
			cout << "Enter it correctly:";
			cin.ignore(500, '\n');
			cin >> choice;
		}
		return choice;

	}
}

namespace handle_clients
{

	short find_client(vector<stUserData>& usersvec, string id = "")
	{
		if (id == "")
		{
			cout << "Choose the ID of user you want : ";
			cin >> id;
		}
		short index = -1;
		do {
			for (int i = 0; i < usersvec.size();i++)
			{
				if (usersvec[i].id == id)
				{
					index = i;
				}
			}
			if (index == -1)
			{
				cout << "No user found ,Enter another id:";
				cin >> id;
			}
		} while (index == -1);

		cout << "NAME : " << usersvec[index].name << endl;
		cout << "ID : " << usersvec[index].id << "\n";
		cout << "BALANCE : " << usersvec[index].balance << "\n";
		cout << "PINCODE : " << usersvec[index].pincode << "\n";
		cout << "PHONE : " << usersvec[index].phone << "\n";

		return index;
	}

	void add_client(vector<stUserData>& usersvec)
	{
		cout << "Please Enter New client information :-\n";
		stUserData newacc;
		cout << "NAME : "; cin >> newacc.name;
		cout << "ID : "; cin >> newacc.id;
		cout << "BALANCE :"; cin >> newacc.balance;
		cout << "PINCODE :"; cin >> newacc.pincode;
		cout << "PHONE : "; cin >> newacc.phone;

		usersvec.push_back(newacc);

	}



}

namespace users_information
{
	void ReadDataFromFile(vector<stUserData>& users)
	{
		stUserData user;
		string All_Data_ofUser;
		ifstream read_file("users_data.txt"), data("users_data.txt");
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

	void save2file(vector<stUserData>& users, string filename = "users_data.txt", string separator = " ")
	{

		fstream myfile;
		myfile.open(filename, ios::out);
		if (!myfile.is_open())
		{
			cout << "the file doesn't open !!!";
		}
		for (stUserData& client : users)
		{
			myfile << client.name << separator;
			myfile << client.id << separator;
			myfile << client.balance << separator;
			myfile << client.phone << separator;
			myfile << client.pincode << separator;
			myfile << endl;
		}

		myfile.close();

	}

	stUserData string_2_struct(string dataline, string separator = " ")
	{
		stUserData st_data;
		vector<string>data;
		string single_data;
		while (short pos = dataline.find(separator) != string::npos)
		{
			single_data = dataline.substr(0, pos);
			data.push_back(single_data);
			dataline.erase(0, pos);
		}
		data[5] = single_data;
		st_data.name = data[0];
		st_data.id = data[1];
		st_data.pincode = data[2];
		st_data.phone = stoi(data[3]);
		st_data.balance = stoi(data[4]);

		return st_data;
	}

	vector<stUserData> read_data(string filename = "users_data.h")
	{

		fstream myfile;
		myfile.open(filename, ios::in);

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
		short index = 0; vector<stUserData>UsersAfterDelete; string again;

		cout << "\t\t\tDeleting Users From Bank .\n\n";

		do {

			index = handle_clients::find_client(users);

			
			cout << "Are you sure you want to delete this user ( yes or no ) ? : ";
			string answer = validation::YesAndNo_Validation(1);

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

	vector<stUserData> UpdateUsers(vector<stUserData>& users)
	{
		short index; string again; string answer; stUserData newdata;
		cout << "\t\t\tUpdating Users In Bank . \n\n";
		do
		{
			index = handle_clients::find_client(users);

			cout << "Are You Want To Change this User's info ( yes or no ) : ";
			answer = validation::YesAndNo_Validation(1);

			if (answer == "yes")
			{
				string agree;

				cout << "Enter the new information of the user .\n";

				cout << "Name : "; cin >> newdata.name;
				cout << "ID : "; cin >> newdata.id;
				cout << "Balance : "; cin >> newdata.balance;
				cout << "Pincode : "; cin >> newdata.pincode;
				cout << "Phone : "; cin >> newdata.phone;

				cout << "Are You Sure You Want To change the information ? ( yes or no ) : ";
				agree = validation::YesAndNo_Validation();
				if (agree == "yes")
				{
					users[index] = newdata;
					cout << "Data Has Been Updated Successfully :) \n\n";
				}
			}
			else
			{
				continue;
			}
			cout << "Do You Want To Change another user information ( yes or no ) : ";
			again = validation::YesAndNo_Validation();

		} while (again == "yes");
		return users;
	}
}

namespace show
{

	void OrgainseProgram(userchoice choice, vector<stUserData>& users)
	{
		if (choice == userchoice::addNewClient)
		{
			handle_clients::add_client(users);
		}
		else if (choice == userchoice::deleteClient)
		{
			users=users_information::DeleteUser(users);
		}
		else if (choice == userchoice::findClient)
		{
			handle_clients::find_client(users);
		}
		else if (choice == userchoice::upgradeClientInfo)
		{
			users=users_information::UpdateUsers(users);
		}
		else if (choice == userchoice::showClientsList)
		{
			users_information::PrintUsers(users);
		}
		else if (choice == userchoice::Exit)
		{
			system("cls");
			cout << "Thanks For Using Bank Program \n\t\t have a nice day :)\n";
			system("pause");
		}
	}

	userchoice mainmenu()
	{
		string sep(50, '*');
		string tab(3, '\t');
		short choice;



		cout << "\n\n" << tab << " Main Menu \n" << sep << endl;

		cout << "[ 1 ] Show cleint list.\n";
		cout << "[ 2 ] Add new client.\n";
		cout << "[ 3 ] Delete client.\n";
		cout << "[ 4 ] Upgrade client info.\n";
		cout << "[ 5 ] Find client.\n";
		cout << "[ 6 ] Exit.\n";
		cout << sep << "\nYour Choice :";
		choice = validation::valid_choice();

		return userchoice(choice);
	}

}

namespace transactions
{
	void PrintTransactionTable(vector<stUserData>& users)
	{
		cout << "\t\t=======================================\n";
		cout << "\t\t\tTransactions Table\n";
		cout << "\t\t=======================================\n\n\n";

		cout << "|" << left << setw(15) << "NAME"
			 << "|" << left << setw(15) << "ID"
			 << "|" << left << setw(15) << "BALANCE";

		cout << "\n*********************************************************\n";

		int TotalBalance = 0;
		for (stUserData& user : users)
		{
			cout << "|" << left << setw(15) << user.name
				 << "|" << left << setw(15) << user.id
				 << "|" << left << setw(15) << user.balance<<endl;
			TotalBalance += user.balance;

			cout << "________________________________________________________" << endl;
		}
		cout << "Total Balance Of all Users : " << TotalBalance<<endl;
	}

	void OrganiseTransactions(entransactions choice, vector<stUserData>& users)
	{
		switch (choice)
		{
		case entransactions::deposit:
			break;

		case entransactions::withdraw:
			break;

		case entransactions::show_balances:
			PrintTransactionTable(users);
			break;

		case entransactions::backto_mainmenu:
			break;
		}
	}

	void TransactionsMainMenu(vector<stUserData>& users)
	{
		while (true)
		{
			short choice;
			cout << "\t===========================================\n";
			cout << "\t\ttransactions menu\n";
			cout << "\t===========================================\n\n";

			cout << "choose your option :-\n";
			cout << "[ 1 ] deposit\n[ 2 ] withdraw\n[ 3 ] show all users balance\n[ 4 ] back to main menu\n";
			cout << "the choice --> "; cin >> choice; validation::valid_choice(1, 4);

			entransactions UserChoice = (entransactions)choice;

			if (UserChoice == entransactions::backto_mainmenu) break;

			OrganiseTransactions(UserChoice,users);
		}
	
	}
}

