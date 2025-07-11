0x00    lb      x1, 0(x0)       | 00 00 00 83
0x04    lb      x2, 1(x0)       | 00 10 01 03
0x08    lb      x3, 2(x0)       | 00 20 01 83

0x0C    add     x4, x1, x2      | 00 20 82 33
0x10    beq     x4, x3, else    | 00 32 06 63
0x14    sb      x4, 0(x0)       | 00 40 00 23
0x18    beq     x0, x0, end     | 00 00 06 63

else:
0x1C    add     x1, x1, x1      | 00 10 80 B3
0x20    sb      x1, 0(x0)       | 00 10 00 23

end:
0x24    beq     x0, x0, end     | 00 00 00 63