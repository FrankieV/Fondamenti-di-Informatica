#include <iostream>
#include <climits>
using namespace std;

int main()
{

    int successivo = 0;
    int num_max = INT_MIN;
    bool vuoto = true;

    cin >> successivo;

    while(successivo != -1)
    {
        vuoto = false;

        if( successivo > num_max)
        {
            num_max = successivo;
        }

        cin >> successivo;
    }

  if(vuoto)
  {
      cout << "EMPTY" << endl;
  }
  else
  {
      cout << num_max << endl;
  }

  return 0;

}
