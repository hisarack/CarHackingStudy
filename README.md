
* Setup and install virtual CAN interface

```
sudo apt-get install libsdl2-dev libsdl2-image-dev can-utils  
sudo modprobe can
sudo modprobe vcan
sudo ip link add dev vcan0 type vcan
sudo ip link set up vcan0
```

* Prepare executable 

```
sudo apt-get install nasm
gcc -o temp_shellcode temp_shellcode.c 
nasm -f elf64 -o temp_shell2.o temp_shell.S
```
