// 2022.05.16

#include <iostream>
using namespace std;

inline bool canwin(int n) {
	// 判断 (0,0,n) 状态下，先手是否有必胜策略
	if (n==0) return false; // (0,0,0) 状态下已无法操作
	if (n<0) n=-n;
	int prime2num=0; // 统计 n 中素因子 2 的个数
	while (n%2==0) n/=2, ++prime2num;
	return prime2num%2; 
} 

void sort3num(int &x, int &y, int &z) {
	// 对三个数进行排序 
	if (x>y) swap (x,y);
	if (x>z) swap (x,z);
	if (y>z) swap (y,z);
}

struct Node {
	int x, y, z;
	bool gameEnd () {
		// 判断游戏是否已经无法操作 
		int maxn = max (x, max (y, z));
		int minn = min (x, min (y, z));
		return maxn - minn <= 1;
	}
};

pair<bool,Node> worker(Node tmp){
	// 计算 
	sort3num (tmp.x, tmp.y, tmp.z);
	if (tmp.gameEnd()) return {false, {}}; // 无法操作 
	if (tmp.x<tmp.y && tmp.y<tmp.z) {
		// 三数不等必有必胜策略 
		Node changer = {tmp.x+(tmp.z-tmp.y), tmp.y, tmp.y};
			// 中间状态 
		if (canwin (changer.x-changer.y)) {
			// 中间状态为后手必败状态 
			int t = (tmp.x+tmp.z) / 2;
			return {true, {t, t, tmp.y}}; // 计算先手的必胜操作 
		}
		else return {true, changer}; // 中间状态为后手必胜状态  
	}
	if (tmp.y==tmp.z) swap (tmp.x, tmp.z); 
		// 后两数相等转换成前两数相等 
	if (canwin (tmp.z - tmp.x)) {
		// 与 (0,0,z-x) 状态等价 
		int t = (tmp.x+tmp.z) / 2;
		return {true, {tmp.y, t, t}}; 
	}
	else return {false, {}};
} 

int main() {
	Node nownode;
	cin >> nownode.x >> nownode.y >> nownode.z;
	sort3num (nownode.x, nownode.y, nownode.z);
	pair<bool,Node> tmp = worker(nownode);
	if (tmp.first) cout << 0 << endl; // 程序先 
	else cout << 1 << endl; // 交互库先 
	bool now = tmp.first;
	while (!nownode.gameEnd()){
		if(now){
			nownode = worker(nownode) .second;
			cout << nownode.x << ' ' << nownode.y << ' ' << nownode.z << endl;
		}
		else cin >> nownode.x >> nownode.y >> nownode.z;
		sort3num (nownode.x, nownode.y, nownode.z);
		now = !now;
	}
	return 0;
} 
