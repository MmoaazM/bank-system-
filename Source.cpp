#include<iostream>
#include"Header.h"
using namespace std;

int main()
{
	vector<stUserData>all_users;

	users_information::ReadDataFromFile(all_users);
	show::mainmenu();

	all_users=users_information::UpdateUsers(all_users);
	return 0;
}