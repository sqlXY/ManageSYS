#include <iostream>
#include <cstdlib> 
#include <iomanip>
#include <cstring>
#include <iostream>  
#include <fstream> 
using namespace std; 

const int StuNum = 100; //可以录入100个学生的信息，若如增加改动此数值即可。 
void clearScreen(); //清屏


class student {
private:
	int num;      		   /*学号*/
	string name;     	   /*姓名*/
	string sex;      	   /*性别*/
	double cppScore;       /*C++成绩*/
	double mathScore;      /*数学成绩*/
	double engScore;       /*英语成绩*/
	double yuScore;        /*语文成绩*/
	double totalScore;     /*总分*/
	double aveScore;       /*平均分*/
	int Rank;              /*名次*/
	int Class;             /*班级*/
	int Grade;             /*年级*/
	string family;   	   /*计算机系*/
public:
	student() {  //默认构造函数
		num = -1; //设学号为-1，今后只要检测到为-1，说明为未录入信息的数组。 
	}
	student(int _num, string _name, string _sex, int _Class, int _Grade, string _family, double _cppScore, double _mathScore, double _engScore, double _yuScore) {
		num = _num;
		name = _name;
		sex = _sex;
		Class = _Class;
		Grade = _Grade;
		family = _family;
		cppScore = _cppScore;
		mathScore = _mathScore;
		engScore = _engScore;
		yuScore = _yuScore;
	}
	int rNum() {
		return num;
	}
	void sNum(int _num) {
		num = _num;
	}
	string rName() {
		return name;
	}
	string rSex() {
		return sex;
	}
	double rCppScore() {
		return cppScore;
	}
	double rMathScore() {
		return mathScore;
	}
	double rEngScore() {
		return engScore;
	}
	double rYuScore() {
		return yuScore;
	}
	double rTotalScore() {
		return totalScore;
	}
	double rAveScore() {
		return aveScore;
	}
	int rRank() {
		return Rank;
	}
	void sRank(int num) {
		Rank = num;
	}
	int rClass() {
		return Class;
	}
	int rGrade() {
		return Grade;
	}
	string rFamily() {
		return family;
	}
	void set(); //信息录入
	void print(); //信息输出
	void culc(); //计算总分与平均分
	void batchSet(int _num, string _name, string _sex, int _Rank, int _Class, int _Grade, string _family, double _cppScore, double _mathScore, double _engScore, double _yuScore, double _totalScore, double _aveScore); //批量信息录入; 
}; 

class mainSystem {
private:
	student Stu[StuNum];
public:
	int returnPosition(int num); //返回所输入的学号在Stu数组中的位置
	int length(); //已输入的信息条数 
	void insertInfo(); //信息插入
	void setInfo(); //连续插入 
	void findInfo(); //信息查询
	void deleteInfo(); //信息删除
	void saveInfo(); //写入文件
	void readInfo(); //读取文件
	void updateInfo(); //信息修改 
	void sort(); //排序
	void Statistics(); //统计 
	void display(); //显示所有学生 
	bool refer(int flag, int j); //排序依据 
	void updateRank(); //更新排名 
}; 

void student::set() {
	cout << "录入学生信息，请输入" << endl;
	cout << "学号：";
	cin >> num;
	cout << "姓名：";
	cin >> name;     
	cout << "性别：";	   
	cin >> sex;
	cout << "C++成绩：";
	cin >> cppScore;
	cout << "数学成绩：";
	cin >> mathScore;
	cout << "英语成绩：";
	cin >> engScore;
	cout << "语文成绩：";
	cin >> yuScore;
	cout << "班级：";
	cin >> Class;
	cout << "年级：";
	cin >> Grade;
	cout << "计算机系：";
	cin >> family;
} 

