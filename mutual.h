#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<iomanip>



using namespace std;

enum userchoice { showClientsList = 1, addNewClient,
	deleteClient, upgradeClientInfo, findClient,trans, Exit };
enum entransactions{deposit=1,withdraw,show_balances,backto_mainmenu};
enum enoperation {depo=1,withdr};
struct stUserData
{
	string name;
	string id;
	string pincode;
	string phone;
	int balance;
};

