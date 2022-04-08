#include <iostream>
#include <stdexcept>
#include <fstream>
#include <numeric>
#include <algorithm>
#include <vector>
using namespace std;

class Less_than {
	double v;
	public:
		Less_than(double vv) : v{vv}{}
		bool operator()(const double val) {return val < v;}
};


template<typename C>
void print(const C& c, char sep = '\n'){
	cout << "Container elements:\n";
	
	for(const auto elem : c){
		cout << elem << sep;
	} 
	cout << endl;
}

int main()
try{

	const string iname {"input_floats.txt"};
	ifstream ifs {iname};
	if(!ifs) throw runtime_error("Could not read file: "+iname);
	
	vector<double> vd;
	for(double d; ifs >> d;){
		vd.push_back(d);
	}
	
	print(vd);
	
	vector<int> vi(vd.size());
	/*for(auto& d : vd){
		vi.push_back(d);
	}*/
	copy(vd.begin(),vd.end(),vi.begin());
	print(vi);
	
	for(int i=0; i<vd.size(); i++){
		cout << vd[i] << '\t';
	}
	/*
	//difference between the sum of elements	//for-t megcsinalni
	int sum_i = 0;
	for(int i = 0; i < sizeof(vi);i++){
		sum_i += vi[i];
	}
	double sum_d = 0;
	for(int i = 0; i < sizeof(vd);i++){
		sum_d+=vd[i];
	}
	cout << endl;
	cout << "sum of ints: " << sum_i << '\n' << "sum of doubles: " << sum_d << endl;
	*/
	cout << endl;
	double d_sum = accumulate(vd.begin(),vd.end(),0.0);
	cout << "sum of doubles: " << d_sum << endl;
	int i_sum = accumulate(vi.begin(),vi.end(),0);
	cout << "sum of ints: " << i_sum << endl;
	//cout << precision(10);
	
	reverse(vd.begin(), vd.end());
	print(vd);
	
	double vd_mean = d_sum / vd.size();
	cout << "Mean value of vd: " << vd_mean << endl;
	
	
	//copy if
	vector<double> vd2(vd.size());
	auto it = copy_if(vd.begin(), vd.end(), vd2.begin(),
	Less_than(vd_mean));
		vd2.resize(distance(vd2.begin(), it));
	print(vd2);
	
	sort(vd.begin(), vd.end());
	print(vd);
	
	/*
	vector<double> vd2(vd.size());
	for(int i = 0; i <sizeof(vd); i++){
		if(vd_mean > vd[i]){
		vd2[i] = vd[i];
	}
		else{}
	}
	
	for(int i = 0; i <sizeof(vd2); i++){
		cout << vd2[i] << " ";
	}
	*/
	cout << endl;
} catch(exception & e) {
	cerr << e.what() << '\n';
	return 1;
}
	catch(...){
	cerr << "Unknown exception\n";
	return 2;

}