void student::print() {
	cout << left << setw(9) << "学号";
	cout << left << setw(9) << "姓名";     
	cout << left << setw(9) << "性别";
	cout << left << setw(9) << "班级";
	cout << left << setw(9) << "年级";
	cout << left << setw(9) << "计算机系" << endl;
	cout << left << setw(9) << num;
	cout << left << setw(9) << name;     
	cout << left << setw(9) << sex;
	cout << left << setw(9) << Class;
	cout << left << setw(9) << Grade;
	cout << left << setw(9) << family << endl;
	cout << left << setw(9) << "C++成绩";
	cout << left << setw(9) << "数学成绩";
	cout << left << setw(9) << "英语成绩";
	cout << left << setw(9) << "语文成绩";
	cout << left << setw(9) << "平均成绩";
	cout << left << setw(9) << "名次" << endl;
	cout << left << setw(9) << cppScore;
	cout << left << setw(9) << mathScore;
	cout << left << setw(9) << engScore;
	cout << left << setw(9) << yuScore;
	cout << left << setw(9) << aveScore;
	cout << left << setw(9) << Rank << endl;
	cout << endl;
}

void student::culc() {
	totalScore = cppScore + mathScore + engScore + yuScore;
	aveScore = totalScore / 4;
}

void student::batchSet(int _num, string _name, string _sex, int _Rank, int _Class, int _Grade, string _family, double _cppScore, double _mathScore, double _engScore, double _yuScore, double _totalScore, double _aveScore) {
		num = _num;
		name = _name;
		sex = _sex;
		Rank = _Rank;
		Class = _Class;
		Grade = _Grade;
		family = _family;
		cppScore = _cppScore;
		mathScore = _mathScore;
		engScore = _engScore;
		yuScore = _yuScore;
		totalScore = _totalScore;
		aveScore = _aveScore;
}



int mainSystem::returnPosition(int num) {
	int i;
	for(i = 0; i < StuNum; i++) {
		if(Stu[i].rNum() == num) break;
	}
	if(i == StuNum) return -1; //若未查询到就返回-1 
	return i; //正常情况下返回查询到的位置 
} 

int mainSystem::length() {
	int i;
	for(i = 0; i < StuNum; i++) {
		if(Stu[i].rNum() == -1) break;
	}
	return i;
} 

void mainSystem::insertInfo() {
	int i = length();
	Stu[i].set();
	Stu[i].culc(); 
	cout << "录入成功！" << endl;
	updateRank();
}

void mainSystem::setInfo() {
	int flag;
	do {
		insertInfo();
		cout << "是否继续输入？若是请输入1，若返回请输入0或其他数字：";
		cin >> flag;
		clearScreen(); 
	} while(flag == 1);
	updateRank();
} 

void mainSystem::findInfo() {
	int num ,i;
	cout << "请输入学号：";
	cin >> num;
	i = returnPosition(num);
	if(i == -1) {
		cout << "没有此学生！" << endl; 
	} else {
		cout << "查询成功！" << endl;
		Stu[i].print();
	}
	cout << endl;
}

void mainSystem::deleteInfo() {
	int num ,i;
	cout << "请输入学号：";
	cin >> num;
	i = returnPosition(num);
	if(i == -1) {
		cout << "没有此学生！" << endl; 
	} else {
		for(; i < length() - 1; i++) {
			Stu[i] = Stu[i+1];
		}
		Stu[i].sNum(-1);
		cout << "删除成功" << endl; 
	}
	cout << endl;
	updateRank();
} 

void mainSystem::updateInfo() {
	int num, i;
	cout << "请输入要修改学生的学号：";
	cin >> num;
	i = returnPosition(num);
	if(i == -1) {
		cout << "没有此学生！" << endl; 
	} else {
		cout << "对" << Stu[i].rNum() << "(" << Stu[i].rName() << ")进行修改" << endl;
		Stu[i].set();
		Stu[i].culc(); 
		cout << "修改成功！" << endl;
	}
	cout << endl;
	updateRank();
}

void mainSystem::saveInfo() {
	ofstream outfile;  
    outfile.open("data.txt");  
	for(int i = 0; i < length(); i++) {
		if(Stu[i].rNum() != -1) {
			outfile << Stu[i].rNum() << " " << Stu[i].rName() << " " << Stu[i].rSex() << " " << Stu[i].rRank() << " " << Stu[i].rClass() << " " << Stu[i].rGrade() << " " << Stu[i].rFamily();
  			outfile << " " << Stu[i].rCppScore() << " " << Stu[i].rMathScore() << " " << Stu[i].rEngScore() << " " << Stu[i].rYuScore() << " " << Stu[i].rTotalScore() << " " << Stu[i].rAveScore();
		}
		if(Stu[i+1].rNum() != -1) {
			outfile <<endl;
		}
	}
    outfile.close(); 
} 

