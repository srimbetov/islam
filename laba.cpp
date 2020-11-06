#include <iostream>
#include <ctime>
#include <vector>
using namespace std;

class MyClass
{
public:
	MyClass(const int size1, const int size2)
	{
		for (int i = 0; i < size1; i++) Arr1.push_back(rand() % 10);
		for (int i = 0; i < size2; i++) Arr2.push_back(rand() % 10);
	}
	MyClass(const MyClass& other)
	{
		for (int i = 0; i < other.Arr1.size(); i++)
			Arr1.push_back(other.Arr1[i]);

		for (int i = 0; i < other.Arr2.size(); i++)
			Arr2.push_back(other.Arr2[i]);
	}
	~MyClass()
	{
		Arr1.clear();
		Arr2.clear();
	}
	void print()
	{
		cout << "1 массив: ";
		for (int i = 0; i < Arr1.size(); i++) cout << Arr1[i] << " ";
		cout << endl << "2 массив: ";
		for (int i = 0; i < Arr2.size(); i++) cout << Arr2[i] << " ";
		cout << endl;
	}

	MyClass operator &()
	{
		bool ready;
		vector<int> temp;

		for (int i = 0; i < Arr1.size(); i++)
			for (int j = 0; j < Arr2.size(); j++)
			{
				ready = false;

				if (Arr1[i] == Arr2[j]) ready = true;

				for (int k = 0; k < temp.size(); k++)
					if (temp[k] == Arr1[i])
						ready = false;

				if (ready) temp.push_back(Arr1[i]);
			}

		cout << "Массив: ";
		for (int i = 0; i < temp.size(); i++) cout << temp[i] << " ";
		cout << endl;

		return *this;
	}

private:
	vector<int> Arr1, Arr2;
};

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(nullptr));

	int size1, size2;

	cout << "Введите размер 1 массива: ";
	cin >> size1;
	cout << "Введите размер 2 массива: ";
	cin >> size2;
	cout << endl;

	MyClass mc1(size1, size2);
	mc1.print();
	cout << endl;
	
	&mc1;
	cout << endl;
	
	MyClass mc2(mc1);
	mc2.print();

	return 0;
}
