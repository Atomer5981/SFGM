///////////////////////////////////////////////
//         2024春晚魔术编程复现尝试             //
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
	//初始化随机数生成
	random_device ramdom;
	mt19937 gen(ramdom());
	uniform_int_distribution<> dis(1,3);
	int position_to_insert;

	//基本信息录入
	int gender;                      //1为男，2为女
	cout << "输入性别(1为男，2为女)：";
	cin >> gender;

	int name_length;                 //名字长度
	cout << "输入姓名长度：";
	cin >> name_length;

	int position;
	cout << "输入南北方人(1为北方，2为南方，3为不知道)：";
	cin >> position;
	
	//步骤一：初始化扑克牌
	vector<int> card_init = { 1,2,3,4 };

	//步骤二：将扑克牌撕开，叠在一起，会保持ABCD-ABCD顺序
	vector<int> card_change = { 1,2,3,4,1,2,3,4 };

	//步骤三：名字排序（不管怎么操作，最后顺序仍会保持ABCD-ABCD形式）
	for (int times = 0; times < name_length; times++) {
		int temp = card_change[0];
		card_change.erase(card_change.begin());
		card_change.push_back(temp);
	}

	//步骤四：从牌堆最顶上拿3张牌，随意地插入中间
	vector<int> card_outside = { card_change[0],card_change[1],card_change[2] };
	card_change.erase(card_change.begin(), card_change.begin() + 3); 
	
	for (int times = 0; times < 3; times++) {  //循环三次插入拿出的三张牌，插入中间，即范围为第2-4张
		position_to_insert = dis(gen); //随机数赋值
		card_change.insert(card_change.begin() + position_to_insert, card_outside[times]); //插牌
	}
	print_vector("扑克牌顺序_步骤四：", card_change);

	//步骤五：把最顶上的牌放在一边
	int card_aside = card_change[0];
	card_change.erase(card_change.begin()); 

	//步骤六：如果你是南方人，就从牌顶拿1张牌放到中间。如果你是北方人，放2张。如果你不知道是南方人还是北方人，就插3张
	if (position == 1) {    //北方
		position_to_insert = dis(gen);
		card_change.insert(card_change.begin() + position_to_insert, card_outside[0]);
		card_change.erase(card_change.begin());
	}if (position == 2) {   //南方
		for (int times = 0; times < 2; times++) {
			position_to_insert = dis(gen); 
			card_change.insert(card_change.begin() + position_to_insert, card_outside[times]);
		}
	}if (position == 3) {   //不知道
		for (int times = 0; times < 3; times++) {
			position_to_insert = dis(gen);
			card_change.insert(card_change.begin() + position_to_insert, card_outside[times]);
		}
	}
	//步骤七：如果你是男生，从最上面拿1张洒到空中。如果你是女生，从最上面拿2张洒到空中
	if (gender == 1) {  //男生删除一张
		card_change.erase(card_change.begin());
	}if (gender == 2) { //女生删除两张
		card_change.erase(card_change.begin(), card_change.begin() + 1);
	}
	print_vector("扑克牌顺序_步骤七：", card_change);

	//步骤八：口中念“见证奇迹的时刻”7个字，每念一次，把一张牌从上面拿到底层
	for (int times = 0; times < 7; times++) {
		int temp = card_change[0];
		card_change.erase(card_change.begin());
		card_change.push_back(temp);
	}
	print_vector("扑克牌顺序_步骤八：", card_change);

	//步骤九：口中喊“好运留下来”并把顶上的牌放到底层；再喊“烦恼丢出去”，把顶上的牌扔到空中。
	while (card_change.size() > 1) {
		int temp = card_change[0];                     //好运留下来
		card_change.erase(card_change.begin());
		card_change.push_back(temp);

		card_change.erase(card_change.begin());        //烦恼丢出去
	}
	print_vector("最终剩下的一张牌为：", card_change);

	//步骤十：比对在步骤五中放在一边的牌
	cout << "放在一边的牌为：" << card_aside;
}