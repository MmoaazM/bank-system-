#include<iostream>
#include"Header.h"
using namespace std;

int main()
{
	vector<stUserData>all_users;

	users_information::ReadDataFromFile(all_users);
	validation::YesAndNo_Validation();

	


	show::mainmenu();


	handle_clients::find_client(all_users);
	return 0;
}