module ia (/*AUTOARG*/
  // Outputs
  addr,
  // Inputs
  clk, rst
  );
  parameter aw = 8;
  
  input                 clk, rst;
  output [aw-1:0]       addr;
  reg [aw-1:0]          pc;

  always @(posedge clk or negedge rst) begin
    if ( ! rst) begin
      // Initialize pc[aw-1:0]
    end else begin
      // 
      // pc += 4
    end
  end

endmodule // ia
