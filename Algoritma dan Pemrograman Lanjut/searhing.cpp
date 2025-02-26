/*
// search_non_sentinel.cpp   (Data tidak terurut non sentinel)
// Data array a[0..9] dan belum terurut, data yang dicari X, found var boolean (True,False)

// #include "stdafx.h"
#include <iostream>
using namespace std;
int main()
{ int a[10]={10,2,9,4,8,6,1,3,7,5};
  int i,x; bool found;
  cout << "nilai yang dicari = "; cin >> x;
  i=0; found=false;
  while ((i<10) && (!found))
  { if (a[i]==x)
       found = true;
    else
       i = i + 1;
  }
  if(found)
     cout << x <<" ditemukan pada index array ke-" <<i<< endl;
  else
     cout << x <<" tidak terdapat pada array tersebut"<< endl;
  cout << " "<< endl;
  system("pause");
}
  */


/////////////////////////////////////////////////////
/*
 // #include "stdafx.h"
  #include <iostream>
  using namespace std;
  int main()
  { int a[11]={10,2,9,4,8,1,3,6,7,5};
    int i,x; 
    cout << "nilai yang dicari = "; cin >> x;
    a[10]=x; // Sentinel
    i=0;   
    while (a[i] != x)
       i = i + 1;
    if(i<10)
       cout << x <<" ditemukan pada index array ke-" <<i<< endl;
    else
       cout << x <<" tidak terdapat pada array tersebut"<< endl;
    cout << " "<< endl;
    system("pause");
  }
*/

////////////////////////////////////////////////
/*
//#include "stdafx.h"
#include <iostream>
using namespace std;
int main()
{ int a[11]={2,4,7,10,13,17,21,25,28};
  int i,x; bool found;
  cout << "nilai yang dicari = "; cin >> x;
  i=0; found=false;  
  a[10] = x;  // Sentinel
  while ((i<=10) && (!found) && (a[i]<=x))  
  { if (a[i]==x)
       found = true;
    else
       i = i + 1;
  }
  if(i<10 && (found))
     cout << x <<" ditemukan pada index array ke-" <<i<< endl;
  else
     cout << x <<" tidak terdapat pada array tersebut"<< endl;
  cout << " "<< endl;
  system("pause");
}
*/


///////////////////////////////////////////////////////////
/*
// Search_Binary.cpp      (Data terurut, pencarian secara binary).
// Data array a[0..9] dan terurut, data yang dicari X, 
//#include "stdafx.h"
#include <iostream>
using namespace std;
int main()
{ int a[10]={2,4,7,10,13,17,21,25,28};
  int i,j,t,x; bool found;
  cout << "nilai yang dicari = "; cin >> x;
  i=0;  j=10;  found=false;  // i: index awal     j: index akhir
  while ((!found) & (i <= j))
  { t = (i + j) / 2;     // index tengah
    if (a[t]==x)
	found=true;       // Data ditemukan
    else
	if (x < a[t])
	   j = t - 1;    // index awal tetap,  index akhir = index tengah - 1 
	else
	   i = t + 1;    // index awal = index tengah + 1, index akhir = tetap
  }
  if(found)
     cout << x <<" ditemukan pada index array ke-" <<i<< endl;
  else
     cout << x <<" tidak terdapat pada array tersebut"<< endl;
}*/



// BinSearch_SudahUrut
/*
diasumsikan Array X sudah ada dan berisi data yang sudah terurut,
nilai yang dicari adalah y dan hanya ada satu 
#include <iostream>

typedef enum boolean {
    bool false=0,true=1
};

int main()
{
 int X[10]={10,20,30,40,50,60,70,80,90,100};
 int i,y,j,k;
 boolean found;
 cout << "nilai yang dicari = ";
 cin >> y;
 found = false;
 i=0;
 j=10;
 while ((!found) & (i <= j))
 {
	 k=(i+j)/2;
	 if (y == X[k])
		found=true;
	 else
		if (y<X[k])
			j=k-1;    //i tetap
		else
			i=k+1; //j tetap
 }
 if (found)
	cout<< y<<"ditemukan dalam Array pada index ke-" << k;
 else
	cout << "tidak ada " << y << " dalam Array";
}
*/



#include <iostream>
using namespace std;

int main()
{
    int X[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int i, y, j, k;
    bool found;

    cout << "Nilai yang dicari = ";
    cin >> y;

    found = false;
    i = 0;
    j = 9;

    while ((!found) && (i <= j))
    {
        k = (i + j) / 2;
        if (y == X[k])
            found = true;
        else if (y < X[k])
            j = k - 1;  // i tetap
        else
            i = k + 1;  // j tetap
    }

    if (found)
        cout << y << " ditemukan dalam Array pada index ke-" << k << endl;
    else
        cout << "Tidak ada " << y << " dalam Array" << endl;

    return 0;
}


