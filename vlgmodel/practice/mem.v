`timescale 1ns/1ns

module mem (/*AUTOARG*/
  // Outputs
  rdata,
  // Inputs
  addr, wdata, wex, rex
  );
  parameter aw = 8, dw = 16;
  parameter WDELAY = 2, RDELAY = 3;

  input [aw-1:0]        addr;
  input [dw-1:0]        wdata;
  input                 wex, rex;
  output [dw-1:0]       rdata;
  reg [dw-1:0]          mem[0:(1<<aw)-1];
  
  always @(wex or wdata or addr) begin
    if ( ! wex) begin
      // mem の addr 番目の場所に
      // wdata を格納する。その時、WDELAY の遅延をつける
    end
  end

  assign #RDELAY rdata[dw-1:0] = !rex? mem[addr[aw-1:0]]: {dw{1'bz}};
endmodule // mem
