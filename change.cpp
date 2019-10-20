#include <bits/stdc++.h>
#include <iostream>

using namespace std;

bool checkForIncomingEdges(vector<int> mailParentNodes, vector<int> phoneParentNodes){
	return !(mailParentNodes.size() > phoneParentNodes.size());
}

bool checkForOutgoingEdges(vector<int> mailNodes, vector<int> phoneNodes){
	return !(mailNodes.size() > phoneNodes.size());
}

pair< int,vector<string> > generateConstranints(vector<vector<int> > gmail
	, vector<vector<int> > gphone
	, int gphsize, int gemsize
	, vector<vector<int> > phonepar
	, vector<vector<int> > mailpar
	,vector< pair<int,int> > mailedg
	,vector< pair<int,int> > phoneedg){

	int count=0;
	vector<string> cons;

	vector<vector<int>> verifiedPair;
	for(int i=0; i< gmail.size(); i++){
		vector<int> temp;
		verifiedPair.push_back(temp);
		for(int j=0; j< gphone.size(); j++){
			verifiedPair[i].push_back(0);
		}
	}
	//cout << "line 1: ";
	for(int i=0; i< gmail.size(); i++){
		for(int j=0; j< gphone.size(); j++){
			if((!checkForIncomingEdges(mailpar[i], phonepar[j]) || !checkForOutgoingEdges(gmail[i], gphone[j]))){
				string s1 = to_string((int)(-1*(i*(gphone.size())+j+1))) + " 0\n";
				cons.push_back(s1);
				count++;
				verifiedPair[i][j] = -1;
			}
		}
	}
	
	vector<vector<int>> edgeMapMail;
	vector<vector<int>> edgeMapPhone;
	for(int i1=0; i1< gmail.size(); i1++){
		vector<int> temp;
		for(int i2=0; i2< gmail.size(); i2++){
			temp.push_back(0);
		}
		edgeMapMail.push_back(temp);
	}

	for(int i1=0; i1< gphone.size(); i1++){
		vector<int> temp;
		for(int i2=0; i2< gphone.size(); i2++){
			temp.push_back(0);
		}
		edgeMapPhone.push_back(temp);
	}

	//cout<<"Edg cons21\n";
	for(int i=0; i< mailedg.size(); i++){
		edgeMapMail[mailedg[i].first][mailedg[i].second] = 1;
	}
	for(int i=0; i< phoneedg.size(); i++){
		edgeMapPhone[phoneedg[i].first][phoneedg[i].second] = 1;
	}

	for(int edge=0; edge < phoneedg.size(); edge++){
		int j1 = phoneedg[edge].first;
		int j2 = phoneedg[edge].second;
		for(int i1=0; i1< gmail.size(); i1++){
			for(int i2=0; i2< gmail.size(); i2++){
				if(i2 != i1 && edgeMapMail[i1][i2]==0){
					string s1 = "";
					//s1 = s1+to_string((int)(gmail.size()*gphone.size()+i1*gmail.size()+i2+1)) + " ";
					s1 = s1 + to_string((int)(-1*(i1*(gphone.size())+j1+1))) + " " + to_string((int)(-1*(i2*(gphone.size())+j2+1))) + " ";
					s1 = s1 + "0\n";
					cons.push_back(s1);
					count++;
				}
			}
		}
	}

	for(int edge=0; edge < mailedg.size(); edge++){
		int i1 = mailedg[edge].first;
		int i2 = mailedg[edge].second;
		for(int j1=0; j1< gphone.size(); j1++){
			for(int j2=0; j2< gphone.size(); j2++){
				if(j2 != j1 && edgeMapPhone[j1][j2]==0){
					string s1 = "";
					//s1 = s1+to_string((int)(gmail.size()*gphone.size()+gmail.size()*gmail.size()+j1*gphone.size()+j2+1)) + " ";
					s1 = s1 + to_string((int)(-1*(i1*(gphone.size())+j1+1))) + " " + to_string((int)(-1*(i2*(gphone.size())+j2+1))) + " ";
					s1 = s1 + "0\n";
					cons.push_back(s1);
					count++;
				}
			}
		}
	}

	//atleast one soln
	for(int i=0;i<gmail.size();i++){
		string s1="";
		for(int j=0;j<gphone.size();j++){
			s1 = s1+to_string((int)((i*(gphone.size())+j+1))) + " ";
		}
		s1=s1+"0\n";
		cons.push_back(s1);
		count++;
	}

	//cout << "line 2: ";
	//optional.
	for(int i=0; i< gmail.size(); i++){
		for(int j=0; j< gphone.size(); j++){
			for(int k=j+1;k<gphone.size();k++){
				string s1 = to_string((int)(-1*(i*(gphone.size())+j+1)))+ " "+ to_string((int)(-1*(i*(gphone.size())+k+1)))+" 0\n";
				cons.push_back(s1);
				count++;
			}
		}
	}
	//cout << "\nline 3: "<<cons.size();
	//optional.
	for(int i=0; i< gphone.size(); i++){
		for(int j=0; j< gmail.size(); j++){
			for(int k=j+1;k<gmail.size();k++){
				string s1 = to_string((int)(-1*(j*gphone.size()+i+1))) + " " + to_string((int)(-1*(k*gphone.size()+i+1)))+" 0\n";
				cons.push_back(s1);
				count++;
			}
		}
	}

	return make_pair(count,cons);
}

