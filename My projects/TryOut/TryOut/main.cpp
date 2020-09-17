#include <iostream>

using namespace std;

// Typy danych

struct slistEl
{
	slistEl * next;
	int v, w;           // numer w�z�a docelowego i waga kraw�dzi
};

const int MAXINT = 2147483647;

// **********************
// *** PROGRAM G��WNY ***
// **********************

int main()
{
	int i, j, m, n, v, u, w, x, y, sptr, *d, *p, *S;
	bool *QS;           // Zbiory Q i S
	slistEl **graf;     // Tablica list s�siedztwa
	slistEl *pw, *rw;

	cin >> v >> n >> m; // W�ze� startowy, liczba wierzcho�k�w i kraw�dzi

	// Tworzymy tablice dynamiczne

	d = new int[n];          // Tablica koszt�w doj�cia
	p = new int[n];          // Tablica poprzednik�w
	QS = new bool[n];        // Zbiory Q i S
	graf = new slistEl *[n]; // Tablica list s�siedztwa
	S = new int[n];          // Stos
	sptr = 0;                   // Wska�nik stosu

	// Inicjujemy tablice dynamiczne

	for (i = 0; i < n; i++)
	{
		d[i] = MAXINT;
		p[i] = -1;
		QS[i] = false;
		graf[i] = NULL;
	}

	// Odczytujemy dane wej�ciowe

	for (i = 0; i < m; i++)
	{
		cin >> x >> y >> w;    // Odczytujemy kraw�d� z wag�
		pw = new slistEl;      // Tworzymy element listy s�siedztwa
		pw->v = y;             // Wierzcho�ek docelowy kraw�dzi
		pw->w = w;             // Waga kraw�dzi
		pw->next = graf[x];
		graf[x] = pw;       // Element do��czamy do listy
	}

	cout << endl;

	d[v] = 0;             // Koszt doj�cia v jest zerowy

	// Wyznaczamy �cie�ki

	for (i = 0; i < n; i++)
	{
		// Szukamy wierzcho�ka w Q o najmniejszym koszcie d

		for (j = 0; QS[j]; j++);
		for (u = j++; j < n; j++)
			if (!QS[j] && (d[j] < d[u])) u = j;

		// Znaleziony wierzcho�ek przenosimy do S

		QS[u] = true;

		// Modyfikujemy odpowiednio wszystkich s�siad�w u, kt�rzy s� w Q

		for (pw = graf[u]; pw; pw = pw->next)
			if (!QS[pw->v] && (d[pw->v] > d[u] + pw->w))
			{
				d[pw->v] = d[u] + pw->w;
				p[pw->v] = u;
			}
	}

	// Gotowe, wy�wietlamy wyniki

	for (i = 0; i < n; i++)
	{
		cout << i << ": ";

		// �cie�k� przechodzimy od ko�ca ku pocz�tkowi, 
		// Zapisuj�c na stosie kolejne wierzcho�ki

		for (j = i; j > -1; j = p[j]) S[sptr++] = j;

		// Wy�wietlamy �cie�k�, pobieraj�c wierzcho�ki ze stosu

		while (sptr) cout << S[--sptr] << " ";

		// Na ko�cu �cie�ki wypisujemy jej koszt

		cout << "$" << d[i] << endl;
	}

	// Usuwamy tablice dynamiczne

	delete[] d;
	delete[] p;
	delete[] QS;
	delete[] S;

	for (i = 0; i < n; i++)
	{
		pw = graf[i];
		while (pw)
		{
			rw = pw;
			pw = pw->next;
			delete rw;
		}
	}

	delete[] graf;

	return 0;
}