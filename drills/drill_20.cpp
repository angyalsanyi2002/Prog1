#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <array>
#include <exception>
using namespace std;

template<typename C>
void print(const C& c){
	for(auto& i: c){
		cout << i << ' ';
	}
	cout << endl;
}

template<typename C>
void inc(C& c, int n){
	for(auto& i : c){
	i += n;
	}
}

template<typename Iter1, typename Iter2>
// requires Input_iterator<Iter1>() && Output_iterator<Iter2>()
Iter2 orai_copy(Iter1 f1, Iter1 e1, Iter2 f2){
	for(Iter1 p = f1; p != e1; ++p){
		*f2++ = *p;		//először *f2 = *p, utána fogja *f2-t növelni
	}
	return f2;

}



int main()
try {

	constexpr int size = 10;
	
	int arr[size];			//ebből másoljuk ki az inteket 0-tól 10-ig
	for (int i = 0; i < size; i++) arr[i] = i;
	print(arr);
	
	//feltöltjük a tömböt, vectort, listát
	array<int, size> ai;
	copy(arr, arr + size, ai.begin());
	cout << "array: "; print(ai);
	
	vector<int> vi(size);
	copy(arr, arr + size, vi.begin());
	cout << "vector: "; print(vi);
	
	list<int> li(size);
	copy(arr, arr + size, li.begin());
	cout << "list: "; print(li);
	cout << endl;
	array<int, size> ai2 = ai;
	vector<int> vi2 = vi;
	list<int> li2 = li;
	
	cout << "second array: "; print(ai2);
	cout << "second vector: "; print(vi2);
	cout << "second list: "; print(li2);
	cout << endl;
	
	//növeljük az elemek értékét
	inc(ai2, 2);
	inc (vi2, 3);
	inc (li2, 5);
	
	cout << "increased array: "; print(ai2);
	cout << "increased vector: "; print(vi2);
	cout << "increased list: "; print(li2);
	cout << endl;
	
	//tömb elemeit a vectorba, lista elemeit a tömbbe másoljuk
	orai_copy(ai2.begin(), ai2.end(), vi2.begin());
	orai_copy(li2.begin(), li2.end(), ai2.begin());
	
	cout << "array: "; print(ai2);
	cout << "vector: "; print(vi2);
	cout << "list: "; print(li2);
	cout << endl;
	
	//3-as értéket keressük a vi2 vectorban
	vector<int>::iterator vit;
	vit = std::find(vi2.begin(), vi2.end(), 3);
	if( vit != vi2.end()){
		cout << "Found at " << distance(vi2.begin(), vit) << endl;
	}
	else {
		cout << "Not found" << endl;
	}
	//27-es értéket keressük
	vector<int>::iterator vit2;
	vit2 = std::find(vi2.begin(), vi2.end(), 27);
	if( vit2 != vi2.end()){
		cout << "Found at " << distance(vi2.begin(), vit2) << endl;
	}
	else {
		cout << "Not found" << endl;
	}
		
}
catch (exception& e) {
    cerr << "Exception: " << e.what() << '\n';
    return 1;
	}
	
catch(...) {
    cerr << "Unknown exception\n";
    return 2;
}


