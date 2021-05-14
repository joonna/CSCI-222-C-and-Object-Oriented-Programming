#include <iostream>
#include <string>
using namespace std;

int main()
{
	string user_input;
	cout << "enter 'x' to exit" << endl;
	while (user_input != "x") {
		cout << "Please enter name of country: ";
		getline(cin, user_input);
		char endch = user_input.back();
		char startch = user_input.front();
		if (endch == 's')
		{
			cout << "les " << user_input << endl;
		}
		else if (user_input == "Belize" || user_input == "Zimbabwe" || user_input == "Zaire" || user_input == "Mozambique" || user_input == "Mexique" || user_input == "Cambodge")
		{
			cout << "le " << user_input << endl;
		}
		else if (startch == 'A' || startch == 'O' || startch == 'E' || startch == 'U' || startch == 'Y' || startch == 'I')
		{
			cout << "l'" << user_input << endl;
		}
		else if (endch == 'e')
		{
			cout << "la " << user_input << endl;
		}
		else
		{
			cout << "le " << user_input << endl;
		}
	}
}