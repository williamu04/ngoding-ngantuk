#include <iostream>
#include <string>

using namespace std;

class Motor {
    public:
      int roda = 2;
      void klakson(){
        cout << "Tut tut!\n";
      }
      int getRoda(){
        return roda;
      }
};

class Yamaha: protected Motor {
    public:
      string model = "R15";
      void sound(){
        klakson();
      }
      void roda(){
        cout << roda;
      }
};

class Honda: protected Motor {
    public:
      string model = "CBR15";
      void klakson(){
        cout << "Toletot\n";
      }
      void rode(){
      cout << roda;
      }
};

int main(){
    Yamaha motor1;
    cout << motor1.model << " bunyinya ";
    motor1.sound();
    cout << "jumlah roda: ";
    motor1.roda();

    Honda motor2;
    cout << motor2.model << " bunyinya ";
    motor2.klakson();
    cout << "jumlah roda: "; 
    motor2.rode();

    return 0;
}