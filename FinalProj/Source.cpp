#pragma warning(disable : 4996)
#include <iostream>
#include "LinkedList.cpp"
#include <fstream>
#include <ctime>
#include <stack>
#include <string>
using namespace std;

int main() {

	LinkedList<string> Obj;

	int choice = -1;
	string feedbackTxt;
	/*for Background : 0 (black), 1 for blue, 2 for green, 3 for aqua , 5 for purple , 6 for yellow, 7 for white , 8 for gray , 9 for light blue */
    /* for text color : A for (Green),B for (lightaqua), C for (red) ,D for (purple) ,E for (yellow) ,f for (white) */
	system("Color 7D");
	const int y = 80;
	char s[y];
	time_t t = time(0);
	strftime(s, y, "%d/%m/%Y", localtime(&t));
	std::cout <<"\t ****Data: "<< s <<"****"<< '\n';

	while (choice != 0) {
		cout << "\n****** TEXT EDITOR Application *******\n" << endl;
		cout << "Please Select what you want to do.\n1. Add Text At The End of The File." << endl;
		cout << "2. Insert text into Line Number N. \n3. Get Text At a Specific Line Number N." << endl;
		cout << "4. Delete Text At a Specific Line Number N.\n5. Update Line M\n6. Find Line That Contain Text T." << endl;
		cout << "7. Replace First Text with Second Text.\n8. The No of Times a Word W Appears in The Line N." << endl;
		cout << "9. Feedback." << endl;
		cout << "10. Display Data.\n11. Exit From Application." << endl;
		cin >> choice;
		cout << endl;

		//Add Line At the End Of the File
		if (choice == 1) {

			string textInput;
			cout << "Enter Text You Want to Add At the End: ";
			cin.ignore(1);
			getline(cin, textInput);
			textInput += " ";
			Obj.AddAtTail(textInput);
		}

		//Insert Line Fn
		else if (choice == 2) {

			int lineNoInput;
			string textInput;
			cout << "Enter line Number you want to Inserted Text In: ";
			cin >> lineNoInput;
			cout << "Enter Text: ";
			cin.ignore(1);
			getline(cin, textInput);
			textInput += " ";
			Obj.InsertAt(lineNoInput - 1, textInput);
		}

		//Get Line Fn
		else if (choice == 3) {
			int lineNumber;
			cout << "Enter Line number" << endl;
			cin >> lineNumber;
			cout << "text is " << Obj.GettextAt(lineNumber - 1) << endl;
		}

		//Delete Fn
		else if (choice == 4) {
			int lineNoInput;

			cout << "Enter line Number you want to Delete Its Text: ";
			cin >> lineNoInput;

			Obj.DeleteAt(lineNoInput);
		}

		//Update Fn
		else if (choice == 5) {

			int lineNoInput;
			string textInput;
			cout << "Enter line Number you want to Update Its Text: ";
			cin >> lineNoInput;
			cout << "Enter Text: ";
			cin.ignore(1);
			getline(cin, textInput);
			Obj.Update(lineNoInput - 1, textInput);
		}

		//Find Fn
		else if (choice == 6) {

			string textToFind;
			cout << "Enter Text You Want To Find: ";
			cin.ignore(1);
			getline(cin, textToFind);
			Obj.FindAll(textToFind, Obj.numOfLines);
			cout << endl;
		}

		//Replace Fn
		else if (choice == 7) {

			string firstText, secondText;
			cout << "Enter The First Text: ";
			cin.ignore(1);
			getline(cin, firstText);
			cout << "Enter The second Text: ";
			cin.ignore(1);
			getline(cin, secondText);
			Obj.Replace(firstText, secondText);
		}

		//AppearanceCount Fn
		else if (choice == 8) {

			int lineNoInput;
			string wordInput;
			cout << "Enter Line Number: ";
			cin >> lineNoInput;
			cout << "Enter Text: ";
			cin.ignore(1);
			getline(cin, wordInput);
			wordInput += " ";
			if (lineNoInput == 1 || lineNoInput < Obj.numOfLines || lineNoInput == Obj.numOfLines) {
				Obj.AppearanceCount(wordInput, lineNoInput - 1);
			}
		}

		//Feedback Fn
		else if (choice == 9) {
			Obj.Feedback(feedbackTxt);
		}

		//Display Fn
		else if (choice == 10) {
			Obj.DisplayAll();
		}

		//Exit Fn
		else if (choice == 11) {
			Obj.Exit();
		}
	}
	return 0;
}