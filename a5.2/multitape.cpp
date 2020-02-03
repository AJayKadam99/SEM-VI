#include<bits/stdc++.h>
using namespace std;



struct tape{
	int capacity;
	int available;
	vector<int> data;
};


int main(){
	int n, val_size, val, sum2=0;
	double sum=0;
	cout<<"enter number of tapes:\t";
	cin>>n;
	struct tape t[n];
	cout<<"enter tape capacities:\n";
	for(int i=0;i<n;i++){
		cout<<"tape "<<i+1<<":\t";
		cin>>t[i].capacity;
		t[i].available = t[i].capacity;
	}
	cout<<"enter number of programs:\t";
	cin>>val_size;
	int t_id = 0;
	for(int i=0;i<val_size;i++)
	{
		cout<<"size of program "<<i+1<<":\t";
		cin>>val;
		t_id = 0;
		while(t_id<n)
			if(val<=t[t_id].available){
				t[t_id].data.push_back(val);
				t[t_id].available -= val;
				break;
			}
			else{
				t_id++;
				if(t_id == n)
					cout<<"current program cannot fit in any of the available tapes\n";
			}	
	}
	for(int i=0;i<n;i++)
		sort(t[i].data.begin(), t[i].data.end());
		
	
	for(int i=0;i<n;i++){
		cout<<"tape "<<i+1<<":\t";
		int k = t[i].data.size();
		for(int j=0;j<k;j++){
			cout<<t[i].data[j]<<" ";
			sum = sum + t[i].data[j] * (k - j);
		}
		sum2 += k;
		cout<<"\n";
	}
	sum = sum/sum2; 
	isnan(sum) == false ? cout<<sum : cout<<"no program on disk";
	cout<<"\n";

	return 0;
}
