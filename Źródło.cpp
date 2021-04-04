#include <iostream>

using namespace std;

class AStos
{
private:
	int* items; //tablica przechowujaca elementy stosu
	int capacity; //max pojemnosc tablicy
	int sp; //wskaznik na szczyt stosu, stack pointer
public:
	AStos(int c); //konstruktor
	bool empty(); //zwraca true, jesli stos jest pusty, w przeciwnym razie zwraca false
	bool full(); //zwraca true, jesli stos jest pelny, w przeciwnym razie zwraca false
	void push(int x); //dodaje element na szczyt stosu
	int pop();		//usuwa element ze szczytu stosu i zwraca daną ze stosu
	void clear(); //zwalnia pamiec, czyli usuwa cala tablice dynamiczna przechowujaca elementy stosu
	friend ostream& operator<<(ostream& out, AStos& s);
};

AStos::AStos(int c) //jako parametr przyjmuje c, czyli max pojemnosc tablicy dynamicznej
{
	items = new int[c];
	capacity = c;
	sp = 0; //jezeli stos jest pusty sp przyjmuje indeks pierwszej komorki tablicy, jesli jest pelny to wskazuje indeks komorki tuz nad szczytem stosu
}

bool AStos::empty()
{
	/**if (sp == 0)
	{
		return true;
	}
	else
	{
		return false;
	}**/

	if (sp == 0)
		return true;
	return false;
}

bool AStos::full()
{
	/**if (sp == capacity - 1)
	{
		return true;
	}
	else
	{
		return false;
	}**/

	if (sp == capacity)
		return true;
	return false;
}

void AStos::push(int x)
{
	if (!full())
	{
		items[sp] = x;
		sp++;
	}
	else
	{
		//cout << "Stos jest pelny!" << endl;
		return;
	}
}

int AStos::pop()
{
	if (!empty())
	{
		sp--;
		int wartosc;
		wartosc = items[sp];
		return wartosc;
	}
	else
	{
		//cout << "Stos jest pusty!" << endl;
		return NULL;
	}
}

void AStos::clear()
{
	if (!empty())
	{
		sp = 0;
	}
	else
	{
		//cout << "Stos jest pusty!" << endl;
		return;
	}
}

ostream& operator<<(ostream& out, AStos& s)
{
	int temp = s.sp - 1;
	while (temp >= 0)
	{
		out << s.items[temp] << "  ";
		temp--;
	}
	return out;
}

/**driver code**/
int main()
{
	//AStos s(10);
	//drugi sposob
	AStos s = AStos(10);

	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	cout << s << endl;

	s.pop();
	cout << s << endl;

	return 0;
}