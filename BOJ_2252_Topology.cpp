﻿#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>

using namespace std;

int n, m;
int* inDegree;
queue<int> q;
vector<int>* arr;
vector<int> result;

void topologySort() {
	for (int i = 1; i <= n; i++)
	{
		if (inDegree[i] == 0) {
			q.push(i);
		//	cout << "inDegree : " << i << endl;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (q.empty()) {
		//	cout << "사이클이 발생했습니다." << endl;
			return;
		}
		int x = q.front();
		q.pop();
		result.push_back(x);
	//	cout << "current x(q.front) : " << x << endl;
		for (int j = 0; j < arr[x].size(); j++) {
			int y = arr[x][j];
			//cout << "current y(q.front)." << y << endl;
			inDegree[y]--;
			if (inDegree[y] == 0){
			//	cout << "Lets push " << y << endl;
				q.push(y);
			}
		}
	}
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}
}

int main() {
	int a, b;
	cin >> n >> m;
	inDegree = new int[n+1];
	arr = new vector<int>[n+1];

	for (int i = 0; i <= n; ++i) {
		inDegree[i] = 0;
	}

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		arr[a].push_back(b);
		inDegree[b]++;
	}
	topologySort();
	return 0;
}