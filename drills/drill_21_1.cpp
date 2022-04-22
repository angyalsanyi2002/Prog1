#include <iostream>
#include <map>
#include <string>
#include <stdexcept>
#include <numeric>
using namespace std;
template<typename K, typename V>
void print(const map<K, V>& m){
	for(pair <K, V> i : m){
	//for(auto& i : msi){
	cout << i.first << '\t' << i.second << endl;
	}
}

void read_map(map <string, int>& m){
	string s;
	int i =0;
	while (m.size()<10){
		cin >> s >> i;
		//m[s] = i;
		m.insert(make_pair(s, i));
	}
}

int main()
try{
	map<string, int> msi;
	msi["a"] = 1;
	msi["b"] = 3;
	msi["ab"] = 7;
	msi["efgh"] = 98;
	msi["xy"] = 76;
	msi["qw"] = 61;
	msi["efh"] = 60;
	msi["xc"] = 23;
	msi["qwertz"] = 11;
	msi["ax"] = 1;

	cout  << "MSI map: " << endl;
	print(msi);
	
	msi.erase("a");
	cout << endl << "Egy elem törlése után: " << endl;
	print(msi);
	
	msi.erase(msi.begin(), msi.end());
	cout << endl << "Teljes törlés után: " << endl;
	print(msi);
	
	cout << endl << "Adj meg 10 kulcs érték párt: " << endl;
	read_map(msi);
	cout << endl << "msi beolvasás után: " << endl;
	print(msi);
	
	int total = accumulate(msi.begin(), msi.end(), 0,
			[](int sum, const pair<string, int>& p)
			{return sum += p.second;}
			);
	int total2 = 0;
	for(pair<string, int> a : msi){
		total2 += a.second;
	}
	cout << endl <<"sum of the values in msi: "<< total << endl;
	
	/*
	int sum = 0;
	for (auto i:msi){
		//cout << i.second << " ";
		sum = sum + i.second;
	
	}
	cout << endl <<"sum of the values in msi: "<< sum << endl;
	*/	
	
	//megcserélük msi-nél a string-et és int-et
	map<int, string> mis;
	for(pair<string, int> i : msi){
		mis[i.second] = i.first;
	}
	cout << endl << "mis map: " << endl;
	print(mis);


} catch (exception& e){
	cerr<< "Exception: " <<e.what()<<'\n';
	return 1;
} catch (...){
	cerr<< "Unknown exception "<<"\n";
	return 2;
}

	









