# Device Bus
The device bus is the bus where every device is connected, similar to pci

## Structure
To get the address of the bus, one needs to read from the io port #1.
<br />
The bus has the following structure (pseudocode):
```c
struct BusDevice
{
    int type;
    uint32_t addr; // Command buffer, 128 bytes
    int size; // Command buffer size
};

struct Bus
{
    BusDevice devices[32];
    int device_count;
};
```

So, to get the disk address, you could do this (again pseudocode):

```c
Bus *bus = (Bus*)io_read(1);

for(int i = 0; i < bus->device_count; i++)
{
    if(bus->devices[i].type == DISK)
    {
        disk_addr = bus->devices[i].addr;
        break;
    }
}
```

## Device commands
Device commands are sent to the device through its buffer.
Device commands can be, for example, a disk read.