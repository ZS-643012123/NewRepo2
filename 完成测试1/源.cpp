#include<iostream>
using namespace std;
int main() {
	//��ɲ���1.1
	int n, k;
	cin >> n >> k;//n��Կ��k����ʦҪ��
	int m = n;
	int first = 0, exist = 0;//��Կ��ʱ����õ�ʱ�䣨�Ͽ�ʱ�䣩
	int num = 0;//Ҫȡ�ߵ�Կ��+  
	int stored[1002] = { 0 };//��1��ʼ��Ӧÿһ��Կ�׵Ĵ洢λ
	int used[1002] = { 0 };//��¼��ʦʹ��Կ�׵���Ϣ��ʼ��������Կ�׵�ʱ�䣬��Ȼûʹ�õ�Կ�׾���0��
	int pd = 0, min = 0;
	for (int i = 1; i <= n; i++) {
		stored[i] = i;//ȫ��һ�ΰ���ŴӴ�С����洢����
	}
	for (int i = 1; i <= k; i++) {//��ʼ�Ǽ���ʦʹ��Կ�׵���Ϣ
		cin >> num >> first >> exist;
		for (int j = 1; j <= n; j++) {//�ҵ����Ϊnum��Կ�׽����Ĵ洢λ���ÿ�Ȼ��ȡ��Կ��
			if (stored[j] == num) {//j��λ�ô���num��Կ��
				used[num] = first + exist;//����num��Կ�ױ������ã���¼�¹黹ʱ�� num�ŵĶ�Ӧ���±���num+1
				stored[j] = 0;//num��Կ�ױ����ߣ�λ���ǿյ�
			}
		}
	}
	//����Ҫ���ݹ黹ʱ������С����Կ�׼��ǽ��洢����Ϊ0����������
	for (int i = 1; i <= n; i++) {
		//��used��0������һ��Ȼ���ȡ�±꣬��Ӧ��storedΪ0��ǰ��λ����ȥ
		if (used[i] != 0) {//i��Կ���Ѿ�ʹ��
			min = i;
			for (int j = 1; j <= n; j++) {
				if (used[j] != 0) {
					if (used[i] > used[j]) {
						min = j;
					}
					for (int k = 1; k <= n; k++) {
						if (stored[k] == 0) {
							stored[k] = min;//�黹Կ��
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