#include <iostream>
#include <cstdlib> 
#include <iomanip>
#include <cstring>
#include <iostream>  
#include <fstream> 
using namespace std; 

const int StuNum = 100; //����¼��100��ѧ������Ϣ���������ӸĶ�����ֵ���ɡ� 
void clearScreen(); //����


class student {
private:
	int num;      		   /*ѧ��*/
	string name;     	   /*����*/
	string sex;      	   /*�Ա�*/
	double cppScore;       /*C++�ɼ�*/
	double mathScore;      /*��ѧ�ɼ�*/
	double engScore;       /*Ӣ��ɼ�*/
	double yuScore;        /*���ĳɼ�*/
	double totalScore;     /*�ܷ�*/
	double aveScore;       /*ƽ����*/
	int Rank;              /*����*/
	int Class;             /*�༶*/
	int Grade;             /*�꼶*/
	string family;   	   /*�����ϵ*/
public:
	student() {  //Ĭ�Ϲ��캯��
		num = -1; //��ѧ��Ϊ-1�����ֻҪ��⵽Ϊ-1��˵��Ϊδ¼����Ϣ�����顣 
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
	void set(); //��Ϣ¼��
	void print(); //��Ϣ���
	void culc(); //�����ܷ���ƽ����
	void batchSet(int _num, string _name, string _sex, int _Rank, int _Class, int _Grade, string _family, double _cppScore, double _mathScore, double _engScore, double _yuScore, double _totalScore, double _aveScore); //������Ϣ¼��; 
}; 

class mainSystem {
private:
	student Stu[StuNum];
public:
	int returnPosition(int num); //�����������ѧ����Stu�����е�λ��
	int length(); //���������Ϣ���� 
	void insertInfo(); //��Ϣ����
	void setInfo(); //�������� 
	void findInfo(); //��Ϣ��ѯ
	void deleteInfo(); //��Ϣɾ��
	void saveInfo(); //д���ļ�
	void readInfo(); //��ȡ�ļ�
	void updateInfo(); //��Ϣ�޸� 
	void sort(); //����
	void Statistics(); //ͳ�� 
	void display(); //��ʾ����ѧ�� 
	bool refer(int flag, int j); //�������� 
	void updateRank(); //�������� 
}; 

void student::set() {
	cout << "¼��ѧ����Ϣ��������" << endl;
	cout << "ѧ�ţ�";
	cin >> num;
	cout << "������";
	cin >> name;     
	cout << "�Ա�";	   
	cin >> sex;
	cout << "C++�ɼ���";
	cin >> cppScore;
	cout << "��ѧ�ɼ���";
	cin >> mathScore;
	cout << "Ӣ��ɼ���";
	cin >> engScore;
	cout << "���ĳɼ���";
	cin >> yuScore;
	cout << "�༶��";
	cin >> Class;
	cout << "�꼶��";
	cin >> Grade;
	cout << "�����ϵ��";
	cin >> family;
} 

void student::print() {
	cout << left << setw(9) << "ѧ��";
	cout << left << setw(9) << "����";     
	cout << left << setw(9) << "�Ա�";
	cout << left << setw(9) << "�༶";
	cout << left << setw(9) << "�꼶";
	cout << left << setw(9) << "�����ϵ" << endl;
	cout << left << setw(9) << num;
	cout << left << setw(9) << name;     
	cout << left << setw(9) << sex;
	cout << left << setw(9) << Class;
	cout << left << setw(9) << Grade;
	cout << left << setw(9) << family << endl;
	cout << left << setw(9) << "C++�ɼ�";
	cout << left << setw(9) << "��ѧ�ɼ�";
	cout << left << setw(9) << "Ӣ��ɼ�";
	cout << left << setw(9) << "���ĳɼ�";
	cout << left << setw(9) << "ƽ���ɼ�";
	cout << left << setw(9) << "����" << endl;
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
	if(i == StuNum) return -1; //��δ��ѯ���ͷ���-1 
	return i; //��������·��ز�ѯ����λ�� 
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
	cout << "¼��ɹ���" << endl;
	updateRank();
}

void mainSystem::setInfo() {
	int flag;
	do {
		insertInfo();
		cout << "�Ƿ�������룿����������1��������������0���������֣�";
		cin >> flag;
		clearScreen(); 
	} while(flag == 1);
	updateRank();
} 

void mainSystem::findInfo() {
	int num ,i;
	cout << "������ѧ�ţ�";
	cin >> num;
	i = returnPosition(num);
	if(i == -1) {
		cout << "û�д�ѧ����" << endl; 
	} else {
		cout << "��ѯ�ɹ���" << endl;
		Stu[i].print();
	}
	cout << endl;
}

void mainSystem::deleteInfo() {
	int num ,i;
	cout << "������ѧ�ţ�";
	cin >> num;
	i = returnPosition(num);
	if(i == -1) {
		cout << "û�д�ѧ����" << endl; 
	} else {
		for(; i < length() - 1; i++) {
			Stu[i] = Stu[i+1];
		}
		Stu[i].sNum(-1);
		cout << "ɾ���ɹ�" << endl; 
	}
	cout << endl;
	updateRank();
} 

void mainSystem::updateInfo() {
	int num, i;
	cout << "������Ҫ�޸�ѧ����ѧ�ţ�";
	cin >> num;
	i = returnPosition(num);
	if(i == -1) {
		cout << "û�д�ѧ����" << endl; 
	} else {
		cout << "��" << Stu[i].rNum() << "(" << Stu[i].rName() << ")�����޸�" << endl;
		Stu[i].set();
		Stu[i].culc(); 
		cout << "�޸ĳɹ���" << endl;
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
        cout<<"�޷����ļ�!!!";  
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
	cout<<"��ѡ���Ժ��ַ�ʽ����:"<<endl;
	cout<<"1.��ѧ������"<<endl;
	cout<<"2.��c++�ɼ�����"<<endl;
	cout<<"3.����ѧ�ɼ�����"<<endl;
	cout<<"4.��Ӣ��ɼ�����"<<endl;
	cout<<"5.�����ĳɼ�����"<<endl;
	cout<<"6.���ܷ�����"<<endl;
	cout<<"7.��ƽ��������"<<endl;
	cout<<"8.����������"<<endl;
	cout<<"��ѡ��(1-8):"<<endl;
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
	cout<<"**************** C++������ ******************\n";
	count = 0;
	for(int i = 0; i < length(); i++) {
		if(Stu[i].rCppScore() < 60) {
			if(count == 0) {
				cout << left << setw(9) << "ѧ��";
				cout << left << setw(9) << "����";     
				cout << left << setw(9) << "�Ա�";
				cout << left << setw(9) << "�༶";
				cout << left << setw(9) << "�꼶";
				cout << left << setw(13) << "�����ϵ";
				cout << left << setw(9) << "C++�ɼ�"  << endl;
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
		cout<<"******************* �� **********************\n";
	} else {
		cout<<"****************** ��" << count << "�� ********************\n";	
	}
	cout<<"*********************************************\n";
	cout<<"**************** ��ѧ������ ******************\n";
	count = 0;
	for(int i = 0; i < length(); i++) {
		if(Stu[i].rMathScore() < 60) {
			if(count == 0) {
				cout << left << setw(9) << "ѧ��";
				cout << left << setw(9) << "����";     
				cout << left << setw(9) << "�Ա�";
				cout << left << setw(9) << "�༶";
				cout << left << setw(9) << "�꼶";
				cout << left << setw(13) << "�����ϵ";
				cout << left << setw(9) << "��ѧ�ɼ�"  << endl;
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
		cout<<"******************* �� **********************\n";
	} else {
		cout<<"****************** ��" << count << "�� ********************\n";	
	}
	cout<<"*********************************************\n";
	cout<<"**************** ���Ĳ����� ******************\n";
	count = 0;
	for(int i = 0; i < length(); i++) {
		if(Stu[i].rYuScore() < 60) {
			if(count == 0) {
				cout << left << setw(9) << "ѧ��";
				cout << left << setw(9) << "����";     
				cout << left << setw(9) << "�Ա�";
				cout << left << setw(9) << "�༶";
				cout << left << setw(9) << "�꼶";
				cout << left << setw(13) << "�����ϵ";
				cout << left << setw(9) << "���ĳɼ�"  << endl;
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
		cout<<"******************* �� **********************\n";
	} else {
		cout<<"****************** ��" << count << "�� ********************\n";	
	}
	cout<<"*********************************************\n";
	cout<<"**************** Ӣ�ﲻ���� ******************\n";
	count = 0;
	for(int i = 0; i < length(); i++) {
		if(Stu[i].rEngScore() < 60) {
			if(count == 0) {
				cout << left << setw(9) << "ѧ��";
				cout << left << setw(9) << "����";     
				cout << left << setw(9) << "�Ա�";
				cout << left << setw(9) << "�༶";
				cout << left << setw(9) << "�꼶";
				cout << left << setw(13) << "�����ϵ";
				cout << left << setw(9) << "Ӣ��ɼ�"  << endl;
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
		cout<<"******************* �� **********************\n";
	} else {
		cout<<"****************** ��" << count << "�� ********************\n";	
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
	cout << "�ܷ���ߣ�" << Stu[w].rGrade() << "-" << Stu[w].rFamily() << Stu[w].rClass() << "��-" << Stu[w].rName() << "(ѧ��:" << Stu[w].rNum() << ")���ܷ�:" << Stu[w].rTotalScore() << endl; 
	bigest = w = 0;
	for(int i = 0; i < length(); i++) {
		if(Stu[i].rCppScore() > bigest) {
			bigest = Stu[i].rCppScore();
			w = i;
		}
	}
	cout << "C++��ߣ�" << Stu[w].rGrade() << "-" << Stu[w].rFamily() << Stu[w].rClass() << "��-" << Stu[w].rName() << "(ѧ��:" << Stu[w].rNum() << ")��C++:" << Stu[w].rCppScore() << endl;
	bigest = w = 0;
	for(int i = 0; i < length(); i++) {
		if(Stu[i].rMathScore() > bigest) {
			bigest = Stu[i].rMathScore();
			w = i;
		}
	}
	cout << "��ѧ��ߣ�" << Stu[w].rGrade() << "-" << Stu[w].rFamily() << Stu[w].rClass() << "��-" << Stu[w].rName() << "(ѧ��:" << Stu[w].rNum() << ")����ѧ:" << Stu[w].rMathScore() << endl;
	bigest = w = 0;
	for(int i = 0; i < length(); i++) {
		if(Stu[i].rYuScore() > bigest) {
			bigest = Stu[i].rYuScore();
			w = i;
		}
	}
	cout << "������ߣ�" << Stu[w].rGrade() << "-" << Stu[w].rFamily() << Stu[w].rClass() << "��-" << Stu[w].rName() << "(ѧ��:" << Stu[w].rNum() << ")������:" << Stu[w].rYuScore() << endl;
	bigest = w = 0;
	for(int i = 0; i < length(); i++) {
		if(Stu[i].rEngScore() > bigest) {
			bigest = Stu[i].rEngScore();
			w = i;
		}
	}
	cout << "Ӣ����ߣ�" << Stu[w].rGrade() << "-" << Stu[w].rFamily() << Stu[w].rClass() << "��-" << Stu[w].rName() << "(ѧ��:" << Stu[w].rNum() << ")������:" << Stu[w].rEngScore() << endl;
	cout << "���������ַ�����" << endl;
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
		cout<<"*************  ѧ���ɼ�����ϵͳ  ************\n";
		cout<<"*********************************************\n";
		cout<<"*************  1.  ����ѧ����Ϣ  ************\n"; 
		cout<<"*************  2.  ɾ��ѧ����Ϣ  ************\n";
		cout<<"*************  3.  ����ѧ����Ϣ  ************\n";
		cout<<"*************  4.  �޸�ѧ����Ϣ  ************\n";
		cout<<"*************  5.  ��ѯѧ����Ϣ  ************\n"; 
		cout<<"*************  6.  ����ѧ���ɼ�  ************\n";
		cout<<"*************  7.  ͳ��ѧ���ɼ�  ************\n";
		cout<<"*************  8.  ����ѧ����Ϣ  ************\n";
		cout<<"*************  9.  ��ȡѧ����Ϣ  ************\n";
		cout<<"*************  10.  �˳�ϵͳ     ************\n";
		cout<<"*********************************************\n";
		cout<<"*************     ���ߣ�ҽ��     ************\n";
		cout<<"*************       YConxy       ************\n";
		cout<<"*************      ��Ϣ��ȫ      ************\n";
		cout<<"*********************************************\n";
		cout<<"��ѡ��(1-10):";
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

void clearScreen() { //���� 
	system("cls");
}
