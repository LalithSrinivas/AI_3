#include <bits/stdc++.h>
#include <iostream>

using namespace std;


int main(){
	//it has all the nodes with value subtracted by 1 i.e; 1 as 0 and 4 as 3 etc
	vector<vector<int> > gmail;
	vector<vector<int> > gphone;
	int gphsize=0;
	int gemsize=0;

	int n1,n2;
	int swit=0;

	int ino=0;
	while(cin>>n1){
		cin>>n2;
		if(n1==0){
			swit=1;
			ino=0;
		}
		else{
			//for phone
			if(swit==0){
				gphsize=max(gphsize,n1);
				gphsize=max(gphsize,n2);
				for(int i=ino;i<n1;i++){	//
					vector<int> v1;
					gphone.push_back(v1);
				}
				ino=n1;
				gphone[n1-1].push_back(n2-1);
			}
			//for mail
			if(swit==1){
				gemsize=max(gemsize,n1);
				gemsize=max(gemsize,n2);
				for(int i=ino;i<n1;i++){	//
					vector<int> v1;
					gmail.push_back(v1);
				}
				ino=n1;
				gmail[n1-1].push_back(n2-1);
			}
		}
	}

	cout<<"Ph "<<gphone.size()<<"\n";
	for(int i=0;i<gphone.size();i++){
		for(int j=0;j<gphone[i].size();j++){
			cout<<"("<<i+1<<","<<gphone[i][j]+1<<") ";
		}
		cout<<gphone[i].size()<<"\n";
	}

	cout<<"Gm "<<gmail.size()<<"\n";
	for(int i=0;i<gmail.size();i++){
		for(int j=0;j<gmail[i].size();j++){
			cout<<"("<<i+1<<","<<gmail[i][j]+1<<") ";
		}
		cout<<gmail[i].size()<<"\n";
	}

	//adjacency matrices help us to find parents adjacency list
	vector<vector<int> > gphoneadm;
	vector<vector<int> > gmailadm;;

	for(int i=0;i<gphsize;i++){
		vector<int> vi(gphsize,0);
	}
	//for(int i=0;i<gphoneadm;)

	return 0;
}