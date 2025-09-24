#include<iostream>
#include"header2.h"
#include"mutual.h"
using namespace std;

int main()
{
	

	vector<stUserData>all_users; userchoice choice;

	users_information::ReadDataFromFile(all_users);

	IndexOfUser = validation::login(all_users);

	system("cls");

 	do
	{	
	    choice = show::mainmenu();
		/// put here the function () that make sure that option is valid for this user 
		show::OrganiseProgram(choice, all_users);

	}while (1);
	
	return 0;
}