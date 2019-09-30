#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//input as given in assignment statement and type any letter in last
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
			for(int i=ino;i<gphsize;i++){	//
				vector<int> v1;
				gphone.push_back(v1);
			}
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

	for(int i=ino;i<gemsize;i++){	
		vector<int> v1;
		gmail.push_back(v1);
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
		gphoneadm.push_back(vi);
	}
	for(int i=0;i<gphone.size();i++){
		for(int j=0;j<gphone[i].size();j++){
			gphoneadm[i][gphone[i][j]]=1;
		}
	}

	for(int i=0;i<gemsize;i++){
		vector<int> vi(gemsize,0);
		gmailadm.push_back(vi);
	}
	for(int i=0;i<gmail.size();i++){
		for(int j=0;j<gmail[i].size();j++){
			gmailadm[i][gmail[i][j]]=1;
		}
	}

	//make a parents adjaceny list from adjmatrices
	vector<vector<int> > phonepar;
	vector<vector<int> > mailpar;

	for(int i=0;i<gphoneadm.size();i++){
		vector<int> vi;
		for(int j=0;j<gphoneadm.size();j++){
			if(gphoneadm[j][i]==1){
				vi.push_back(j);
			}
		}
		phonepar.push_back(vi);
	}

	for(int i=0;i<gmailadm.size();i++){
		vector<int> vi;
		for(int j=0;j<gmailadm.size();j++){
			if(gmailadm[j][i]==1){
				vi.push_back(j);
			}
		}
		mailpar.push_back(vi);
	}

	cout<<"Phpar "<<gphone.size()<<"\n";
	for(int i=0;i<phonepar.size();i++){
		for(int j=0;j<phonepar[i].size();j++){
			cout<<"("<<i+1<<","<<phonepar[i][j]+1<<") ";
		}
		cout<<phonepar[i].size()<<"\n";
	}

	cout<<"Gmpar "<<mailpar.size()<<"\n";
	for(int i=0;i<mailpar.size();i++){
		for(int j=0;j<mailpar[i].size();j++){
			cout<<"("<<i+1<<","<<mailpar[i][j]+1<<") ";
		}
		cout<<mailpar[i].size()<<"\n";
	}
	return 0;
}