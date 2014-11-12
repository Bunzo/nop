`timescale 1ns/1ns

module tb;
  parameter STEP = 1000;
  
  /*AUTOINPUT*/
  // Beginning of automatic regs (from unused autoinst regs)
  reg                 clk;                    // To ia of ia.v
  reg                 rex;                    // To mem of mem.v
  reg                 rst;                    // To ia of ia.v
  reg [15:0]          wdata;                  // To mem of mem.v
  reg                 wex;                    // To mem of mem.v
  // End of automatics
  /*AUTOWIRE*/
  // Beginning of automatic wires (from unused autoinst wires)
  wire [15:0]         rdata;                  // From mem of mem.v
  // End of automatics

  always
    #(STEP/2) clk = ~clk;

  initial begin
    init;
    #(STEP*10);
    meminit;

    #(STEP*512);
    $finish(2);
  end

  mem #(.aw(8), .dw(16)) mem (/*AUTOINST*/
           // Wires
           .rdata                       (rdata[dw-1:0]),
           // Regs
           .addr                        (addr[aw-1:0]),
           .wdata                       (wdata[dw-1:0]),
           .wex                         (wex),
           .rex                         (rex));

  ia #(.aw(8)) ia (/*AUTOINST*/
         // Wires
         .addr                          (addr[aw-1:0]),
         // Regs
         .clk                           (clk),
         .rst                           (rst));

  task init;
    begin
      clk = 1'b0;
      rst = 1'b1;
      #(STEP*10);
      rst = 1'b0;
      rex = 1'b1;
      wex = 1'b1;
      wdata = {dw{1'b0}};
    end
  endtask

  task meminit;
    integer i;
    begin
      for (i=0; i<(1<<aw)-1; i=i+1) begin
        #(STEP);
        wex = 1'b0;
        rdate[dw-1:0] = i;
      end
    end
  endtask
  
endmodule
