#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//input as given in assignment statement and type any letter in last
int main(int argc, char* argv[]){
	
	string filname1 = ".satoutput";
	string inp1(argv[1]);
    inp1=inp1+filname1;
	char name1[inp1.size()+1];
	strcpy(name1,inp1.c_str());
	ifstream f1;
	f1.open(&name1[0]);

	fstream outfile;
	filname1 = ".mapping";
	string inpo(argv[1]);
    inpo=inpo+filname1;
	char name2[inpo.size()+1];
	strcpy(name2,inpo.c_str());
	outfile.open(&name2[0],ios::out);

	string sat;
	getline(f1, sat);
	int gphsize=0;
	if(sat.compare("SAT") == 0){
		int temp;
		vector<int> ans;
		while(f1>>temp){
			gphsize++;
			if(temp>0){
				ans.push_back(temp);
			}		
		}
		int gemsize = ans.size();
		gphsize = gphsize/gemsize;
		for(int i=1;i<=gemsize;i++){
			int k= ans[i-1]%gphsize;
			if(k==0){
				k=k+gphsize;
			}																																		
			outfile << i << " " << k << "\n";
		}
		return 0;
	}
	outfile << "0\n";
	return 0;
}