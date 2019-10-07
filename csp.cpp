#include <bits/stdc++.h>
#include <iostream>

using namespace std;

bool checkForIncomingEdges(vector<int> mailParentNodes, vector<int> phoneParentNodes){
	return !(mailParentNodes.size() > phoneParentNodes.size());
}

bool checkForOutgoingEdges(vector<int> mailNodes, vector<int> phoneNodes){
	return !(mailNodes.size() > phoneNodes.size());
}

void generateConstranints(vector<vector<int> > gmail
	, vector<vector<int> > gphone
	, int gphsize, int gemsize
	, vector<vector<int> > phonepar
	, vector<vector<int> > mailpar){
	//cout << "phone size: " << gphone.size() << "\n";
	//cout << "mail size: " << gmail.size() << "\n";
	vector<vector<int>> verifiedPair;
	for(int i=0; i< gemsize; i++){
		vector<int> temp;
		verifiedPair.push_back(temp);
		for(int j=0; j< gphsize; j++){
			verifiedPair[i].push_back(0);
		}
	}
	//cout << "line 1: ";
	for(int i=0; i< gmail.size(); i++){
		for(int j=0; j< gphone.size(); j++){
			if((!checkForIncomingEdges(mailpar[i], phonepar[j]) || !checkForOutgoingEdges(gmail[i], gphone[j]))){
				cout<< (int)(-1*(i*(gphone.size())+j+1)) << " 0\n";
				verifiedPair[i][j] = -1;
			}
		}
	}
	//cout << "line 2: ";
	//optional.
	for(int i=0; i< gmail.size(); i++){
		//cout << "\nbijection check from mail side " << i << " mail-node: ";
		//cout << "!(" << i+1 << ", " << 1 << ") ";
		for(int j=0; j< gphone.size(); j++){
			for(int k=j+1;k<gphone.size();k++){
				cout<< (int)(-1*(i*(gphone.size())+j+1)) << " "<< (int)(-1*(i*(gphone.size())+k+1))<<" 0\n";
			}
		}
	}
	//cout << "\nline 3: ";
	//optional.
	for(int i=0; i< gphone.size(); i++){
		//cout << "\nbijection check from mail side " << i << " phone-node: ";
		//cout << "!(" << 1 << ", " << i+1 << ") ";
		for(int j=0; j< gmail.size(); j++){
			for(int k=j+1;k<gmail.size();k++){
				cout<< (int)(-1*(j*gphone.size()+i+1)) << " "<< (int)(-1*(k*gphone.size()+i+1))<<" 0\n";
			}
		}
	}
	//cout << "\nChildren:";
	// cout << "line 1: ";
	for(int i=0; i< gmail.size(); i++){
		if(gmail[i].size() != 0){
			for(int j=0; j< gphone.size(); j++){
				if(verifiedPair[i][j] ==0){
					//cout << "\nchildren constraint : ("<<i+1 << ", " <<j+1<< ") -> " ;
					for(int k =0; k< gmail[i].size(); k++){
						cout <<(int)(-1*(i*gphone.size()+j+1));
						for (int t=0; t< gphone[j].size(); t++){
							if(verifiedPair[gmail[i][k]][gphone[j][t]] == 0)
								cout << " " <<(int)(gmail[i][k]*gphone.size()+gphone[j][t]+1); 
						}
						cout<< " 0\n";
					}

					for(int k =0; k< gmail[i].size(); k++){
						for (int t=0; t< gphone[j].size(); t++){
							for (int t1=t+1; t1< gphone[j].size(); t1++){
								if(verifiedPair[gmail[i][k]][gphone[j][t]] == 0)
									cout <<(int)(-1*(i*gphone.size()+j+1))<<" "<<(int)(-1*(gmail[i][k]*gphone.size()+gphone[j][t]+1))<<" " <<(int)(-1*(gmail[i][k]*gphone.size()+gphone[j][t1]+1))<<" 0\n"; 
							}
						}
					}

					for(int k =0; k< gphone[j].size(); k++){
						for (int t=0; t< gmail[i].size(); t++){
							for (int t1=t+1; t1< gmail[i].size(); t1++){
								if(verifiedPair[gmail[i][k]][gphone[j][t]] == 0)
									cout <<(int)(-1*(i*gphone.size()+j+1))<<" "<<(int)(-1*(gmail[i][t]*gphone.size()+gphone[j][k])+1)<<" " <<(int)(-1*(gmail[i][t1]*gphone.size()+gphone[j][k]+1))<<" 0\n"; 
							}
						}
					}
				}
			}
		}
		// else{
		// 	cout << "\nsize zero " << i+1 << "\n";
		// }
	}

	//cout<<"Parents:";
	for(int i=0; i< mailpar.size(); i++){
		if(mailpar[i].size() != 0){
			for(int j=0; j< phonepar.size(); j++){
				if(verifiedPair[i][j] ==0){
					//cout << "\nchildren constraint : ("<<i+1 << ", " <<j+1<< ") -> " ;
					for(int k =0; k< mailpar[i].size(); k++){
						cout <<(int)(-1*(i*phonepar.size()+j+1));
						for (int t=0; t< phonepar[j].size(); t++){
							if(verifiedPair[mailpar[i][k]][phonepar[j][t]] == 0)
								cout << " " <<(int)(mailpar[i][k]*phonepar.size()+phonepar[j][t]+1); 
						}
						cout<< " 0\n";
					}

					for(int k =0; k< mailpar[i].size(); k++){
						for (int t=0; t< phonepar[j].size(); t++){
							for (int t1=t+1; t1< phonepar[j].size(); t1++){
								if(verifiedPair[mailpar[i][k]][phonepar[j][t]] == 0)
									cout <<(int)(-1*(i*phonepar.size()+j+1))<<" "<<(int)(-1*(mailpar[i][k]*gphone.size()+phonepar[j][t]+1))<<" " <<(int)(-1*(mailpar[i][k]*gphone.size()+phonepar[j][t1]+1))<<" 0\n"; 
							}
						}
					}

					for(int k =0; k< phonepar[j].size(); k++){
						for (int t=0; t< mailpar[i].size(); t++){
							for (int t1=t+1; t1< mailpar[i].size(); t1++){
								if(verifiedPair[mailpar[i][k]][phonepar[j][t]] == 0)
									cout <<(int)(-1*(i*gphone.size()+j+1))<<" "<<(int)(-1*(mailpar[i][t]*gphone.size()+phonepar[j][k]+1))<<" " <<(int)(-1*(mailpar[i][t1]*gphone.size()+phonepar[j][k]+1))<<" 0\n"; 
							}
						}
					}
				}
			}
		}
		// else{
		// 	cout << "\nparents zero"<<"\n";
		// }
	}

}

int main(int argc, const char * argv[]){
	ifstream f;
	f.open(argv[1]);


	//it has all the nodes with value subtracted by 1 i.e; 1 as 0 and 4 as 3 etc
	vector<vector<int> > gmail;
	vector<vector<int> > gphone;
	vector<vector<int> > phonepar;
	vector<vector<int> > mailpar;
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
			}
		}
	}

	if(gmail.size()<gemsize){
		for(int i=gmail.size();i<gemsize;i++){	
			vector<int> v1;
			gmail.push_back(v1);
		}
	}

	/*cout<<"Ph "<<gphone.size()<<"\n";
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

	cout<<"Phpar "<<phonepar.size()<<"\n";
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
	}*/
	generateConstranints(gmail, gphone, gphsize, gemsize, phonepar, mailpar);
	return 0;
}