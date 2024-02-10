///////////////////////////////////////////////
//         2024春晚魔术编程复现尝试             //
//              2024.2.10                   //
/////////////////////////////////////////////

#include<iostream>
#include<random>
#include<vector>
using namespace std;

int main() {
	//初始化随机数生成
	random_device ramdom;
	mt19937 gen(ramdom());
	uniform_int_distribution<> dis(1,3);
	int position_to_insert;

	//基本信息录入
	int gender; //1为男，2为女
	cout << "输入性别(1为男，2为女)：";
	cin >> gender;
	
	//步骤一：初始化扑克牌
	vector<int> card_init = { 1,2,3,4 };

	//步骤二：将扑克牌撕开，叠在一起，会保持ABCD-ABCD顺序
	vector<int> card_change = { 1,2,3,4,1,2,3,4 };

	//步骤三：名字排序（不管怎么操作，最后顺序仍会保持ABCD-ABCD形式）
	// card = { 1,2,3,4,1,2,3,4 };

	//步骤四：从牌堆最顶上拿3张牌，随意地插入中间
	int card_1st = card_change[0];
	int card_2st = card_change[1];
	int card_3st = card_change[2];
	vector<int> card_outside = { card_1st,card_2st,card_3st };
	card_change.erase(card_change.begin(), card_change.begin() + 3); 
	
	for (int times = 0; times < 3; times++) {  //循环三次插入拿出的三张牌，插入中间，即范围为第2-4张
		position_to_insert = dis(gen); //随机数赋值
		card_change.insert(card_change.begin() + position_to_insert, card_outside[times]); //插牌
	}
	cout << "扑克牌顺序_步骤四：";    //输出扑克牌顺序，会发现：头尾两张牌一定一样
	for (int num : card_change) {    
		cout << num << " ";
	}
	cout << endl;

	//步骤五：把最顶上的牌放在一边
	int card_aside = card_change[0];
	card_change.erase(card_change.begin()); 

	//步骤六：如果你是南方人，就从牌顶拿1张牌放到中间。如果你是北方人，放2张。如果你不知道是南方人还是北方人，就插3张
	//这一步最下面的底牌不动，不重要

	//步骤七：如果你是男生，从最上面拿1张洒到空中。如果你是女生，从最上面拿2张洒到空中
	if (gender == 1) { //男生删除一张
		card_change.erase(card_change.begin());
	}
	if (gender == 2) { //女生删除两张
		card_change.erase(card_change.begin(), card_change.begin() + 1);
	}
	cout << "扑克牌顺序_步骤七：";
	for (int num : card_change) {    //输出扑克牌顺序
		cout << num << " ";
	}
	cout << endl;

	//步骤八：口中念“见证奇迹的时刻”7个字，每念一次，把一张牌从上面拿到底层
	for (int times = 0; times < 7; times++) {
		int temp = card_change[0];
		card_change.erase(card_change.begin());
		card_change.push_back(temp);
	}
	cout << "扑克牌顺序_步骤八：";    //输出扑克牌顺序
	for (int num : card_change) {
		cout << num << " ";
	}
	cout << endl;

	//步骤九：口中喊“好运留下来”并把顶上的牌放到底层；再喊“烦恼丢出去”，把顶上的牌扔到空中。
	if (gender == 1) {                                   //男生
		for (int times = 0; times < 5; times++) {
			int temp = card_change[0];                     //好运留下来
			card_change.erase(card_change.begin());
			card_change.push_back(temp);

			card_change.erase(card_change.begin());        //烦恼丢出去
		}
	}
	if (gender == 2) {                                   //女生
		for (int times = 0; times < 5; times++) {
			int temp = card_change[0];                     //好运留下来
			card_change.erase(card_change.begin());
			card_change.push_back(temp);

			card_change.erase(card_change.begin());        //烦恼丢出去
		}
	}
	cout << "最终剩下的一张牌为：";    //输出最终剩下的一张牌
	for (int num : card_change) { 
		cout << num << " "; 
	}
	cout << endl; 

	//步骤十：比对在步骤五中放在一边的牌
	cout << "放在一边的牌为：" << card_aside;
}