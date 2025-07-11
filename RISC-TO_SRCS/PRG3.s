0x00    addi    x1, x0, 93      | 05 D0 00 93
0x04    addi    x2, x0, 28      | 01 C0 01 13

0x08    nop                     | 00 00 00 00

0x0C    sub     x3, x1, x2      | 40 20 81 B3
0x10    sb      x3, 0(x0)       | 00 30 00 23
0x14    sub     x3, x2, x1      | 40 11 01 B3
0x18    sb      x3, 1(x0)       | 00 30 00 A3

0x1C    nop                     | 00 00 00 00

0x20    and     x3, x1, x2      | 00 20 F1 B3
0x24    sb      x3, 2(x0)       | 00 30 01 23

0x28    nop                     | 00 00 00 00

0x2C    andi    x3, x1, 34      | 02 20 F1 93
0x30    sb      x3, 3(x0)       | 00 30 01 A3

0x34    nop                     | 00 00 00 00

0x38    or      x3, x1, x2      | 00 20 E1 B3
0x3C    sb      x3, 4(x0)       | 00 30 02 23

0x40    nop                     | 00 00 00 00

0x44    ori     x3, x1, -21     | FE B0 E1 93
0x48    sb      x3, 5(x0)       | 00 30 02 A3

0x4C    nop                     | 00 00 00 00

0x50    slt     x3, x1, x2      | 00 20 A1 B3
0x54    sb      x3, 6(x0)       | 00 30 03 23
0x58    slt     x3, x2, x1      | 00 11 21 B3
0x5C    sb      x3, 7(x0)       | 00 30 03 A3
0x60    slt     x3, x1, x1      | 00 10 A1 B3
0x64    sb      x3, 8(x0)       | 00 30 04 23

0x68    nop                     | 00 00 00 00

0x6C    slti    x3, x1, 100     | 06 40 A1 93
0x70    sb      x3, 9(x0)       | 00 30 04 A3
0x74    slti    x3, x2, -21     | FE B1 21 93
0x78    sb      x3, 10(x0)      | 00 30 05 23

0x7C    nop                     | 00 00 00 00

0x80    nor     x3, x1, x2      | 80 20 81 B3
0x84    sb      x3, 11(x0)      | 00 30 05 A3

end:
0x88    beq     x0, x0, end     | 00 00 00 63