int main(int argc, const char * argv[]){
	string filname = ".graphs";
	string inp(argv[1]);
    inp=inp+filname;
	char name[inp.size()+1];
	strcpy(name,inp.c_str());
	ifstream f;
	f.open(&name[0]);

	//it has all the nodes with value subtracted by 1 i.e; 1 as 0 and 4 as 3 etc
	vector<vector<int> > gmail;
	vector<vector<int> > gphone;
	vector<vector<int> > phonepar;
	vector<vector<int> > mailpar;

	vector< pair<int,int> > mailedg;
	vector< pair<int,int> > phoneedg;
	int gphsize=0;
	int gemsize=0;

	int n1,n2;
	int swit=0;

	while(f>>n1){
		f>>n2;
		if(n1==0){
			swit=1;
			if(gphone.size()<gphsize){
				for(int i=gphone.size();i<gphsize;i++){	//
					vector<int> v1;
					gphone.push_back(v1);
					phonepar.push_back(v1);
				}
			}
		}
		else{
			//for phone
			if(swit==0){
				gphsize=max(gphsize,n1);
				gphsize=max(gphsize,n2);
				if(gphone.size()<gphsize){
					for(int i=gphone.size();i<gphsize;i++){	//
						vector<int> v1;
						gphone.push_back(v1);
						phonepar.push_back(v1);
					}
				}
				gphone[n1-1].push_back(n2-1);
				phonepar[n2-1].push_back(n1-1);
				phoneedg.push_back(make_pair(n1-1,n2-1));
			}
			//for mail
			if(swit==1){
				gemsize=max(gemsize,n1);
				gemsize=max(gemsize,n2);
				if(gmail.size()<gemsize){
					for(int i=gmail.size();i<gemsize;i++){	
						vector<int> v1;
						gmail.push_back(v1);
						mailpar.push_back(v1);
					}
				}
				gmail[n1-1].push_back(n2-1);
				mailpar[n2-1].push_back(n1-1);
				mailedg.push_back(make_pair(n1-1,n2-1));
			}
		}
	}

	if(gmail.size()<gemsize){
		for(int i=gmail.size();i<gemsize;i++){	
			vector<int> v1;
			gmail.push_back(v1);
		}
	}

	pair< int,vector<string> > ans=generateConstranints(gmail, gphone, gphsize, gemsize, phonepar, mailpar, mailedg, phoneedg);
	fstream outfile;
	string filname1 = ".satinput";
	string inpo(argv[1]);
    inpo=inpo+filname1;
	char name1[inpo.size()+1];
	strcpy(name1,inpo.c_str());
    outfile.open(&name1[0],ios::out);
    outfile << "p cnf " << (gphsize*gemsize)/*+(gemsize*gemsize)*/ << " " << ans.first << "\n";
    for(int i=0;i<ans.second.size();i++){
    	outfile<<ans.second[i];
    }
	return 0;
}