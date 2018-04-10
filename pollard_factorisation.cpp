//Factorize a number using Pollard p-1 factorization method. Compare the time with the "Trial Division" method.

#include<bits/stdc++.h>
#include <sys/time.h>

using namespace std;

int gcd(long int a,long int b){
	
	if(a==0 || b==0) return 0;
	
	if(a==b) return a;
	
	if(a>b) return gcd(a-b,b);
	
	return gcd(a,b-a);
	
}

long long int func(long long int a,long long int b,long long int n){
	long long int x=1,y=a;
	while(b>0){
		if(b%2==1){x=(x*y)%n;}
		y=(y*y)%n;
		b/=2;
	}
	return x%n;
}
		

void pollardfactorize(long long int n,long long int B){
	long int p;
	long int a=2;
	long int e=2;
	while(e<=B){
		//a=(long int)pow(a,e)%n;
		a=func(a,e,n);
		e=e+1;
	}
	//cout << a-1 << " " << n << endl;
	p=gcd(a-1,n);
	//cout << p;
	if(p>1 && p<n);// cout << p << endl;
	else cout << "No number exists\n" << endl;

}

void trialfactorize(long long int n){
	long int a=2;
	while(a<=sqrt(n)){
		while(n%a==0){
			//cout << a << endl;
			n=n/a;
		}
		a=a+1;
	}
	if(n>1);// cout << n << endl;
	else cout << "No more factor" << endl;
}

int main(){
	cout << "Enter the Number:";
	long long int n,B;
	cin >> n;
	cout << "Enter the Bound for Pollard Factorization:";
	cin >> B;
	struct timeval stoptp, starttp;
	gettimeofday(&starttp, NULL);

	pollardfactorize(n,B);
	
	gettimeofday(&stoptp, NULL);

	
	cout << "Time taken by Pollard Factorization : " << (stoptp.tv_sec - starttp.tv_sec) * 1000000 + (stoptp.tv_usec - starttp.tv_usec)  << " microseconds" << endl;

	struct timeval stoptt, starttt;
        gettimeofday(&starttt, NULL);
        
        trialfactorize(n);
        
        gettimeofday(&stoptt, NULL);


        cout << "Time taken by Trial-Division Factorization : " << (stoptt.tv_sec - starttt.tv_sec) * 1000000 + (stoptt.tv_usec - starttt.tv_usec)  << " microseconds" << endl;
	
	return 0;
}
