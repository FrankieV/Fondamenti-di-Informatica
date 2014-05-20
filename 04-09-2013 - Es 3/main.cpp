#include <iostream>

using namespace std;
const int n = 10;

int main()
{
	int A[n];
	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
	}

	int corrente = 0;
	int index = 2;
	bool trovato = false;
	int moltiplicando = 0;
	if (corrente == 0)
	{
		while (index < n && trovato == false)
		{
			for (int i = index; i < n - 1; i++)
			{
				if (A[corrente] == (A[index] * A[i + 1]))
				{
					cout << corrente << index << i + 1;
					trovato = true;
					break;
				}
			}

			index++;

		}
		corrente++;
		trovato = false;
	}
		while (corrente < n)
		{
			while (moltiplicando < n && trovato == false)
			{
				if (moltiplicando != corrente)
				{
					for (int i = 0; i < n; i++)
					{
						if (i != moltiplicando && i != corrente)
						{
							if (A[corrente] == (A[moltiplicando] * A[i]))
							{
								cout << corrente << moltiplicando << i;
								trovato = true;
								break;

							}
						}
					}

					moltiplicando++;
				}
				else
				{
					moltiplicando++;
				}
			}

			corrente++;
		}
}
