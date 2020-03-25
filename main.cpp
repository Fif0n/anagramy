#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

class anagram{
	bool isAnagram = true;
	ifstream plik1;
    ofstream plik2;
    
    public:
        anagram();
		~anagram();
       
		void check();    

};

	anagram::anagram(){
		plik1.open("c:\\od.txt");
	    plik2.open("c:\\do.txt");
	}
	
	int compare(const void *a, const void *b){
		return (*(int*)a - *(int*)b);
	}
	
	void anagram::check(){
		string s1, s2;
		plik2<<"[\n";
		while(!plik1.eof()){
			plik1>>s1>>s2;
			if(s1.length() != s2.length()){
				isAnagram = false;
			}
			int t1[s1.length()];
			int t2[s2.length()];
			
			for(int i = 0; i<=s1.length();i++){
				t1[i] = 0;
				t2[i] = 0;
			}
			
			for(int i = 0;i<=s1.length()-1; i++){
				t1[i] = int(s1[i]);
				t2[i] = int(s2[i]);
			}
			
			qsort(t1,s1.length(),sizeof(int),compare);
			qsort(t2,s2.length(),sizeof(int),compare);
			for(int i = 0; i<=s1.length();i++){
				if(t1[i] != t2[i]){
					isAnagram = false;
				}
			}
			string anagram;
			if(isAnagram){
				anagram = "TAK";
			} else {
				anagram = "NIE";
			}
			plik2<<"{\"slowo1\":\""<<s1<<"\", \"slowo2\":\""<<s2<<"\", \"anagram\":\""<<anagram<<"\"}\n";
			isAnagram = true;
			
		}
		plik2<<"]";
	}
	
	anagram::~anagram(){
		plik1.close();
    	plik2.close();
	}


int main(int argc, char** argv) {
	
	anagram a1;
	a1.check();
	return 0;
}
