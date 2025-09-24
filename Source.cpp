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

		if (validation::ValidForUser(choice, all_users[IndexOfUser]))
			show::OrganiseProgram(choice, all_users);
		else
		{
			cout << "--------------------------------------------------------------------------" << endl;
			cout << "\t\tYOU ARE DENIED TO REACH THIS OPTION !!!!!\n";
			cout << "--------------------------------------------------------------------------" << endl;
			cout << "\nContact with you admin to get the permission";

			system("pause>0");
			system("cls");
		}
			


	}while (1);
	
	return 0;
}