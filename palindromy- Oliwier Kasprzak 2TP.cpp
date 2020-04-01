#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

class palindromy{
       ifstream plik1;
       ofstream plik2;

  public:
        palindromy();
        ~palindromy();

        void czy_palindrom();
};

palindromy::palindromy(){
    plik1.open("plik1.txt");
    plik2.open("plik2.txt");
}

void palindromy::czy_palindrom(){
string a,b,c ("");

plik2<<"[\n";

while(!plik1.eof())

    {
    getline(plik1, a);
    stringstream linia(a);
    while(linia >> b){
      c += b;
    }

    for(int i = 0; i<c.length(); i++)
        {
             if(c[i] >= 'a' && c[i] <= 'z')
        {
        c[i] -= 32;
        }
          else
        {
        c[i] -= 0;
        }
		}

    int back = c.length()-1;

    bool sprawdz = true;

    for (int i=0; i<c.length()/2 && sprawdz; i++)
        {
        if (c[i] != c[back--])
        {
            sprawdz = false;
        }
		}


string czy_prawdziwy;
if(sprawdz)
{
    czy_prawdziwy = "TAK";
}else
    {
        czy_prawdziwy = "NIE";
    }
    plik2<<"{\"string\":"<<c<<", \"palindrom\":\""<<czy_prawdziwy<<"}\n";
		a = "";
		b = "";
		c = "";
    }
	plik2<<"]";


}

palindromy::~palindromy()
{
    plik1.close();
    plik2.close();
}

int main() {
    palindromy t1;

    t1.czy_palindrom();
    return 0;
}
