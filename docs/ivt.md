# IVT
IVT stands for interrupt vector table, it is a table used to describe how an interrupt should behave, giving it an handler, etc.

## Structure
The IVT looks like this:

```c
struct IvtEntry
{
    uint8_t used : 1; // Whether it is used or not
    uint8_t dpl : 1; // Minimum privilege level in which the software interrupt can be executed
    uint32_t address;
} IvtEntry;

struct Ivt
{
    IvtEntry entries[256];
};
```

## Cpu behavior
The CPU reloads the ivt when its register, #IVT, is modified.
</br>
Note that on each interrupt, the CPU pushes PC, therefore to return from an interrupt you need to pop PC

# Hardware interrupts
Here are the hardware interrupts:
| Number   | Description                    |
| -------- | ------------------------------ |
| 0        | Invalid opcode (#UD)           |
| 1        | Page fault (#PF)               |
| 2        | General Protection fault (#GP) |
| 3        | Debug                          |
| 10 (0xA) | Timer interrupt                |
| 11 (0xB) | Keyboard                       |