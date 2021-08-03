// anurag
// lab 2 - searching
// 9/20

#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum { DISPLAY = 1, LINEAR, BINARY, EXIT };

constexpr int ARRSIZE = 3;
constexpr int NUM_TEAM = 10;
constexpr int NUM_MEMBER = 3;

const int TEAMID[NUM_TEAM]{ 100, 101, 102, 103, 104, 105, 106, 107, 108, 109 };

const string TEAMMEMBERS[NUM_TEAM][NUM_MEMBER]
{
	{"Ayo", "Angie", "Shawn"},
	{"Avalon", "Nehemiah", "James"},
	{"Zulekha", "Kyle", "Jay"},
	{"Mickey", "Minnie", "Daisy"},
	{"Donald", "Goofy", "Pluto"},
	{"Huey", "Dewey", "Louie"},
	{"Luke", "Leia", "Han"},
	{"Natasha", "Carol", "Wanda"},
	{"Harry", "Ron", "Hermione"},
	{"May", "Peter", "Mary Jane"}
};

// structure defn
struct Teams
{
	int id{};
	string teams[ARRSIZE];
};

// prototypes
void displayMenu();
int validator(int);
void initialize(vector <Teams>&, const int[], const string[][NUM_MEMBER], int);
void displayTeams(const vector <Teams>&);
void linearSearch(const vector <Teams>&, int);
void binSearch(const vector <Teams>&, int);

int main()
{
	int menuChoice;
	// creating Empty Vector
	vector <Teams> team;

	initialize(team, TEAMID, TEAMMEMBERS, ARRSIZE); // calling func to initialize the team vector

	displayTeams(team); // calling  display team func

	do
	{

		// calling menu func
		displayMenu();

		cout << " Menu Choice: ";
		cin >> menuChoice;

		// calling validator func
		menuChoice = validator(menuChoice);

		switch (menuChoice)
		{
			case DISPLAY:
			{
				displayTeams(team);
				break;
			}

			case LINEAR:
			{
				int teamId{};
				cout << " Enter the team ID to search for: ";
				cin >> teamId;
				cout << endl;

				// calling linearSearch func
				linearSearch(team, teamId);
				break;
			}

			case BINARY:
			{
				int teamId{};
				cout << " Enter the team ID to search for: ";
				cin >> teamId;
				cout << endl;

				// calling binarySearch func
				binSearch(team, teamId);
				break;
			}

			case EXIT:
			{
				cout << " Exiting program!!! " << endl << endl;
				break;
			}

			default:
			{
				cout << " Invalid Choice!!!!" << endl << endl;
			}
		}
	} while (menuChoice != EXIT);

	system("pause");
	return 0;
}


void displayMenu()
{
	cout << "\t1. Display Teams" << endl;
	cout << "\t2. Find Team : Linear Search" << endl;
	cout << "\t3. Find Team : Binary Search" << endl;
	cout << "\t4. Exit" << endl;
	cout << endl;

	return;
}

int validator(int menu)
{
	while (cin.fail() || menu < 0)
	{
		cin.clear();
		cin.ignore(32767, '\n');
		cout << " Invalid choice!! Try Again: ";
		cin >> menu;
	}
	cout << endl;
	return menu;
}

void initialize(vector <Teams>& teams, const int id[], const string members[][NUM_MEMBER], int arrSize)
{
	Teams tempStruct;

	for (int i = 0; i < NUM_TEAM; i++)
	{
		tempStruct.id = id[i];
		for (int j = 0; j < NUM_MEMBER; j++)
		{
			tempStruct.teams[j] = members[i][j];
		}

		teams.push_back(tempStruct); // pushing vector 
	}

}

void  displayTeams(const vector <Teams>& teams)
{
	for (int k = 0; k < teams.size(); k++)
	{
		cout << " Team ID: " << teams[k].id << endl;
		for (int z = 0; z < ARRSIZE; z++)
		{
			cout << " Member " << (z + 1) << " : " << teams[k].teams[z] << endl;
		}
		cout << endl;
	}
	cout << " ------------------------------------------------------------------------------------------------------------------------" << endl;
}

void linearSearch(const vector <Teams>& team, int teamId)
{
	bool found = false;
	int i = 0;
	while (found != true && i < team.size())
	{
		if (team[i].id == teamId)
		{
			cout << " Team found!!! " << endl;
			cout << " Team Id :" << team[i].id << endl;
			for (int j = 0; j < ARRSIZE; j++)
			{
				cout << " Member " << (j + 1) << " : " << team[i].teams[j] << endl;
			}
			found = true;
		}

		i++;
	}

	if (found != true)
	{
		cout << " SORRY!!! Team Not Found " << endl;
	}

	cout << endl;
}

void binSearch(const vector <Teams>& team, int id)
{
	int last = team.size() - 1;
	int first = 0;
	int middle{ 0 };
	bool found = false;
	int i = 0;

	while (found != true && first <= last)
	{
		int middle = (first + last) / 2;

		if (team[middle].id == id)
		{
			cout << " Team found!!! " << endl;
			cout << " Team Id: " << team[middle].id << endl;
			for (int i = 0; i < ARRSIZE; i++)
			{
				cout << " Member " << (i + 1) << " : " << team[middle].teams[i] << endl;
			}
			found = true;

			cout << endl;
		}
		else if (team[middle].id > id)
		{
			last = middle - 1;
		}
		else if (team[middle].id < id)
		{
			first = middle + 1;
		}
	}

	if (found != true)
	{
		cout << " SORRY!!! Team Not Found " << endl << endl;
	}
}