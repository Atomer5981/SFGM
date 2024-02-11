///////////////////////////////////////////////
//         2024����ħ����̸��ֳ���             //
//              2024.2.10                   //
/////////////////////////////////////////////

#include<iostream>
#include<random>
#include<vector>
#include<string>
using namespace std;

static void print_vector(string prefix_string, const vector<int>& vectors)
{
	cout << prefix_string;
	for (int i : vectors)
	{
		cout << i << " ";
	}
	cout << endl;
}

int main() {
	//��ʼ�����������
	random_device ramdom;
	mt19937 gen(ramdom());
	uniform_int_distribution<> dis(1,3);
	int position_to_insert;

	//������Ϣ¼��
	int gender;                      //1Ϊ�У�2ΪŮ
	cout << "�����Ա�(1Ϊ�У�2ΪŮ)��";
	cin >> gender;

	int name_length;                 //���ֳ���
	cout << "�����������ȣ�";
	cin >> name_length;

	int position;
	cout << "�����ϱ�����(1Ϊ������2Ϊ�Ϸ���3Ϊ��֪��)��";
	cin >> position;
	
	//����һ����ʼ���˿���
	vector<int> card_init = { 1,2,3,4 };

	//����������˿���˺��������һ�𣬻ᱣ��ABCD-ABCD˳��
	vector<int> card_change = { 1,2,3,4,1,2,3,4 };

	//���������������򣨲�����ô���������˳���Իᱣ��ABCD-ABCD��ʽ��
	for (int times = 0; times < name_length; times++) {
		int temp = card_change[0];
		card_change.erase(card_change.begin());
		card_change.push_back(temp);
	}

	//�����ģ����ƶ������3���ƣ�����ز����м�
	vector<int> card_outside = { card_change[0],card_change[1],card_change[2] };
	card_change.erase(card_change.begin(), card_change.begin() + 3); 
	
	for (int times = 0; times < 3; times++) {  //ѭ�����β����ó��������ƣ������м䣬����ΧΪ��2-4��
		position_to_insert = dis(gen); //�������ֵ
		card_change.insert(card_change.begin() + position_to_insert, card_outside[times]); //����
	}
	print_vector("�˿���˳��_�����ģ�", card_change);

	//�����壺����ϵ��Ʒ���һ��
	int card_aside = card_change[0];
	card_change.erase(card_change.begin()); 

	//����������������Ϸ��ˣ��ʹ��ƶ���1���Ʒŵ��м䡣������Ǳ����ˣ���2�š�����㲻֪�����Ϸ��˻��Ǳ����ˣ��Ͳ�3��
	if (position == 1) {    //����
		position_to_insert = dis(gen);
		card_change.insert(card_change.begin() + position_to_insert, card_outside[0]);
		card_change.erase(card_change.begin());
	}if (position == 2) {   //�Ϸ�
		for (int times = 0; times < 2; times++) {
			position_to_insert = dis(gen); 
			card_change.insert(card_change.begin() + position_to_insert, card_outside[times]);
		}
	}if (position == 3) {   //��֪��
		for (int times = 0; times < 3; times++) {
			position_to_insert = dis(gen);
			card_change.insert(card_change.begin() + position_to_insert, card_outside[times]);
		}
	}
	//�����ߣ������������������������1���������С��������Ů��������������2����������
	if (gender == 1) {  //����ɾ��һ��
		card_change.erase(card_change.begin());
	}if (gender == 2) { //Ů��ɾ������
		card_change.erase(card_change.begin(), card_change.begin() + 1);
	}
	print_vector("�˿���˳��_�����ߣ�", card_change);

	//����ˣ��������֤�漣��ʱ�̡�7���֣�ÿ��һ�Σ���һ���ƴ������õ��ײ�
	for (int times = 0; times < 7; times++) {
		int temp = card_change[0];
		card_change.erase(card_change.begin());
		card_change.push_back(temp);
	}
	print_vector("�˿���˳��_����ˣ�", card_change);

	//����ţ����к������������������Ѷ��ϵ��Ʒŵ��ײ㣻�ٺ������ն���ȥ�����Ѷ��ϵ����ӵ����С�
	while (card_change.size() > 1) {
		int temp = card_change[0];                     //����������
		card_change.erase(card_change.begin());
		card_change.push_back(temp);

		card_change.erase(card_change.begin());        //���ն���ȥ
	}
	print_vector("����ʣ�µ�һ����Ϊ��", card_change);

	//����ʮ���ȶ��ڲ������з���һ�ߵ���
	cout << "����һ�ߵ���Ϊ��" << card_aside;
}