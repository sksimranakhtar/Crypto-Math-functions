#include<bits/stdc++.h>
using namespace std;

int main(){
	vector<int>factor; 			 //for storing the prime factors of 'm'
	int n,a,m;
	cout << "Enter the value of a and m" << endl;
	float totient;
	cin>>a>>m;
	

	//finding the prime factors of 'm'
	n=m;
	if(n%2==0){  				//if 2 is a prime factor of n
		factor.push_back(2);  

		while (n%2 == 0){
			n = n/2;
		}
	}
	int div=0; 				//flag to check if current i is a prime factor of n
	for (int i = 3; i <= sqrt(n); i = i+2){
        	while (n%i == 0)      
        	{
			div=1;        		//set flag to 1 if i is prime factor of n            
            		n = n/i;
        	}
		if(div==1){
			factor.push_back(i);    //store the factor
			div=0;
		}
	}
	if(n>2){
		factor.push_back(n);          
	}
	
	

	//for finding the totient using eular's formula
	totient=m;
	for(int i=0;i<factor.size();i++){
		float p=factor[i];
		float x=(p-1)/p;
		totient*=x;
	}

	int y=(long long int)(pow(a,(int)(totient-1)))%m;  //calculating the multiplicative inverse

	cout << "Multiplicative Inverse of " << a << " : " << y << endl;
	
	return 0;
			
}

