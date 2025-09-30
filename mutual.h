#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<iomanip>



using namespace std;


short IndexOfUser;


enum userchoice { showClientsList = 1, addNewClient,
	deleteClient, upgradeClientInfo, findClient,trans, manageUsers, Exit };

enum entransactions{deposit=1,withdraw,quickwithdraw,show_balances,backto_mainmenu};

enum enoperation {depo=1,withdr};

enum enpermissions { showing,add,dele,
upgrade,find,tran,manage};

struct stUserData
{
	string name;
	string password;
	string id;
	string pincode;
	string phone;
	int balance;
	short permissions=0;
};

