SECTIONS
{
    . = 0x80000;
    .text : { *(.text) }
    .data : { *(.data) }
    .bss : {
        _bstart = ALIGN(0x10);
        *(.bss);
        _bend = ALIGN(0x10);
    }
}
__bss_size = (_bend - _bstart)>>3;