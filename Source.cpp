#include<iostream>
#include"Header.h"
using namespace std;

int main()
{
	vector<stUserData>all_users;
	users_informations::ReadDataFromFile(all_users);
	users_informations::PrintUsers(all_users);

	return 0;
}