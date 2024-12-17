#include <iostream>
#include <vector>
using namespace std;
void printer() {
	int files;
	cout << "Enter number of files to printed :- ";
	cin >> files;
	cout << "Spooler state: ";
	string spool = "";
	for(int i = 1; i <= files; i++) {
		spool = spool + " File " + to_string(i);
		cout << spool <<endl ;
	}
	cout<<endl;
	cout<<"Printer state"<<endl;
	for(int i = 1; i <= files; i++) {
		spool = " File " + to_string(i);
		cout << spool <<endl;
	}
}
void reader() {
	vector<string> list;
	while(true) {
		cout <<"\n Select user type :- \n"<<endl;
		cout<<"0:Writer "<<endl;
		cout<<"1:Reader "<<endl;
		cout<<"2:END Program"<<endl;
		cout<<"3:Exit Critical Section "<<endl;

		int input;
		cin >> input;
		string rc = "";
		if(input == 1) {
			rc = "Reader";
		}
		if(input == 0) {
			rc = "Writer";
		}
		if(list.size() == 0) {
			list.push_back(rc);
			cout << "[ " << rc << " ]" << endl;
			continue;
		}
		if(input == 3) {
			list.erase(list.begin());
			for(int i = 0; i < list.size(); i++) {
				cout << list[i] << " ";
			}
			continue;
		}
		if(input == 2) {
			break;
		} else {
			if(list[0] == "Writer") {
				cout << "No process can enter in Critical Section \n";
			}
			if(list[0] == "Reader") {
				if(input == 1)

				{
					list.push_back("Reader");

					for(int i = 0; i < list.size(); i++) {
						cout << list[i] << " ";
					}

				} else {
					cout << "Writer cannot enter\n";
				}
				continue;
			}
		}
	}
}
void producer() {
	int produce,consume;
	cout << "Enter the No. of items to be Produced :-";
	cin >> produce;
	cout << "Enter the No. of items to be consumed :-";
	cin >> consume;
	vector<int> plist;
	vector<int> clist;
	cout << "Producer's list:\n";
	for(int i = 0; i < produce; i++) {
		plist.push_back(i);
		for(int j = 0; j < plist.size(); j++) {
			cout << plist[j]+1 << " ";
		}
		cout<<"\n";
	}
	cout << "Consumer's list:\n";
	for(int i = 0; i < consume; i++) {

		clist.push_back(plist[0]);
		plist.erase(plist.begin());
		for(int j = 0; j < plist.size(); j++) {
			cout << plist[j] << " ";
		}
		cout<<"\n";
		if(plist.size() == 0) {
			cout << "NO further item can be consumed as NO more item Produced !"<<endl;;
			break;
		}
	}
}
int main() {
	while(1) {
		int choice=1,process_size=0;
		cout<<" \n Which of the following program do you want to execute :-"<<endl;
		cout<<"1.Readers Writers Problem."<<endl;
		cout<<"2.Producer Consumer Problem."<<endl;
		cout<<"3.Printer Spooler Problem."<<endl;
		cout<<"4.EXIT "<<endl;
		cin>>choice;
		switch(choice) {
			case 1:
				reader();
				break;
			case 2:
				producer();
				break;
			case 3:
				printer();
				break;
			case 4:
				cout<<"Thank you!"<<endl;
				return 0;

			default:
				cout<<"INVALID INPUT!"<<endl;
		}

	}
	return 0;
}
