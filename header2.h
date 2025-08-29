#pragma once

#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<iomanip>


using namespace std;

enum userchoice { showClientsList = 1, addNewClient, deleteClient, upgradeClientInfo, findClient, Exit };


struct stUserData
{
	string name;
	string id;
	string pincode;
	string phone;
	int balance;
};


namespace handle_clients
{

	short find_client( vector<stUserData>& usersvec, string id="")
	{
		if (id == "")
		{
			cout << "Choose the ID of user you want : ";
			cin >> id;
		}
		short index=-1;
		do {
			for (int i = 0; i < usersvec.size();i++)
			{
				if (usersvec[i].id == id)
				{
					index= i;
				}
			}
			if (index == -1)
			{
				cout << "No user found ,Enter another id:";
				cin >> id;
			}
		} while (index==-1);

		cout <<"NAME : " << usersvec[index].name << endl;
		cout <<"ID : " << usersvec[index].id << "\n";
		cout <<"BALANCE : " << usersvec[index].balance << "\n";
		cout <<"PINCODE : "<< usersvec[index].pincode << "\n";
		cout <<"PHONE : " << usersvec[index].phone << "\n";

		return index;
	}






}
namespace show
{



	//transfer it to validation namespace

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
		while (choice < 1 || choice>6)
		{
			cout << "Enter it correctly:";
			cin.ignore(500, '\n');
			cin >> choice;
		}
		return choice;

	}




	///enum userchoice { showClientsList = 1, addNewClient, deleteClient, upgradeClientInfo,
	//findClient, Exit };
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
		choice = valid_choice();

		return userchoice(choice);
	}



}