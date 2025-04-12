module timer {
    input clk_200mhz,
    input reset,
    output reg [31:0] sec,
    output reg [15:0] msec,
    output reg [15:0] usec
}

reg clk_counter [7:0];

always@ (posedge clk_200mhz or posedge reset) begin
    if (reset) begin
        clk_counter <= 0;
        sec <= 0;
        msec <= 0;
        usec <= 0;
    end else begin
        if (clk_counter == 199) begin 
            usec <= usec + 1;
            clk_counter <= 0;
            if (usec == 999) begin
                msec <= msec + 1;
                usec <= 0;
                if (msec == 999) begin
                    sec <= sec + 1;
                    msec <= 0;
                end
            end
        end else begin
            clk_counter <= clk_counter + 1;
        end
    end
end