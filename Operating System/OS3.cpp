#include <iostream>
#include <vector>
using namespace std;
void printer() {
int files;
cout &lt;&lt; &quot;Enter number of files to printed :- &quot;;
cin &gt;&gt; files;
cout &lt;&lt; &quot;Spooler state: &quot;;
string spool = &quot;&quot;;
for(int i = 1; i &lt;= files; i++) {
spool = spool + &quot; File &quot; + to_string(i);
cout &lt;&lt; spool &lt;&lt;endl ;
}
cout&lt;&lt;endl;
cout&lt;&lt;&quot;Printer state&quot;&lt;&lt;endl;
for(int i = 1; i &lt;= files; i++) {
spool = &quot; File &quot; + to_string(i);
cout &lt;&lt; spool &lt;&lt;endl;
}
}
void reader() {
vector&lt;string&gt; list;
while(true) {
cout &lt;&lt;&quot;\n Select user type :- \n&quot;&lt;&lt;endl;
cout&lt;&lt;&quot;0:Writer &quot;&lt;&lt;endl;
cout&lt;&lt;&quot;1:Reader &quot;&lt;&lt;endl;
cout&lt;&lt;&quot;2:END Program&quot;&lt;&lt;endl;
cout&lt;&lt;&quot;3:Exit Critical Section &quot;&lt;&lt;endl;
int input;
cin &gt;&gt; input;
string rc = &quot;&quot;;
if(input == 1) {
rc = &quot;Reader&quot;;
}
if(input == 0) {
rc = &quot;Writer&quot;;
}
if(list.size() == 0) {
list.push_back(rc);
cout &lt;&lt; &quot;[ &quot; &lt;&lt; rc &lt;&lt; &quot; ]&quot; &lt;&lt; endl;

continue;
}
if(input == 3) {
list.erase(list.begin());
for(int i = 0; i &lt; list.size(); i++) {
cout &lt;&lt; list[i] &lt;&lt; &quot; &quot;;
}
continue;
}
if(input == 2) {
break;
} else {
if(list[0] == &quot;Writer&quot;) {
cout &lt;&lt; &quot;No process can enter in Critical Section \n&quot;;
}
if(list[0] == &quot;Reader&quot;) {
if(input == 1)
{
list.push_back(&quot;Reader&quot;);
for(int i = 0; i &lt; list.size(); i++) {
cout &lt;&lt; list[i] &lt;&lt; &quot; &quot;;
}
} else {
cout &lt;&lt; &quot;Writer cannot enter\n&quot;;
}
continue;
}
}
}
}
void producer() {
int produce,consume;
cout &lt;&lt; &quot;Enter the No. of items to be Produced :-&quot;;
cin &gt;&gt; produce;
cout &lt;&lt; &quot;Enter the No. of items to be consumed :-&quot;;
cin &gt;&gt; consume;
vector&lt;int&gt; plist;
vector&lt;int&gt; clist;
cout &lt;&lt; &quot;Producer&#39;s list:\n&quot;;
for(int i = 0; i &lt; produce; i++) {
plist.push_back(i);
for(int j = 0; j &lt; plist.size(); j++) {
cout &lt;&lt; plist[j]+1 &lt;&lt; &quot; &quot;;
}
cout&lt;&lt;&quot;\n&quot;;
}
cout &lt;&lt; &quot;Consumer&#39;s list:\n&quot;;
for(int i = 0; i &lt; consume; i++) {

clist.push_back(plist[0]);
plist.erase(plist.begin());
for(int j = 0; j &lt; plist.size(); j++) {
cout &lt;&lt; plist[j] &lt;&lt; &quot; &quot;;
}
cout&lt;&lt;&quot;\n&quot;;
if(plist.size() == 0) {
cout &lt;&lt; &quot;NO further item can be consumed as NO more item Produced

!&quot;&lt;&lt;endl;;

break;
}
}
}
int main() {
while(1) {
int choice=1,process_size=0;
cout&lt;&lt;&quot; \n Which of the following program do you want to execute :-&quot;&lt;&lt;endl;
cout&lt;&lt;&quot;1.Readers Writers Problem.&quot;&lt;&lt;endl;
cout&lt;&lt;&quot;2.Producer Consumer Problem.&quot;&lt;&lt;endl;
cout&lt;&lt;&quot;3.Printer Spooler Problem.&quot;&lt;&lt;endl;
cout&lt;&lt;&quot;4.EXIT &quot;&lt;&lt;endl;
cin&gt;&gt;choice;
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
cout&lt;&lt;&quot;Thank you!&quot;&lt;&lt;endl;
return 0;
default:
cout&lt;&lt;&quot;INVALID INPUT!&quot;&lt;&lt;endl;

}
}
return 0;
}
