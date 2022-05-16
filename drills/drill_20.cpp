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
void inc(C& c, int n){	//C-nek egy példánya, c egy konténert jelöl
	for(auto& i : c){
	i += n;
	}
}

template<typename Iter1, typename Iter2>
// requires Input_iterator<Iter1>() && Output_iterator<Iter2>()
Iter2 orai_copy(Iter1 f1, Iter1 e1, Iter2 f2){	//mit(mettől, meddig), hova másolunk
	for(Iter1 p = f1; p != e1; ++p){
		*f2++ = *p;		//először *f2 = *p, utána fogja *f2-t növelni, '*' kell mmivel értéket másolok át
	}
	return f2;

}

//vedes feladata
void print2(vector<int> const &vi2)
{
    for (auto vit3 = vi2.begin(); vit3 != vi2.end(); vit3++) {
        cout << *vit3 << ' ';
    }
}


int main()
try {

	constexpr int size = 10;
	
	int arr[size];			//ebből másoljuk ki az inteket 0-tól 10-ig
	for (int i = 0; i < size; i++) arr[i] = i;
	print(arr);
	
	//feltöltjük a tömböt, vectort, listát
	array<int, size> ai;
	copy(arr, arr + size, ai.begin());	//mettől, meddig, hova
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
		cout << "3 is found at " << distance(vi2.begin(), vit) << endl;
	}
	else {
		cout << "3 is not found" << endl;
	}
	//27-es értéket keressük
	vector<int>::iterator vit2;
	vit2 = std::find(vi2.begin(), vi2.end(), 27);	//iteratort ad a tartomány első elemére, ami megfelel a feltételnek
	if( vit2 != vi2.end()){
		cout << "27 is found at " << distance(vi2.begin(), vit2) << endl;	//távolság a tart. első elemétől a megadott elemig
	}
	else {
		cout << "27 is not found" << endl;
	}


	//bejaras iteratorral ami kiirja vi2 elemeit
	cout << "vi2 elemei: ";
	print2(vi2);
	cout << endl;



}
catch (exception& e) {
    cerr << "Exception: " << e.what() << '\n';
    return 1;
	}
	
catch(...) {
    cerr << "Unknown exception\n";
    return 2;
}


