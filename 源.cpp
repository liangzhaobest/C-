#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
class Transportation
{
private:
	char cname[10];
	int  carnum;
	int year, month, day;
	float km;
	int  ymoney, total_money;
public:
	int y,Number;
	int i = 0;
	float V;
	int N, C, X, T;
	void Getinfor(), Getbus(), Getcar(), Gettruck(), Getbasic();
	void Showsort(Transportation a[], int n);
	void  Showinfor(), showbasic(), Showbus(), Showcar(), Showtruck();
	void Judge();
	friend void Getoption();
};
Transportation m[3];
int b(0), c(0), t(0);
void Transportation::Getinfor()
{
	cout << "�����복�����͵���ţ�bus(0),car(1) or truck(2)):";
	cin >> y;
	switch (y)
	{
	case 0:Getbus();b = b + 1;Judge(); break;
	case 1:Getcar();c = c + 1; Judge();break;
	case 2:Gettruck();t = t + 1;Judge(); break;
	default:cout << "�������û���������͵ĳ���";Getinfor();
		break;
	}

}
void  Transportation::Getbasic()
{
	cout << "**��ţ�";cin >> m[i].Number;cout << Number;
	cout << "**���ƺţ�";cin >> m[i].carnum;
	cout << "**����ʱ�䣺���-";cin >> m[i].year;cout << "�·�-";cin >> m[i].month;cout << "��-";cin >> m[i].day;
	cout << "**���칫˾��";cin >> m[i].cname;
	cout << "**�ܹ�������";cin >> m[i].km;
	cout << "**��������";cin >> m[i].V;
	cout << "**��·�ѣ�";cin >> m[i].ymoney;
	

}
void Transportation::Getbus()
{
	Getbasic();
	cout << "**�ؿ�����";cin >> m[i].C;

}
void Transportation::Getcar()
{
	Getbasic();
	cout << "**������";cin >> m[i].X;
}
void Transportation::Gettruck()
{
	Getbasic();
	cout << "**�������������֣���";cin >> m[i].T;
}
void Transportation::Showinfor()
{
	int i = 0;
	switch (y)
	{
	case 0:m[i].Showbus(); break;
	case 1:m[i].Showcar();break;
	case 2:m[i].Showtruck(); break;
	default:cout << "����û���������͵ĳ���";
		break;
	}
}
void Transportation::Showbus()
{
	showbasic();
	cout << "�ؿ�����" << m[i].C << "��" << endl;
}
void Transportation::Showcar()
{
	showbasic();
	cout << "������" << m[i].X << "��" << endl;
}
void Transportation::Showtruck()
{
	showbasic();
	cout << "��������" << m[i].T << "��" << endl;
}
void Transportation::showbasic()
{
	cout << "**���:" << m[i].Number << " ���ƺţ�" << m[i].carnum << " ����ʱ�䣺" << m[i].year << "-" << m[i].month << "-" << m[i].day << "\n���칫˾��" << m[i].cname << " ��ʻ������" << m[i].km << "  ��������" << m[i].V << " ��·��:" << m[i].ymoney;
}
class Management :public Transportation
{
private:
public:

	void TJ();
	friend void Transportation::Getinfor();
};
void Management::TJ()
{
	cout << "��ͳ����У�" << b << "����" << "С�γ����У�" << c << "����" << "�󿨳����У�" << t << "����\n" << "���ƣ�" << b + c + t << "������" << endl;
}
void create()
{
	cout << "�������������Ѵ�����" << endl;
}
void Sort(Transportation a[], int n)
{
	Transportation temp;
	for (int i = 0;i < n;i++)
	{
		for (int j = 1;j < n - 1;j++)
		{
			if (a[j].V > a[j - 1].V)
			{
				temp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = temp;
			}
		}
	}
}
void Transportation::Showsort(Transportation a[], int n)
{
	for (int i = 0;i < n;i++)
	{
		cout << "��ţ�" << a[i].Number << "��������" << a[i].V << endl;;
	}
}
void Showmenu()
{
	cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n"
		<< "=================**1.���복������Ϣ**=================\n"
		<< "=================**2.��Ϣ��ѯ**=======================\n"
		<< "=================**3.�����ǰ������Ϣ**===============\n"
		<< "=================**4.�༭��Ϣ**=======================\n"
		<< "=================**5.ɾ������**=======================\n"
		<< "=================**6.ͳ����Ϣ**=======================\n"
		<< "=================**7.������**=======================\n"
		<< "=================**8.���ز˵�**=======================\n"
		<< "=================**9.�˳�ϵͳ**=======================\n" << endl;
}
void   Delay(int  time)
{
	clock_t   now = clock();
	while (clock() - now < time);
}
void Getoption()
{
	cout << "**�밴����ѡ����Ӧ�Ĺ���**\n"
		<< "!!ѡ���˳��������3���ر�!!" << endl;
	Showmenu();
	int x;
	int i = 0;
	cin >> x;
	Management ma;
	switch (x)
	{
	case 1:cout << "***************�����복����Ϣ��****************" << endl;m[i].Getinfor();break;
	case 2:cout << "***************����ѯ������Ϣ��****************" << endl;break;
	case 3:cout << "***************�����������Ϣ��****************" << endl;m[i].Showinfor();m[i].Judge();  break;
	case 4:cout << "***************���༭������Ϣ��****************" << endl;break;
	case 5:cout << "***************��ɾ��������Ϣ��****************" << endl;break;
	case 6:cout << "***************��ͳ�Ƴ�����Ϣ��****************" << endl;;ma.TJ(); break;
	case 7:cout << "***************����������Ϣ��****************" << endl;Sort(m, 4);m->Showsort(m, 4); break;
	case 8:cout << "***************�����ز˵���********************" << endl;Getoption(); break;
	case 9:cout << "******************���˳�ϵͳ��*****************" << endl;cout << "��л����ʹ�ã�����";Delay(3 * 1000); break;
	default:cout << "�������������������������" << endl;
		break;
	}

}
void Transportation::Judge()
{
	cout << "*****************************\n";
	cout << "***1.����������Ϣ***\n"
		<< "***2.���ز˵�****\n" << endl;
	int x;cin >> x;
	if (x == 1)
		Getinfor();
	else Getoption();
}
int main()
{
	cout << "*********************************************************\n"
		<< "**********************************************************\n"
		<< "***************��ӭ������������ϵͳ��*********************\n"
		<< "**********************************************************\n"
		<< "**********************************************************\n" << endl;
	cout << "�������������" << endl;
	getchar();
	Getoption();
	return 0;
}