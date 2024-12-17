
#include<bits/stdc++.h>
using namespace std;

int main() {
	int framesize=0,pagesize=0;
	cout<<"Enter the Number of Frames in the System :- ";
	cin>>framesize;
	cout<<"Enter the Number of Pages to be inserted in the System :- ";
	cin>>pagesize;
	int frame[framesize],page[pagesize];
	for(int i=0; i<framesize; i++) {
		frame[i]=-1;
	}
	cout<<"Enter the order in which Pages are to be inserted :- "<<endl;
	for(int i=0; i<pagesize; i++) {
		cin>>page[i];
	}
	while(1) {
		int choice=1,process_size=0;
		cout<<" \n Which of the following page replacement algorithm do you want to execute :- \n"<<endl;
		cout<<"1.First in First Out. "<<endl;
		cout<<"2.Least Recently Used. "<<endl;
		cout<<"3.EXIT \n"<<endl;
		cin>>choice;
		if(choice==1) {
			int page_fault=0;
			queue<int> q;
			for(int j=0; j<framesize; j++)

			{
				frame[j]=-1;
			}
			for(int i=0; i<pagesize; i++) {
				int found=0;
				for(int j=0; j<framesize; j++) {
					if(page[i]==frame[j]) {
						found=1;
						break;
					}
				}
				if(found==0) {
					page_fault++;
					for(int j=0; j<framesize; j++) {
						if(frame[j]==-1) {
							q.push(page[i]);
							frame[j]=page[i];
							found=1;
							break;
						}
					}
					if(found==0) {
						int replacement=q.front();
						q.pop();
						for(int j=0; j<framesize; j++) {
							if(frame[j]==replacement) {
								q.push(page[i]);
								frame[j]=page[i];
								found=1;
								break;
							}
						}
					}
				}
				for(int j=0; j<framesize; j++) {
					cout<<frame[j]<<"	";

				}
				cout<<"\n"<<endl;
			}
			cout<<"No. of PAGE FAULTS :- "<<page_fault<<endl;
		} else if(choice==2) {
			int page_fault=0,used[framesize];
			for(int j=0; j<framesize; j++) {
				used[j]=0;
				frame[j]=-1;
			}
			for(int i=0; i<pagesize; i++) {
				int found=0;
				for(int j=0; j<framesize; j++) {
					if(frame[j]==page[i]) {
						used[j]=0;
						found=1;
						break;
					}
				}
				if(found==0) {
					page_fault++;
					for(int j=0; j<framesize; j++) {
						if(frame[j]==-1) {
							frame[j]=page[i];
							used[j]=0;
							found=1;
							break;
						}
					}
					if(found==0) {
						int maxtime=0;
						for(int j=0; j<framesize; j++) {
							if(used[j]>maxtime) {
								maxtime=used[j];

							}
						}
						for(int j=0; j<framesize; j++) {
							if(used[j]==maxtime) {
								frame[j]=page[i];
								used[j]=0;
								found=1;
								break;
							}
						}
					}
				}
				for(int j=0; j<framesize; j++) {
					used[j]++;
					cout<<frame[j]<<"	";
				}
				cout<<"\n"<<endl;
			}
			cout<<"No. of PAGE FAULTS :- "<<page_fault<<endl;
		} else if(choice==3) {
			cout<<"Thank you! "<<endl;
			return 0;
		} else {
			cout<<"INVALID INPUT! "<<endl;
		}

	}

	return 0;
}

