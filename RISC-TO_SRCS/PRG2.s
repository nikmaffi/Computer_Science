start:
0x00    addi    x1, x0, 1           | 00 10 00 93
0x04    addi    x2, x0, 2           | 00 20 01 13
0x08    addi    x3, x0, 3           | 00 30 01 93
0x0C    addi    x4, x0, 4           | 00 40 02 13

0x10    sb      x1, 0(x0)           | 00 10 00 23
0x14    sb      x2, 1(x0)           | 00 20 00 A3
0x18    sb      x3, 2(x0)           | 00 30 01 23
0x1C    sb      x4, 3(x0)           | 00 40 01 A3

0x20    add     x1, x0, x0          | 00 00 00 B3
0x24    add     x5, x0, x0          | 00 00 02 B3

loop:
0x28    lb      x2, 0(x1)           | 00 00 81 03
0x2C    add     x5, x5, x2          | 00 22 82 B3
0x30    addi    x1, x1, 1           | 00 10 80 93
0x34    beq     x1, x4, end_loop    | 00 40 84 63
0x38    beq     x0, x0, loop        | FE 00 08 E3

end_loop:
0x3C    sb      x5, 5(x0)           | 00 50 02 A3

end:
0x40    beq     x0, x0, start       | FC 00 00 E3