void mainSystem::readInfo() {
	ifstream infile;
	int count = 0;
	int _num, _Rank, _Class, _Grade;
	string _name, _sex, _family;
	double _cppScore, _mathScore, _engScore, _yuScore, _totalScore, _aveScore;
    infile.open("data.txt");  
    if(!infile.is_open())  
    {  
        cout<<"无法打开文件!!!";  
        return;  
    }
    while(infile.good())  
    {
        infile >> _num >> _name >> _sex >> _Rank >> _Class >> _Grade >> _family;
		infile >> _cppScore >> _mathScore >> _engScore >> _yuScore >> _totalScore >> _aveScore;
		Stu[count++].batchSet(_num, _name, _sex, _Rank, _Class, _Grade, _family, _cppScore, _mathScore, _engScore, _yuScore, _totalScore, _aveScore);
    }
    infile.close();
} 

bool mainSystem::refer(int flag, int j) {
	switch(flag) {
		case 1: return Stu[j+1].rNum() > Stu[j].rNum(); break;
		case 2: return Stu[j+1].rCppScore() > Stu[j].rCppScore(); break;
		case 3: return Stu[j+1].rMathScore() > Stu[j].rMathScore(); break;
		case 4: return Stu[j+1].rEngScore() > Stu[j].rEngScore(); break;
		case 5: return Stu[j+1].rYuScore() > Stu[j].rYuScore(); break;
		case 6:
		case 7:
		case 8: return Stu[j+1].rTotalScore() > Stu[j].rTotalScore();
		default: return false;
	}
} 

void mainSystem::sort() {
	int flag; 
	cout<<"请选择以何种方式排序:"<<endl;
	cout<<"1.以学号排序"<<endl;
	cout<<"2.以c++成绩排序"<<endl;
	cout<<"3.以数学成绩排序"<<endl;
	cout<<"4.以英语成绩排序"<<endl;
	cout<<"5.以语文成绩排序"<<endl;
	cout<<"6.以总分排序"<<endl;
	cout<<"7.以平均分排序"<<endl;
	cout<<"8.以名次排序"<<endl;
	cout<<"请选择(1-8):"<<endl;
	cin >> flag;
	for (int i = 0; i < length() - 1; i++) {
		for (int j = 0; j < length() - i - 1; j++) {
			if (refer(flag, j)) {
            	student temp = Stu[j];
                Stu[j] = Stu[j+1];
                Stu[j+1] = temp;
            }
        }
    }
    display();
} 

void mainSystem::display() {
	for(int i = 0; i < length(); i++) {
		Stu[i].print();
	}
} 

