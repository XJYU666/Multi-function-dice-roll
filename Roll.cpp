#include"bits/XJYU's Cpp_head.h"
using namespace std;

class Roll {
public:
	int Roll_Answer[100] = { 0 };		//定义并初始化结果数组
	string ErrorInfo;
	bool RollCheck(int faceNumber_Int, int times_Int, bool flagRecur_Bool) {
		if (flagRecur_Bool) {
			if (faceNumber_Int > 0 || faceNumber_Int >= times_Int) {
				return true;
			}
			else {
				ErrorInfo = "Faces<Times";
				return false;
			}
		}
		else {
			return true;
		}
	}
	bool RollMain(int faceNumber_Int, int times_Int, bool flagRecur_Bool) {
		srand((int)time(0));
		if (flagRecur_Bool) {
			if (RollCheck(faceNumber_Int, times_Int, flagRecur_Bool)) {
				RollRecur(faceNumber_Int, times_Int, faceNumber_Int - 1);
				return true;
			}
			else {
				return false;
			}
		}
		else {
			Rollcommon(faceNumber_Int, times_Int);
			return true;
		}
	}
protected:
	void Rollcommon(int faceNumber_Int, int times_Int) {				//不查重掷骰子
		int rollTemp = 0;
		for (int i = 0; i < times_Int; i++) {
			rollTemp = random(faceNumber_Int);
			if (rollTemp == 0) {
				rollTemp = faceNumber_Int;
			}
			Roll_Answer[i] = rollTemp;
		}
	}
	void RollRecur(int faceNumber_Int, int times_Int, int step) {		//用递归做骰子查重,此函数无法拒绝异常数据
		if (step <= -1) {
			return;
		}
		int rollTemp = 0;
		bool flagtemp_Bool = true;
		while (1) {
			rollTemp = random(faceNumber_Int);							//生成0~(X-1)的随机数
			if (rollTemp == 0) {
				rollTemp = faceNumber_Int;
			}															//把0~(X-1)的随机数变成1~X
			//cout << rollTemp << endl;									//运算时数组内容显示
			flagtemp_Bool = true;										//重新赋值
			for (int i = 0; i < times_Int; i++) {						//遍历数组查重
				if (Roll_Answer[i] == rollTemp) {
					flagtemp_Bool = false;
					break;
				}
			}
			if (flagtemp_Bool) {
				Roll_Answer[faceNumber_Int - (faceNumber_Int - step)] = rollTemp;
				RollRecur(faceNumber_Int, times_Int, step - 1);
				return;
			}
		}
	}

	int RollOld(int faceNumber_Int, int times_Int, bool flagRecur_Bool) {
		int turnPlace_Int = 0, rollTemp = 0;
		bool flagtemp_Bool = true;
		srand((int)time(0));
		if (faceNumber_Int > 0) {
			if (flagRecur_Bool) {
				if (faceNumber_Int >= times_Int) {
					while (turnPlace_Int < times_Int) {
						rollTemp = random(faceNumber_Int);
						if (rollTemp == 0) {
							rollTemp = faceNumber_Int;
						}
						//	cout << rollTemp << endl;
						flagtemp_Bool = true;
						for (int i = 0; i < times_Int; i++) {
							if (Roll_Answer[i] == rollTemp) {
								flagtemp_Bool = false;
								break;
							}
						}
						if (flagtemp_Bool) {
							Roll_Answer[turnPlace_Int] = rollTemp;
							turnPlace_Int++;
						}
					}
					return true;
				}
				else {
					return false;
				}
			}
			else {
				for (int i = 0; i < times_Int; i++) {
					rollTemp = random(faceNumber_Int);
					if (rollTemp == 0) {
						rollTemp = faceNumber_Int;
					}
					Roll_Answer[i] = rollTemp;
				}
				return true;
			}
		}
		else {
			return false;
		}
	}
};
	int main() {
		int faceNumber_Int = 0, times_Int = 0, flagRecur_Bool = true;
		char faceNumber_Char;
		cout << "骰子面数：";
		cin >> faceNumber_Int;
		cout << endl;
		cout << "投骰次数：";
		cin >> times_Int;
		cout << endl;
		cout << "是否查重(y/n)：";
		cin >> faceNumber_Char;
		cout << endl;
		switch (faceNumber_Char) {
		case 'y':
			flagRecur_Bool = true;
			break;
		case 'n':
			flagRecur_Bool = false;
			break;
		default:
			cout << "Error" << endl;
			exit(-1);
		}
		Roll Roll1;
		Roll1.RollMain(faceNumber_Int, times_Int, times_Int);
			if (Roll1.RollCheck(faceNumber_Int, times_Int, flagRecur_Bool)) {
				Roll1.RollMain(faceNumber_Int, times_Int, flagRecur_Bool);
			}else {
				End().StdError();
			}

		for (int i = 0; i < times_Int; i++) {
			if (i > 0) {
				cout << ',';
			}
			cout << Roll1.Roll_Answer[i];
		}
		cout << endl;
		End().Normal();
	}