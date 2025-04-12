#include <ap_int.h>


void timer(
  ap_uint<1> &clk_200mhz,
  ap_uint<1> &reset,
  ap_uint<32> &sec,
  ap_uint<16> &ms,
  ap_uint<16> &us
) {
  #pragma HLS PIPELINE II = 1

  static ap_uint<8> clk_counter = 0;
  static ap_uint<32> sec_reg = 0;
  static ap_uint<16> ms_reg = 0;
  static ap_uint<16> us_reg = 0;
}