void mainSystem::Statistics() {
	int count;
	cout<<"*********************************************\n";
	cout<<"**************** C++不及格 ******************\n";
	count = 0;
	for(int i = 0; i < length(); i++) {
		if(Stu[i].rCppScore() < 60) {
			if(count == 0) {
				cout << left << setw(9) << "学号";
				cout << left << setw(9) << "姓名";     
				cout << left << setw(9) << "性别";
				cout << left << setw(9) << "班级";
				cout << left << setw(9) << "年级";
				cout << left << setw(13) << "计算机系";
				cout << left << setw(9) << "C++成绩"  << endl;
			} 
			count++;
			cout << left << setw(9) << Stu[i].rNum();
			cout << left << setw(9) << Stu[i].rName();     
			cout << left << setw(9) << Stu[i].rSex();
			cout << left << setw(9) << Stu[i].rClass();
			cout << left << setw(9) << Stu[i].rGrade();
			cout << left << setw(13) << Stu[i].rFamily(); 
			cout << left << setw(9) << Stu[i].rCppScore() << endl;
		}
	}
	if(count == 0){
		cout<<"******************* 无 **********************\n";
	} else {
		cout<<"****************** 共" << count << "人 ********************\n";	
	}
	cout<<"*********************************************\n";
	cout<<"**************** 数学不及格 ******************\n";
	count = 0;
	for(int i = 0; i < length(); i++) {
		if(Stu[i].rMathScore() < 60) {
			if(count == 0) {
				cout << left << setw(9) << "学号";
				cout << left << setw(9) << "姓名";     
				cout << left << setw(9) << "性别";
				cout << left << setw(9) << "班级";
				cout << left << setw(9) << "年级";
				cout << left << setw(13) << "计算机系";
				cout << left << setw(9) << "数学成绩"  << endl;
			} 
			count++;
			cout << left << setw(9) << Stu[i].rNum();
			cout << left << setw(9) << Stu[i].rName();     
			cout << left << setw(9) << Stu[i].rSex();
			cout << left << setw(9) << Stu[i].rClass();
			cout << left << setw(9) << Stu[i].rGrade();
			cout << left << setw(13) << Stu[i].rFamily(); 
			cout << left << setw(9) << Stu[i].rMathScore() << endl;
		}
	}
	if(count == 0){
		cout<<"******************* 无 **********************\n";
	} else {
		cout<<"****************** 共" << count << "人 ********************\n";	
	}
	cout<<"*********************************************\n";
	cout<<"**************** 语文不及格 ******************\n";
	count = 0;
	for(int i = 0; i < length(); i++) {
		if(Stu[i].rYuScore() < 60) {
			if(count == 0) {
				cout << left << setw(9) << "学号";
				cout << left << setw(9) << "姓名";     
				cout << left << setw(9) << "性别";
				cout << left << setw(9) << "班级";
				cout << left << setw(9) << "年级";
				cout << left << setw(13) << "计算机系";
				cout << left << setw(9) << "语文成绩"  << endl;
			} 
			count++;
			cout << left << setw(9) << Stu[i].rNum();
			cout << left << setw(9) << Stu[i].rName();     
			cout << left << setw(9) << Stu[i].rSex();
			cout << left << setw(9) << Stu[i].rClass();
			cout << left << setw(9) << Stu[i].rGrade();
			cout << left << setw(13) << Stu[i].rFamily(); 
			cout << left << setw(9) << Stu[i].rYuScore() << endl;
		}
	}
	if(count == 0){
		cout<<"******************* 无 **********************\n";
	} else {
		cout<<"****************** 共" << count << "人 ********************\n";	
	}
	cout<<"*********************************************\n";
	cout<<"**************** 英语不及格 ******************\n";
	count = 0;
	for(int i = 0; i < length(); i++) {
		if(Stu[i].rEngScore() < 60) {
			if(count == 0) {
				cout << left << setw(9) << "学号";
				cout << left << setw(9) << "姓名";     
				cout << left << setw(9) << "性别";
				cout << left << setw(9) << "班级";
				cout << left << setw(9) << "年级";
				cout << left << setw(13) << "计算机系";
				cout << left << setw(9) << "英语成绩"  << endl;
			} 
			count++;
			cout << left << setw(9) << Stu[i].rNum();
			cout << left << setw(9) << Stu[i].rName();     
			cout << left << setw(9) << Stu[i].rSex();
			cout << left << setw(9) << Stu[i].rClass();
			cout << left << setw(9) << Stu[i].rGrade();
			cout << left << setw(13) << Stu[i].rFamily(); 
			cout << left << setw(9) << Stu[i].rEngScore() << endl;
		}
	}
	if(count == 0){
		cout<<"******************* 无 **********************\n";
	} else {
		cout<<"****************** 共" << count << "人 ********************\n";	
	}
	cout<<"*********************************************\n";
	int bigest, w;
	bigest = w = 0;
	for(int i = 0; i < length(); i++) {
		if(Stu[i].rTotalScore() > bigest) {
			bigest = Stu[i].rTotalScore();
			w = i;
		}
	}
	cout << "总分最高：" << Stu[w].rGrade() << "-" << Stu[w].rFamily() << Stu[w].rClass() << "班-" << Stu[w].rName() << "(学号:" << Stu[w].rNum() << ")，总分:" << Stu[w].rTotalScore() << endl; 
	bigest = w = 0;
	for(int i = 0; i < length(); i++) {
		if(Stu[i].rCppScore() > bigest) {
			bigest = Stu[i].rCppScore();
			w = i;
		}
	}
	cout << "C++最高：" << Stu[w].rGrade() << "-" << Stu[w].rFamily() << Stu[w].rClass() << "班-" << Stu[w].rName() << "(学号:" << Stu[w].rNum() << ")，C++:" << Stu[w].rCppScore() << endl;
	bigest = w = 0;
	for(int i = 0; i < length(); i++) {
		if(Stu[i].rMathScore() > bigest) {
			bigest = Stu[i].rMathScore();
			w = i;
		}
	}
	cout << "数学最高：" << Stu[w].rGrade() << "-" << Stu[w].rFamily() << Stu[w].rClass() << "班-" << Stu[w].rName() << "(学号:" << Stu[w].rNum() << ")，数学:" << Stu[w].rMathScore() << endl;
	bigest = w = 0;
	for(int i = 0; i < length(); i++) {
		if(Stu[i].rYuScore() > bigest) {
			bigest = Stu[i].rYuScore();
			w = i;
		}
	}
	cout << "语文最高：" << Stu[w].rGrade() << "-" << Stu[w].rFamily() << Stu[w].rClass() << "班-" << Stu[w].rName() << "(学号:" << Stu[w].rNum() << ")，语文:" << Stu[w].rYuScore() << endl;
	bigest = w = 0;
	for(int i = 0; i < length(); i++) {
		if(Stu[i].rEngScore() > bigest) {
			bigest = Stu[i].rEngScore();
			w = i;
		}
	}
	cout << "英语最高：" << Stu[w].rGrade() << "-" << Stu[w].rFamily() << Stu[w].rClass() << "班-" << Stu[w].rName() << "(学号:" << Stu[w].rNum() << ")，语文:" << Stu[w].rEngScore() << endl;
	cout << "输入任意字符返回" << endl;
	getchar();getchar();
	clearScreen();
	return; 
} 

