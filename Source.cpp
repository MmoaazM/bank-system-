#include<iostream>
#include"header2.h"
#include"mutual.h"
using namespace std;

int main()
{
	vector<stUserData>all_users; userchoice choice;

	users_information::ReadDataFromFile(all_users);

 	do
	{	
	    choice = show::mainmenu();
		show::OrganiseProgram(choice, all_users);

	}while (choice != userchoice::Exit);

	users_information::save2file(all_users);
	
	return 0;
}