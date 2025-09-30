#pragma once

#include"mutual.h"

namespace validation
{
	bool ValidForUser(userchoice choice, stUserData& user) /// make it ?!!
	{
		short Choice = pow( 2 , choice - 1);

		return (Choice & user.permissions);
	}

	bool IsExist(vector<stUserData>&users,string name,string ID)
	{
		for (int i = 0;i < users.size();i++)
		{
			if (name == users[i].name && ID == users[i].id)
			{
				return 1;
			}
		}
		return 0;
	}



	short login(vector <stUserData> users)
	{
		cout << "*************************************\n";
		cout << "\t     LOGIN PAGE";
		cout << "\n*************************************\n\n";
		string name; string password;
		while (true)
		{
			cout << "Enter name : "; cin >> name;
			cout << "Enter password : "; cin >> password;

			for (int i = 0;i < users.size();i++)
			{
				if (name == users[i].name && password == users[i].password)
				{
					cout << "\n\nLogin In successfully\nPress any key to continue to the program";
					system("pause>0");
					return i;
				}
			}

			cout << "\nInvalid user data , Enter the data right \n\n";
		}

	}

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

	double valid_choice(double from = 1, double to = 6)
	{

		double choice;
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
	short find_client(vector<stUserData>& usersvec, string id = "",bool InATMmode=false)
	{
		if (InATMmode == true)
		{
			return IndexOfUser;
		}

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
		cout << "PASSWORD : ";cin >> newacc.password;

		system("cls");

		usersvec.push_back(newacc);

	}

}

namespace transactions
{
	void PrintTransactionTable(vector<stUserData>& users,bool InATM_Mode=false)
	{
		system("cls");

	    cout << "\n\t\t=======================================\n";
		cout << "\t\t\tTransactions Table\n";
		cout << "\t\t=======================================\n\n\n";

		if (InATM_Mode == true)
		{

			cout << left << setw(10) << "NAME" << left << setw(10) << "BALANCE"<<endl<<endl;

			cout << left << setw(10) << users[IndexOfUser].name << left << setw(10) << users[IndexOfUser].balance << endl;
			cout << "\n\nPress Any key to continue";
			system("pause>0 ");
			return;
		}

		cout << "|" << left << setw(13) << "NAME"
			<< "|" << left << setw(13) << "ID"
			<< "|" << left << setw(13) << "BALANCE";

		cout << "\n*********************************************************\n";

		int TotalBalance = 0;
		for (stUserData& user : users)
		{
			cout << "|" << left << setw(13) << user.name
				<< "|" << left << setw(13) << user.id
				<< "|" << left << setw(13) << user.balance << endl;
			TotalBalance += user.balance;

			cout << "________________________________________________________" << endl;
		}
		cout << "Total Balance Of all Users : " << TotalBalance << endl;

		cout << "Press Any Key to continue\n";
		system("pause>0 ");
		system("cls");

	}



	void deposit_withdraw(vector<stUserData>& usersvec, enoperation operation)
	{
		system("cls");
		short client_index = handle_clients::find_client(usersvec,"",true);
		double amount = 0;
		cout << "Enter the amount :";
		amount = validation::valid_choice(0, 9999999999999);
		if (operation == enoperation::depo)
		{
			usersvec[client_index].balance += amount;
		}
		else if (operation == enoperation::withdr)
		{
			while (usersvec[client_index].balance < amount)
			{
				cout << "\n you don't have enough money!!\n you have" <<
					usersvec[client_index].balance;
			}
			usersvec[client_index].balance += amount * -1;
		}
	}



	void OrganiseTransactions(entransactions choice, vector<stUserData>&usersvec)
	{
		switch (choice)
		{
		case entransactions::deposit:
			deposit_withdraw(usersvec, depo);

			break;

		case entransactions::withdraw:
			deposit_withdraw(usersvec, withdr);

			break;

		case entransactions::show_balances:
			PrintTransactionTable(usersvec,true);
			break;

		case entransactions::backto_mainmenu:
			break;

		}
	}

	void TransactionsMainMenu(vector<stUserData>&usersvec)
	{
		while (true)
		{
			system("cls");
			short choice;
			cout << "\t===========================================\n";
			cout << "\t\ttransactions menu\n";
			cout << "\t===========================================\n\n";

			cout << "choose your option :-\n";
			cout << "[ 1 ] deposit\n[ 2 ] withdraw\n[ 3 ] Quick withdraw\n[ 4 ] show user balance\n[ 5 ] back to main menu\n";
			cout << "the choice --> ";
			choice = validation::valid_choice(1, 4);

			entransactions UserChoice = (entransactions)choice;

			if (UserChoice == entransactions::backto_mainmenu) 
			{
				system("cls");
				break;
			}

			OrganiseTransactions(UserChoice, usersvec);
		}

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
			data >> user.name >> user.id >> user.balance >> user.pincode >> user.phone>>user.password>>user.permissions;
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
			myfile << client.password << separator;
			myfile << client.permissions << separator;
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

		cout << left << setw(14) << "\n\nNAME " << " | "
			<< left << setw(13) << "ID" << " | "
			<< left << setw(13) << "BALANCE" << " | "
			<< left << setw(13) << "PINCODE" << " | "
			<< left << setw(13) << "PHONE" << " | "
			<< left << setw(13) << "PASSWORD" << " | "
			<< left << setw(13) << "PERMISSIONS" << " | \n";
		cout << "**************************************************************************************************************\n";


		for (int i = 0;i < users.size();i++)
		{
			cout << left << setw(13) << users[i].name << "| ";
			cout << left << setw(13) << users[i].id << " | ";
			cout << left << setw(13) << users[i].balance << " | ";
			cout << left << setw(13) << users[i].pincode << " | ";
			cout << left << setw(13) << users[i].phone << " | ";
			cout << left << setw(13) << users[i].password << " | ";
			cout << left << setw(13) << users[i].permissions << " | ";
			cout << "\n______________________________________________________________________________________________________________\n\n";
		}
		cout << "Press Any Key to continue\n";
		system("pause>0 ");
		system("cls");
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
				if(users[index].name == "admin")
				{
					cout << "\nAdmin can't be deleted\n";
					again = "yes";
					continue;
				}
				else
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
				
			}
			else
			{
				cout << "Do You Want To continue in this page : ";
				string OkContinue = validation::YesAndNo_Validation();

				if (OkContinue == "yes")
				{
					again = "yes";
					continue;
				}
					
				else
				{
					for (int k = 0;k < users.size();k++)
					{
							UsersAfterDelete.push_back(users[k]);
				    }
					break;
				}
					
			}

			cout << "\nDo You Want To Delete another user (yes or no ) ? : ";

			again = validation::YesAndNo_Validation();
			system("cls");
		} while (again == "yes");
		system("cls");
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
				agree = validation::YesAndNo_Validation(1);
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
			system("cls");
		} while (again == "yes");
		system("cls");
		return users;
	}
}

namespace show
{

	void OrganiseProgram(userchoice choice, vector<stUserData>& users)
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
			users_information::save2file(users);

			system("cls");
			cout << "Thanks For Using Bank Program \n\t\t have a nice day :)\n";
			system("pause");

			system("cls");
			IndexOfUser=validation::login(users);
			system("cls");
		}
		else if (choice == userchoice::trans)
		{
			transactions::TransactionsMainMenu(users);

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
		cout << "[ 6 ] Transactions.\n";
		cout << "[ 7 ] logout.\n";
		cout << sep << "\nYour Choice :";
		choice = validation::valid_choice(1,7);
		system("cls");
		return userchoice(choice);
	}

}



