#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<iomanip>



using namespace std;

enum userchoice { showClientsList = 1, addNewClient, deleteClient, upgradeClientInfo, findClient, Exit };
enum entransactions{deposit=1,withdraw,show_balances,backto_mainmenu};

struct stUserData
{
	string name;
	string id;
	string pincode;
	string phone;
	int balance;
};

