//2020-06-29 00:01:01
//Writer SakaTaku
#include<iostream>
using namespace std;
const long long MAX = 100, INF = 1e18, WHITE = 0, GRAY = 1, BLACK = 2;
long long n, M[MAX][MAX];
void init(){
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)M[i][j] = INF;
	for (int i = 0; i < n; i++)
		M[i][i] = 0;
}
int main(){
	int e;
	cin >> n >> e;
	init();
	for (int i = 0; i < e; i++){
		int s, t, u;
		cin >> s >> t >> u;
		M[s][t] = u;
	}
	for (int k = 0; k < n; k++){
		for (int i = 0; i < n; i++){
			if (M[i][k] == INF)continue;
			for (int j = 0; j < n; j++){
				if (M[k][j] == INF) continue;
				M[i][j] = min(M[i][j], M[i][k] + M[k][j]);
			}
		}
	}
	for (int i = 0; i < n; i++){
		if (M[i][i] < 0){
			cout << "NEGATIVE CYCLE" << endl;
			return 0;
		}
	}
	for (int i = 0; i < n; i++){
		if (M[i][0] == INF)
			cout << "INF";
		else
			cout << M[i][0];
		for (int j = 1; j < n; j++)
		{
			if (M[i][j] == INF)
				cout << " INF";
			else
				cout << " " << M[i][j];
		}
		cout << endl;
	}
}