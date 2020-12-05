#include<iostream>
using namespace std;
int main() {
	//完成测试1.1
	int n, k;
	cin >> n >> k;//n把钥匙k个老师要用
	int m = n;
	int first = 0, exist = 0;//拿钥匙时间和用的时间（上课时间）
	int num = 0;//要取走的钥匙+  
	int stored[1002] = { 0 };//从1开始对应每一个钥匙的存储位
	int used[1002] = { 0 };//记录老师使用钥匙的信息初始化就是拿钥匙的时间，当然没使用的钥匙就是0啦
	int pd = 0, min = 0;
	for (int i = 1; i <= n; i++) {
		stored[i] = i;//全部一次按编号从大小到达存储起来
	}
	for (int i = 1; i <= k; i++) {//开始登记老师使用钥匙的信息
		cin >> num >> first >> exist;
		for (int j = 1; j <= n; j++) {//找到编号为num的钥匙将它的存储位置置空然后取走钥匙
			if (stored[j] == num) {//j号位置存了num号钥匙
				used[num] = first + exist;//现在num号钥匙被拿走用，记录下归还时间 num号的对应的下标是num+1
				stored[j] = 0;//num号钥匙被拿走，位置是空的
			}
		}
	}
	//现在要根据归还时间来从小还回钥匙即是将存储数组为0的填上序列
	for (int i = 1; i <= n; i++) {
		//将used非0的排序一遍然后读取下标，对应到stored为0靠前的位置中去
		if (used[i] != 0) {//i号钥匙已经使用
			min = i;
			for (int j = 1; j <= n; j++) {
				if (used[j] != 0) {
					if (used[i] > used[j]) {
						min = j;
					}
					for (int k = 1; k <= n; k++) {
						if (stored[k] == 0) {
							stored[k] = min;//归还钥匙
							used[min] = 0;
							break;
							break;
						}

					}
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << stored[i];
		if (i != n)
			cout << " ";
	}
	return 0;
}