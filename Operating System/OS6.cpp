#include <stdio.h>
#include <vector>

#include<bits/stdc++.h>
using namespace std;

int main() {
	int head=0,count=0,trackcount=0;
	cout<<"Enter the current position of R/W Head :-"<<endl;
	cin>>head;
	cout<<"Enter the total no. of tracks present in the Disc :-"<<endl;
	cin>>count;
	cout<<"Enter the total no. of tracks to be read in the Disc :-"<<endl;
	cin>>trackcount;

	vector<int> track(trackcount);
	cout<<"Enter the tracks to be read in the Disc :-";
	for(int i=0; i<trackcount; i++) {
		cin>>track[i];
	}
	while(1) {

		int choice=1;
		cout<<" \n Which of the following Disc Scheduling Algorithm would do you want to execute :- \n"<<endl;
		cout<<"1.FCFS \n"<<endl;
		cout<<"2.SSTF \n"<<endl;
		cout<<"3.SCAN \n"<<endl;
		cout<<"4.C-SCAN \n"<<endl;
		cout<<"5.LOOK \n"<<endl;
		cout<<"6.C-LOOK \n"<<endl;
		cout<<"7.EXIT \n"<<endl;
		cin>>choice;
		if(choice==1) {
			int diff=0,prev=head;
			cout<<"\n The sequence of Execution of Tracks :-"<<endl;
			for(int i=0; i<trackcount; i++) {
				cout<<track[i]<<" ";
				diff+=abs(track[i]-prev);
				prev=track[i];
			}
			cout<<"\n Total Difference :-"<<diff<<endl;
		} else if(choice==2) {
			int diff=0,prev=head;
			int i=0;
			sort(track.begin(),track.end());
			while(i<trackcount) {
				if(head>track[i]) {
					i++;
				}

				else if(head<track[i]) {
					i--;
					break;
				} else {
					break;
				}
			}
			cout<<"\n The sequence of Execution of Tracks :-"<<endl;
			int j=i+1;
			while((i>=0)&&(j<trackcount)) {
				if(abs(track[i]-prev)>abs(track[j]-prev)) {
					cout<<track[j]<<" ";
					diff+=abs(track[j]-prev);
					prev=track[j++];
				} else {
					cout<<track[i]<<" ";
					diff+=abs(track[i]-prev);
					prev=track[i--];
				}
			}
			while(i>=0) {
				cout<<track[i]<<" ";
				diff+=abs(track[i]-prev);
				prev=track[i--];
			}
			while(j<trackcount) {
				cout<<track[j]<<" ";
				diff+=abs(track[j]-prev);
				prev=track[j++];
			}
			cout<<"\n Total Difference :-"<<diff<<endl;
		} else if(choice==3) {

			int diff=0,prev=head;
			int i=0;
			sort(track.begin(),track.end());
			while(i<trackcount) {
				if(head>track[i]) {
					i++;
				} else if(head<track[i]) {
					i--;
					break;
				} else {
					break;
				}
			}
			cout<<"\n The sequence of Execution of Tracks :-"<<endl;
			for(int j=i; j>=0; j--) {
				cout<<track[j]<<" ";
				diff+=abs(track[j]-prev);
				prev=track[j];
			}
			diff+=abs(prev-0);
			prev=0;
			cout<<"0"<<" ";
			for(int j=i+1; j<trackcount; j++) {
				cout<<track[j]<<" ";
				diff+=abs(track[j]-prev);
				prev=track[j];
			}
			cout<<"\n Total Difference :-"<<diff<<endl;
		} else if(choice==4) {
			int diff=0,prev=head;
			int i=0;
			sort(track.begin(),track.end());
			while(i<trackcount)

			{
				if(head>track[i]) {
					i++;
				} else if(head<track[i]) {
					i--;
					break;
				} else {
					break;
				}
			}
			cout<<"\n The sequence of Execution of Tracks :-"<<endl;
			for(int j=i+1; j<trackcount; j++) {
				cout<<track[j]<<" ";
				diff+=abs(track[j]-prev);
				prev=track[j];
			}
			diff+=abs(count-prev-1);
			prev=count-1;
			cout<<count<<" ";
			diff+=abs(prev-0);
			prev=0;
			cout<<"0"<<" ";
			for(int j=0; j<=i; j++) {
				cout<<track[j]<<" ";
				diff+=abs(track[j]-prev);
				prev=track[j];
			}



			cout<<"\n Total Difference :-"<<diff<<endl;
		} else if(choice==5) {
			int diff=0,prev=head;
			int i=0;
			sort(track.begin(),track.end());

			while(i<trackcount) {
				if(head>track[i]) {
					i++;
				} else if(head<track[i]) {
					i--;
					break;
				} else {
					break;
				}
			}
			cout<<"\n The sequence of Execution of Tracks :-"<<endl;
			for(int j=i; j>=0; j--) {
				cout<<track[j]<<" ";
				diff+=abs(track[j]-prev);
				prev=track[j];
			}
			for(int j=i+1; j<trackcount; j++) {
				cout<<track[j]<<" ";
				diff+=abs(track[j]-prev);
				prev=track[j];
			}
			cout<<"\n Total Difference :-"<<diff<<endl;
		} else if(choice==6) {
			int diff=0,prev=head;
			int i=0;
			sort(track.begin(),track.end());
			while(i<trackcount) {
				if(head>track[i]) {
					i++;
				} else if(head<track[i])

				{
					i--;
					break;
				} else {
					break;
				}
			}
			cout<<"\n The sequence of Execution of Tracks :-"<<endl;
			for(int j=i+1; j<trackcount; j++) {
				cout<<track[j]<<" ";
				diff+=abs(track[j]-prev);
				prev=track[j];
			}

			for(int j=0; j<=i; j++) {
				cout<<track[j]<<" ";
				diff+=abs(track[j]-prev);
				prev=track[j];
			}
			cout<<"\n Total Difference :-"<<diff<<endl;
		} else if(choice==7) {
			cout<<"Thank you! \n"<<endl;
			break;
		} else {
			cout<<"INVALID INPUT!\n"<<endl;
		}

	}

	return 0;
}

