#include <iostream>
#include <string>

using namespace std;

class Buah {
    public:
      string nama;
      string warna;

      void setParam(string a, string b){
        nama = a;
        warna = b;
      }
    
    protected:
      void pesan1(){
        cout << "Halo selamat dtg" << endl;
      }
};

class Apel: public Buah {
    public:
      void pesan2(){
        pesan1();
        cout << "Nama buah: "<< nama << endl << "Warnanya: "<< warna;
      }
};

class Apel_Merah: public Apel{
    public:
      int harga = 2000;
};

class Apel_Hijau: public Apel{
    public:
      int harga = 1500;
};

int main(){
    Apel_Hijau pel;
    cout << "jenis: "<< 
    return 0;
}