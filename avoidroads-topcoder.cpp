#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <iomanip>
#include <set>
#include <cstdio>
#define inf 1000000009
#define ll long long
using namespace std;
bool bol[101][101] = {0};
int main() {
	int x,y,n;
	int x_crdnt,y_crdnt;
	int num;
	ll int mat[101][101] = {0};
	cin>>x>>y;
	string s,tmp;
	getline(cin,s,'|');
	int ct = 0;
	for(int i=0;i<s.size();){
		if((int)s[i] > 47&&(int)s[i] < 58){
			num = 0;
			while((int)s[i] > 47 && (int)s[i] < 58){
				num *= 10;
				num += (int)s[i]-48;
				i++;
			}
			ct++;
			if(ct == 1){
				x_crdnt = num;
			}
			else{
				y_crdnt = num;
				ct = 0;
				bol[x_crdnt][y_crdnt] = 1;
			}
		}
		else i++;
	}
	mat[0][0] = 1;
	for(int i=0;i<=x;i++){
		for(int j=0;j<=y;j++){
			if(bol[i][j]){
				if(!bol[i+1][j]){
					mat[i+1][j] += mat[i][j];
				}
				if(!bol[i][j+1]){
					mat[i][j+1] += mat[i][j];
				}
			}
			else{
				mat[i+1][j] += mat[i][j];
				mat[i][j+1] += mat[i][j];
			}
		}
	}	cout << mat[x][y] << endl;
	return 0;
}
