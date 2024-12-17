#include <iostream>
#include <vector>

using namespace std;

int isempty(int arr[],int diff_resources) {
	for(int k=0; k<diff_resources; k++) {
		if(arr[k]!=0) {
			return 0;
		}
	}
	return 1;
}

int main() {
	int diff_resources,diff_process;
	cout<<"Enter the number of different resources available :-";
	cin>>diff_resources;
	int resources[diff_resources],empty[diff_resources];
	int curravailable[diff_resources];
	for(int i=0; i<diff_resources; i++) {
		cout<<"Enter the number of resources of type "<<i+1<<" :-";
		cin>>resources[i];
		curravailable[i]=resources[i];
	}

	cout<<"Enter the number of different processes to be executed :-";
	cin>>diff_process;

	int req_resources[diff_process][diff_resources],avail_resources[diff_process][diff_resources];

	int alloc_resources[diff_process][diff_resources];
	for(int i=0; i<diff_process; i++) {
		cout<<"Enter the number of different resources required by the process "<<i+1<<endl;
		for(int j=0; j<diff_resources; j++) {
			cout<<"Enter the number of resources of type "<<j+1<<" required:-";
			cin>>req_resources[i][j];
		}
		cout<<"Enter the number of different resources allocated the process "<<i+1<<endl;
		for(int j=0; j<diff_resources; j++) {
			cout<<"Enter the number of resources of type "<<j+1<<" :-";
			cin>>avail_resources[i][j];
			curravailable[j]-=avail_resources[i][j];
		}
		for(int j=0; j<diff_resources; j++) {
			alloc_resources[i][j]=req_resources[i][j]-avail_resources[i][j];
		}
	}

	vector<int> order;
	for(int a=0; a<diff_process; a++) {
		int safe=0;
		for(int i=0; i<diff_process; i++) {
			if(isempty(req_resources[i],diff_resources)) {
				continue;
			}
			int count=0;
			for(int j=0; j<diff_resources; j++) {
				if(alloc_resources[i][j]<=curravailable[j]) {
					count++;
				} else {
					break;
				}
			}
			if(count==diff_resources) {
				order.push_back(i+1);

				for(int j=0; j<diff_resources; j++) {
					curravailable[j]+=avail_resources[i][j];
					req_resources[i][j]=0;
					safe=1;
				}
			}

		}
		if(order.size()==diff_process) {
			safe=1;
			break;
		}
		if(safe==0) {
			cout<<"The Process system is not safe."<<endl;
			return 0;
		}
	}
	cout<<"Process execute in the order :-"<<endl;
	for(int i=0; i<order.size(); i++) {
		cout<<order[i]<<endl;
	}

	return 0;
}
