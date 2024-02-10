///////////////////////////////////////////////
//         2024����ħ����̸��ֳ���             //
//              2024.2.10                   //
/////////////////////////////////////////////

#include<iostream>
#include<random>
#include<vector>
using namespace std;

int main() {
	//��ʼ�����������
	random_device ramdom;
	mt19937 gen(ramdom());
	uniform_int_distribution<> dis(1,3);
	int position_to_insert;

	//������Ϣ¼��
	int gender; //1Ϊ�У�2ΪŮ
	cout << "�����Ա�(1Ϊ�У�2ΪŮ)��";
	cin >> gender;
	
	//����һ����ʼ���˿���
	vector<int> card_init = { 1,2,3,4 };

	//����������˿���˺��������һ�𣬻ᱣ��ABCD-ABCD˳��
	vector<int> card_change = { 1,2,3,4,1,2,3,4 };

	//���������������򣨲�����ô���������˳���Իᱣ��ABCD-ABCD��ʽ��
	// card = { 1,2,3,4,1,2,3,4 };

	//�����ģ����ƶ������3���ƣ�����ز����м�
	int card_1st = card_change[0];
	int card_2st = card_change[1];
	int card_3st = card_change[2];
	vector<int> card_outside = { card_1st,card_2st,card_3st };
	card_change.erase(card_change.begin(), card_change.begin() + 3); 
	
	for (int times = 0; times < 3; times++) {  //ѭ�����β����ó��������ƣ������м䣬����ΧΪ��2-4��
		position_to_insert = dis(gen); //�������ֵ
		card_change.insert(card_change.begin() + position_to_insert, card_outside[times]); //����
	}
	cout << "�˿���˳��_�����ģ�";    //����˿���˳�򣬻ᷢ�֣�ͷβ������һ��һ��
	for (int num : card_change) {    
		cout << num << " ";
	}
	cout << endl;

	//�����壺����ϵ��Ʒ���һ��
	int card_aside = card_change[0];
	card_change.erase(card_change.begin()); 

	//����������������Ϸ��ˣ��ʹ��ƶ���1���Ʒŵ��м䡣������Ǳ����ˣ���2�š�����㲻֪�����Ϸ��˻��Ǳ����ˣ��Ͳ�3��
	//��һ��������ĵ��Ʋ���������Ҫ

	//�����ߣ������������������������1���������С��������Ů��������������2����������
	if (gender == 1) { //����ɾ��һ��
		card_change.erase(card_change.begin());
	}
	if (gender == 2) { //Ů��ɾ������
		card_change.erase(card_change.begin(), card_change.begin() + 1);
	}
	cout << "�˿���˳��_�����ߣ�";
	for (int num : card_change) {    //����˿���˳��
		cout << num << " ";
	}
	cout << endl;

	//����ˣ��������֤�漣��ʱ�̡�7���֣�ÿ��һ�Σ���һ���ƴ������õ��ײ�
	for (int times = 0; times < 7; times++) {
		int temp = card_change[0];
		card_change.erase(card_change.begin());
		card_change.push_back(temp);
	}
	cout << "�˿���˳��_����ˣ�";    //����˿���˳��
	for (int num : card_change) {
		cout << num << " ";
	}
	cout << endl;

	//����ţ����к������������������Ѷ��ϵ��Ʒŵ��ײ㣻�ٺ������ն���ȥ�����Ѷ��ϵ����ӵ����С�
	if (gender == 1) {                                   //����
		for (int times = 0; times < 5; times++) {
			int temp = card_change[0];                     //����������
			card_change.erase(card_change.begin());
			card_change.push_back(temp);

			card_change.erase(card_change.begin());        //���ն���ȥ
		}
	}
	if (gender == 2) {                                   //Ů��
		for (int times = 0; times < 5; times++) {
			int temp = card_change[0];                     //����������
			card_change.erase(card_change.begin());
			card_change.push_back(temp);

			card_change.erase(card_change.begin());        //���ն���ȥ
		}
	}
	cout << "����ʣ�µ�һ����Ϊ��";    //�������ʣ�µ�һ����
	for (int num : card_change) { 
		cout << num << " "; 
	}
	cout << endl; 

	//����ʮ���ȶ��ڲ������з���һ�ߵ���
	cout << "����һ�ߵ���Ϊ��" << card_aside;
}