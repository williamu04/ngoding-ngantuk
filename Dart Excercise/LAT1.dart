import 'dart:io';

segitiga1(int panjang) {
  String hasil = '';
  for (int i = 0; i < panjang; i++) {
    for (int j = 0; j <= i; j++) {
      hasil += '* ';
    }
    hasil += '\n';
  }
  print(hasil);
}

void main() {
  int n = int.parse(stdin.readLineSync()!);
  segitiga1(n);
}
