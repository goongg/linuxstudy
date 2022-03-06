#include <iostream>
#include <vector>
using namespace std;

/*
[1, 1, 0]
[1, 1, 0]
[0, 0, 1]
*/

vector<vector<int> > networks;
int serch_network(int com_idx);

int main()
{

	int n;
	vector<vector<int> > computers;

	/*copy here */
	vector<int> network0;
	int com_idx=0;

	//idx =0 과 연결된 그룹을 찾기
	for(com_idx=0; com_idx< n ;com_idx++ )
	{
		int net = serch_network(com_idx);
		if(net ==-1)	//내가 속한 네트워크가 없으면 새로 만들어
		{
			network0.clear();
			network0.push_back(com_idx);
			networks.push_back(network0);
			net = networks.size()-1;
			cout<<"make network "<<net<<" by:" <<com_idx<<endl; 
		}

		int search_idx=0;
		for( int i : computers[com_idx])
		{
			if(i==1 && search_idx != com_idx)
				networks[net].push_back(search_idx);
			search_idx++;
		}	
	}

	for(int i=0; i< networks.size(); i++)
	{
		cout<<"net" <<i<<": ";
		for(int j=0; j< networks[i].size(); j++)
			cout<<networks[i][j]<<" ";
		cout<<'\n';
	}
	return networks.size();

}

int serch_network(int com_idx)
{
	int network_idx=0;
	for(vector<int> n : networks)
	{
		for(int i : n)
		{
			if(i==com_idx)
				return network_idx;
		}
		network_idx++;
	}
return -1;
}