void mainSystem::updateRank() {
	for (int i = 0; i < length() - 1; i++) {
		for (int j = 0; j < length() - i - 1; j++) {
			if (Stu[j].rTotalScore() < Stu[j+1].rTotalScore()) {
            	student temp = Stu[j];
                Stu[j] = Stu[j+1];
                Stu[j+1] = temp;
            }
        }
    }
    for (int i = 0; i < length(); i++) {
    	Stu[i].sRank(i+1);
	}
} 


int main() {
	int c;
	mainSystem system;
	do
	{
		cout<<"*********************************************\n";
		cout<<"*************  学生成绩管理系统  ************\n";
		cout<<"*********************************************\n";
		cout<<"*************  1.  输入学生信息  ************\n"; 
		cout<<"*************  2.  删除学生信息  ************\n";
		cout<<"*************  3.  插入学生信息  ************\n";
		cout<<"*************  4.  修改学生信息  ************\n";
		cout<<"*************  5.  查询学生信息  ************\n"; 
		cout<<"*************  6.  排序学生成绩  ************\n";
		cout<<"*************  7.  统计学生成绩  ************\n";
		cout<<"*************  8.  保存学生信息  ************\n";
		cout<<"*************  9.  读取学生信息  ************\n";
		cout<<"*************  10.  退出系统     ************\n";
		cout<<"*********************************************\n";
		cout<<"*************     作者：医生     ************\n";
		cout<<"*************       YConxy       ************\n";
		cout<<"*************      信息安全      ************\n";
		cout<<"*********************************************\n";
		cout<<"请选择(1-10):";
		cin>>c;
		clearScreen();
		switch (c) { 
			case 1: system.setInfo(); break;
			case 2: system.deleteInfo(); break;
			case 3: system.insertInfo(); break;
			case 4: system.updateInfo(); break;
			case 5: system.findInfo(); break;
			case 6: system.sort(); break;
			case 7: system.Statistics();break;
			case 8: system.saveInfo(); break;
			case 9: system.readInfo(); break;
		}
	} while(c != 10);
	return 0;
}

void clearScreen() { //清屏 
	system("cls");
}
