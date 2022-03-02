#include <iostream>	
#include <fstream>
#include <list>

using namespace std;

class PInfoMgmt{
	private:
		struct Student{
			string studentId;
			string name;
			string age;
			string telNumber;
			string race;
			string cppResult;
			string javaResult;
		};
		string path = "1.txt";
		list<Student> studlist;

	public:
		void SaveTemp(){
			ofstream ofst;
    		ofst.open(path, ios::app);//open or create txt
		    if (!ofst)
		        cout << "fail open file" << path << endl;
			ofst.close();
			ifstream ifst;
			ifst.open(path, ios::in);

			char line[50];
			Student temp;

			ifst.getline(line, sizeof(line));//first line 

			while (!ifst.eof()) {

				ifst.getline(line, sizeof(line));
				temp.studentId = line;	
				ifst.getline(line, sizeof(line));
				temp.name = line;	
				ifst.getline(line, sizeof(line));
				temp.age = line;
				ifst.getline(line, sizeof(line));
				temp.race = line;
				ifst.getline(line, sizeof(line));
				temp.telNumber = line;
				ifst.getline(line, sizeof(line));
				temp.cppResult = line;
				ifst.getline(line, sizeof(line));
				temp.javaResult = line;


				studlist.push_back(temp);
			}
			
		}
		bool AddStudent(){
			Student student;
		L1:
			cout << "Enter \"cancel\" to cancel or stop adding student info" << endl;
            cout << "Student ID: ";
			cin >> student.studentId;
			if(student.studentId == "cancel" )
				return false;
			for (list<Student>::const_iterator i = studlist.begin(); i != studlist.end(); i++)
				if (i->studentId == student.studentId) {
					cout << endl << "Student Id already exist, please re-enter student Id." << endl << endl;
					goto L1;
				}
			cout << "Name: ";
			cin >> student.name;
			if (student.name == "cancel") return false;
			cout << "Age: ";
			cin >> student.age;
			if (student.age == "cancel") return false;
			cout << "Race: ";
			cin >> student.race;
			if (student.race == "cancel") return false;
			cout << "Telephone Number: ";
			cin >> student.telNumber;
			if (student.telNumber == "cancel") return false;
			cout << "C++: ";
			cin >> student.cppResult;
			if (student.cppResult == "cancel") return false;
			cout << "Java: ";
			cin >> student.javaResult;
			if (student.javaResult == "cancel") return false;

			cout << endl;
			studlist.push_back(student);

			ofstream ofst;
			ofst.open(path, ios::app);

			ofst << endl << student.studentId << endl << student.name << endl << student.age << endl << student.race << endl << student.telNumber << endl << student.cppResult << endl << student.javaResult;

			ofst.close();
			cout << "success" << endl << endl;
			return true;
		}
		void Menu(){
			cout << "Welcome to Personal Information Management System"<< endl;
			cout << "\n----------------------<MENU>---------------------" << endl;
			cout << "1. Add New Student" << endl;
			cout << "2. Show All Students Information" << endl;
			cout << "3. Exit" << endl;
      cout << "--------------------------------------------------" << endl;
		}
    void PrintMess(){
      cout << endl;
			for (list<Student>::const_iterator it = studlist.begin(); it != studlist.end(); it++) {
				cout << "studentId:" << it->studentId << endl;
				cout << "name:" << it->name << endl;
				cout << "age:" << it->age << endl;
				cout << "race:" << it->race << endl;
				cout << "Telefon Number:" << it->telNumber << endl;
				cout << "C++ Result:" << it->cppResult << endl;
				cout << "Java Result:" << it->javaResult << endl<< endl;
			}
    }
};
int main(){
	PInfoMgmt pim;
	pim.SaveTemp();
	while(true){
		pim.Menu();
		char number = 0;
		cout << "\nEnter the number: ";
		cin >> number;
		switch(number){
			case '1':
				while (pim.AddStudent());
				break;
			case '2':
				pim.PrintMess();
				break;
			case '3':
        cout << "\nThank You For Using Our Personal Information Management!" << endl; 
				return 0;
			default:
				cout << endl << "Please enter valid number." << endl << endl;
				break;
		}
	}
	return 0;
}
