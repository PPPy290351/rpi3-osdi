.section ".text"
# define global and will bind symbol with "GLOBAL"
# Symbol table '.symtab' contains 5 entries:
#   Num:    Value          Size Type    Bind   Vis      Ndx Name
#     0: 0000000000000000     0 NOTYPE  LOCAL  DEFAULT  UND
#     1: 0000000000080000     0 SECTION LOCAL  DEFAULT    1
#     2: 0000000000000000     0 FILE    LOCAL  DEFAULT  ABS start.o
#     3: 0000000000080000     0 NOTYPE  LOCAL  DEFAULT    1 $x
#   > 4: 0000000000080000     0 NOTYPE  GLOBAL DEFAULT    1 _start
.global _start

_start:
    wfe
    b _start
