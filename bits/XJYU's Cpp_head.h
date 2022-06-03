//<MADE by XJYU666>//
/*
* Warning!!!
* 此头文件必须配合stdc++.h使用!
*/
#include"bits/stdc++.h"
#define random(x) rand()%(x);

class End {
public:
	void Normal() {
		system("pause");
		exit(0);
	}
	void StdError() {
		printf("Error/n");
		system("pause");
		exit(1);
	}
	void SerError() {
		exit(1);
	}
};