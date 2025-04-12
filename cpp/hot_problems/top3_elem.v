module top3_finder {
    input clk,
    input reset,
    input [31:0] data_in,
    output reg [31:0] result_0,
    output reg [31:0] result_1,
    output reg [31:0] result_2
};

always@(posedge clk or posedge reset) begin
    if (reset) begin
        result_0 <= 32'b80000000;
        result_1 <= 32'b80000000;
        result_2 <= 32'b80000000;
    end else begin
        if (data_in > result_2) begin
            result_0 <= result_1;
            result_1 <= result_2;
            result_2 <= data_in;
        end else if (data_in > result_1) begin
            result_0 <= result_1;
            result_1 <= data_in;
        end else if (data_in > result_0) begin
            result_0 <= data_in;
        end
    end
end

endmodule