#include<iostream>
#include<string>
#include<cstdlib>
#include<fstream>
using namespace std;

void sort(float x[], int N){
	for(int i = 1; i < N; i++){
		for(int j = i; j > 0; j--){
			if(x[j] > x[j-1]){
				float temp = x[j];
				x[j] = x[j-1];
				x[j-1] = temp;
			}else{
				break;
			} 
		}
	}
}

int main(){

	//Write your code here
	ifstream source("score3.txt");
	string line;
	float x[20];
	int j=0;
	while(getline(source,line)){
		x[j] = atof(line.c_str());
		j++;
	}
	sort(x,20);

	ofstream dest("result.txt");
	int b=1; int c=0;
	for(int i=0; i<20; i++){
		if(x[i] == x[i-1]){
			dest << b << ":" << x[i] << "\n";
			c++;
		}else if(x[i] != x[i-1] && x[i] == x[i+1]){
			b=b+c;
			dest << b << ":" << x[i] << "\n";
			c=1;
		}
		else{
			b=b+c;
			dest << b << ":" << x[i] << "\n";
			c=1;
		}
	}
	dest.close();
	return 0;
}


