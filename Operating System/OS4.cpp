#include <iostream>
#include <vector>
using namespace std;
int isempty(int arr[],int diff_resources) {
for(int k=0; k&lt;diff_resources; k++) {
if(arr[k]!=0) {
return 0;
}
}
return 1;
}
int main() {
int diff_resources,diff_process;
cout&lt;&lt;&quot;Enter the number of different resources available :-&quot;;
cin&gt;&gt;diff_resources;
int resources[diff_resources],empty[diff_resources];
int curravailable[diff_resources];
for(int i=0; i&lt;diff_resources; i++) {
cout&lt;&lt;&quot;Enter the number of resources of type &quot;&lt;&lt;i+1&lt;&lt;&quot; :-&quot;;
cin&gt;&gt;resources[i];
curravailable[i]=resources[i];
}
cout&lt;&lt;&quot;Enter the number of different processes to be executed :-&quot;;
cin&gt;&gt;diff_process;
int req_resources[diff_process][diff_resources],avail_resources[diff_process][diff_resources];
int alloc_resources[diff_process][diff_resources];
for(int i=0; i&lt;diff_process; i++) {
cout&lt;&lt;&quot;Enter the number of different resources required by the process &quot;&lt;&lt;i+1&lt;&lt;endl;
for(int j=0; j&lt;diff_resources; j++) {
cout&lt;&lt;&quot;Enter the number of resources of type &quot;&lt;&lt;j+1&lt;&lt;&quot; required:-&quot;;
cin&gt;&gt;req_resources[i][j];
}
cout&lt;&lt;&quot;Enter the number of different resources allocated the process &quot;&lt;&lt;i+1&lt;&lt;endl;

for(int j=0; j&lt;diff_resources; j++) {
cout&lt;&lt;&quot;Enter the number of resources of type &quot;&lt;&lt;j+1&lt;&lt;&quot; :-&quot;;
cin&gt;&gt;avail_resources[i][j];
curravailable[j]-=avail_resources[i][j];
}
for(int j=0; j&lt;diff_resources; j++) {
alloc_resources[i][j]=req_resources[i][j]-avail_resources[i][j];
}
}
vector&lt;int&gt; order;
for(int a=0; a&lt;diff_process; a++) {
int safe=0;
for(int i=0; i&lt;diff_process; i++) {
if(isempty(req_resources[i],diff_resources)) {
continue;
}
int count=0;
for(int j=0; j&lt;diff_resources; j++) {
if(alloc_resources[i][j]&lt;=curravailable[j]) {
count++;
} else {
break;
}
}
if(count==diff_resources) {
order.push_back(i+1);
for(int j=0; j&lt;diff_resources; j++) {
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
cout&lt;&lt;&quot;The Process system is not safe.&quot;&lt;&lt;endl;
return 0;
}
}
cout&lt;&lt;&quot;Process execute in the order :-&quot;&lt;&lt;endl;
for(int i=0; i&lt;order.size(); i++) {
cout&lt;&lt;order[i]&lt;&lt;endl;
}
return 0;

}
