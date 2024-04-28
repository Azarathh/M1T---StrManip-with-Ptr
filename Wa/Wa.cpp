/*
This C++ program demonstrates string manipulation with the following functions ::
[1] Find string length
[2] Compare strings
[3]	Concatenate strings
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>

//Store strings
struct StringStorage
{
	char string1[50];
	char string2[50];
};

//For a more readable switch
enum MenuChoices
{
	menuExit,  // 0
	strLength, // 1
	strCmp,    // 2
	strCat,    // 3
};


//Function prototypes
void DisplayChoices();
void DisplayExit(const std::string& border);
void InputString(StringStorage* str);
void Length(StringStorage* str, int* length1, int* length2);
void DisplayLength(int* length1, int* length2);
void Compare(StringStorage* str, int* res);
void DisplayCompare(int* res);
void Concat(StringStorage* str);
void DisplayConcat(StringStorage* str);
void ProcessDecision(char& decision, const std::string& border);


int main()
{
	DisplayChoices();
}


void DisplayChoices()
{
	//Struct ptr variable declaration
	StringStorage* str;
	str = new StringStorage();

	//Variable declarations
	std::string border(60, '-');
	int menuChoice, result, len1, len2;
	char decision;

	do
	{

		do
		{
			std::cout << border << '\n' << std::setw(43) << "STRING MANIPULATION MENU \n" << border;
			std::cout
				<< "\nPlease input the corresponding number of your choice :: "
				<< "\n[1] Find the string length"
				<< "\n[2] Compare two strings"
				<< "\n[3] Concatenate two strings"
				<< "\n[0] Exit"
				<< "\n>> ";

			std::cin >> menuChoice;
			
			//If user input != num
			if (std::cin.fail()) {
				std::cin.clear(); //clear error
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //clear buffer
				std::cout << "\a\n<Error :: Invalid input, please enter a number>";
				continue; //restart loop
			}

			//To prevent menuChoice buffer from overlapping InputString
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //clear buffer
			system("pause");
			system("cls");

			switch (menuChoice)
			{
			case strLength:
				InputString(str);
				Length(str, &len1, &len2);
				DisplayLength(&len1, &len2);
				break;

			case strCmp:
				InputString(str);
				Compare(str, &result);
				DisplayCompare(&result);
				break;

			case strCat:
				InputString(str);
				Concat(str);
				DisplayConcat(str);
				break;

			case menuExit:
				DisplayExit(border);
				exit(0); //exit program
				break;

			default:
					std::cout << "\a<Error :: Invalid input, please choose a number between 0 and 3...>\n\n";
					continue; //restart loop
			}
		} while (menuChoice < 0 || menuChoice > 4);

		ProcessDecision(decision, border);
		system("pause");
		system("cls");

	} while (decision == 'Y');

	DisplayExit(border);
}


void DisplayExit(const std::string& border)
{
	std::cout << "Thank you for using this program, now exiting...\n\n" << border;
}


void InputString(StringStorage* str)
{
	std::cout << "Please input string 1 :: ";
	std::cin.getline(str->string1, 50);
	
	std::cout << "Please input string 2 :: ";
	std::cin.getline(str->string2, 50);
 
}


void Length(StringStorage* str, int* length1, int* length2)
{
	//used static_cast to make 'string_t' type compatible to 'int'
	*length1 = static_cast<int>(strlen(str->string1)); 
	*length2 = static_cast<int>(strlen(str->string2));
}


void DisplayLength(int* length1, int* length2)
{
	std::cout
		<< "\nThe length of string 1 is :: " << *length1
		<< "\nThe length of string 2 is :: " << *length2;
}


void Compare(StringStorage* str, int* res)
{
	//Storing result of string1 and string 2 in ptr res
	*res = strcmp(str->string1, str->string2);
}


void DisplayCompare(int* res)
{
	if (*res == 0)
	{
		std::cout << "\nstring 1 and string 2 are equal";
	}
	else
	{
		std::cout << "\nstring 1 and string 2 are NOT equal";
	}
}


void Concat(StringStorage* str)
{
	//Concatenate string 1 and string 2
	strcat_s(str->string1, str->string2);
}


void DisplayConcat(StringStorage* str)
{
	std::cout << "\nThe result is :: " << str->string1;
}


void ProcessDecision(char& decision, const std::string& border)
{
	std::cout << "\n\n" << border << "\nDo you want to try again [Y/N] :: ";
	std::cin >> decision;
	decision = toupper(decision);
}