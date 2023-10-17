import 'dart:io';

void main() {
  int input_bilangan_bulat_biasanya_didefinisikan_sebagai_n =
      int.parse(stdin.readLineSync() ?? '0');

  if (input_bilangan_bulat_biasanya_didefinisikan_sebagai_n % 2 == 0) {
    input_bilangan_bulat_biasanya_didefinisikan_sebagai_n =
        input_bilangan_bulat_biasanya_didefinisikan_sebagai_n - 1;
  }

  for (int iterasi_for_loop_biasanya_didefinisikan_sebagai_i_itupun_tipe_data_int =
          1;
      iterasi_for_loop_biasanya_didefinisikan_sebagai_i_itupun_tipe_data_int <=
          input_bilangan_bulat_biasanya_didefinisikan_sebagai_n;
      iterasi_for_loop_biasanya_didefinisikan_sebagai_i_itupun_tipe_data_int +=
          2) {
    for (int iterasi_yang_biasanya_digunakan_dalam_loop_jadi_membuat_stacked_loop_bisa_pakai_j_atau_k_karena_akan_diiterasi_setiap_satu_kali_i =
            0;
        iterasi_yang_biasanya_digunakan_dalam_loop_jadi_membuat_stacked_loop_bisa_pakai_j_atau_k_karena_akan_diiterasi_setiap_satu_kali_i <
            (input_bilangan_bulat_biasanya_didefinisikan_sebagai_n -
                    iterasi_for_loop_biasanya_didefinisikan_sebagai_i_itupun_tipe_data_int) ~/
                2;
        iterasi_yang_biasanya_digunakan_dalam_loop_jadi_membuat_stacked_loop_bisa_pakai_j_atau_k_karena_akan_diiterasi_setiap_satu_kali_i++) {
      stdout.write('  ');
    }
    for (int iterasi_yang_biasanya_digunakan_dalam_loop_jadi_membuat_stacked_loop_bisa_pakai_j_atau_k_karena_akan_diiterasi_setiap_satu_kali_i =
            0;
        iterasi_yang_biasanya_digunakan_dalam_loop_jadi_membuat_stacked_loop_bisa_pakai_j_atau_k_karena_akan_diiterasi_setiap_satu_kali_i <
            iterasi_for_loop_biasanya_didefinisikan_sebagai_i_itupun_tipe_data_int;
        iterasi_yang_biasanya_digunakan_dalam_loop_jadi_membuat_stacked_loop_bisa_pakai_j_atau_k_karena_akan_diiterasi_setiap_satu_kali_i++) {
      stdout.write('* ');
    }
    stdout.writeln();
  }

  for (int iterasi_for_loop_biasanya_didefinisikan_sebagai_i_itupun_tipe_data_int =
          input_bilangan_bulat_biasanya_didefinisikan_sebagai_n - 2;
      iterasi_for_loop_biasanya_didefinisikan_sebagai_i_itupun_tipe_data_int >=
          1;
      iterasi_for_loop_biasanya_didefinisikan_sebagai_i_itupun_tipe_data_int -=
          2) {
    for (int iterasi_yang_biasanya_digunakan_dalam_loop_jadi_membuat_stacked_loop_bisa_pakai_j_atau_k_karena_akan_diiterasi_setiap_satu_kali_i =
            0;
        iterasi_yang_biasanya_digunakan_dalam_loop_jadi_membuat_stacked_loop_bisa_pakai_j_atau_k_karena_akan_diiterasi_setiap_satu_kali_i <
            (input_bilangan_bulat_biasanya_didefinisikan_sebagai_n -
                    iterasi_for_loop_biasanya_didefinisikan_sebagai_i_itupun_tipe_data_int) ~/
                2;
        iterasi_yang_biasanya_digunakan_dalam_loop_jadi_membuat_stacked_loop_bisa_pakai_j_atau_k_karena_akan_diiterasi_setiap_satu_kali_i++) {
      stdout.write('  ');
    }
    for (int iterasi_yang_biasanya_digunakan_dalam_loop_jadi_membuat_stacked_loop_bisa_pakai_j_atau_k_karena_akan_diiterasi_setiap_satu_kali_i =
            0;
        iterasi_yang_biasanya_digunakan_dalam_loop_jadi_membuat_stacked_loop_bisa_pakai_j_atau_k_karena_akan_diiterasi_setiap_satu_kali_i <
            iterasi_for_loop_biasanya_didefinisikan_sebagai_i_itupun_tipe_data_int;
        iterasi_yang_biasanya_digunakan_dalam_loop_jadi_membuat_stacked_loop_bisa_pakai_j_atau_k_karena_akan_diiterasi_setiap_satu_kali_i++) {
      stdout.write('* ');
    }
    stdout.writeln();
  }
}
