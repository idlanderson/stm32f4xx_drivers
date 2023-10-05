ENTRY(Reset_Handler)

MEMORY
{
    FLASH(rx):ORIGIN = 0x08000000,LENGTH = 1024K
    SRAM(rwx):ORIGIN = 0x20000000,LENGTH = 128K
}

SECTIONS
{
    /* Location counter (.) always tracks VMA */
    .text :
    {
        *(.isr_vector)
        *(.text)        /* .text of all input files */
        *(.text.*)      /* Merge all sub-sections of .text. */
        *(.init)
        *(.fini)
        *(.rodata)
        *(.rodata.*)
        . = ALIGN(4);
        _etext = .;     /* Symbol for address of the end of text section. */
    }> FLASH            /* VMA = LMA in this case */

    __exidx_start = .;
    .exidx :
    {
        *(.exidx* .gnu.linkonce.exidx*)
    } >FLASH
    __exidx_end = .;

    _la_data = LOADADDR(.data);

    .data :
    {
        _sdata = .;     /* Start of .data section = start of SRAM (VMA) */
        *(.data)
        *(.data.*)
        . = ALIGN(4);
        _edata = .;     /* End of .data section. */
    }> SRAM AT> FLASH   /* > VMA AT> LMA, where VMA = virtual memory address, LMA = load memory address */

    .bss :
    {
        _sbss = .;      /* Start of .bss section. */
        __bss_start__ = _sbss;
        *(.bss)
        *(.bss.*)
        *(COMMON)
        . = ALIGN(4);
        _ebss = .;      /* End of .bss section. */
        __bss_end__ = _ebss;
        . = ALIGN(4);
        end = .;
        __end__ = .;
    }> SRAM
}