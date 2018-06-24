ENTRY(_Reset)
SECTIONS
{
  . = 0x0;
  .text : {
    boot.o (INTERRUPT_VECTOR)
    *(.text)
  }
  .data : { *(.data) }
  .bss : { *(.bss COMMON) }
  . = ALIGN(8);
  stack_base = .;
  . = . + 0x1000;
  . = . + 0x1000;
  PROVIDE (end = .);
}
