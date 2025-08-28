#include<iostream>
#include"Header.h"
using namespace std;

int main()
{
	vector<stUserData>all_users;

	users_information::ReadDataFromFile(all_users);

	//users_information::PrintUsers(all_users);
	//all_users=users_information::DeleteUser(all_users);
	//system("pause");
	//users_information::PrintUsers(all_users);


	return 0;
}