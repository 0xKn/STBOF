# STBOF

Just a proof of concept to automate the exploitation of binaries vulnerable to buffer overflow that receive an argument.

[*]The vulnerable binary and the exploit have to be located under the same directory.


## Exploit

### Installation:

**[*]** This exploit requires Python 3.7 or higher

GDB:
``` 
sudo apt-get install gdb 
```

pwntools:
``` 
apt-get install python3 python3-pip python3-dev git libssl-dev libffi-dev build-essential
python3 -m pip install --upgrade pip
python3 -m pip install --upgrade pwntools
```
(https://docs.pwntools.com/en/stable/install.html)


### Needs

1.- Disable ASLR protection - Sudo

``` 
echo 0 > /proc/sys/kernel/randomize_va_space
```

2.- Compile vulnerable program

  2.1- To compile m32
``` 
sudo apt-get install gcc-multilib
```
  2.2.- Compilation:
``` 
gcc -fno-stack-protector -z execstack -m32 -o [VULNERABLE_BINARY] [VULNERABLE].c
```

3.- Set-UID
``` 
sudo chown root [VULNERABLE_BINARY]
sudo chmod 4755 [VULNERABLE_BINARY]
```
  3.1.- Avoid dash countermeasure if /bin/sh is a symbolic link pointing to /bin/dash:
``` 
sudo ln -sf /bin/zsh /bin/sh
```
  To avoid problems after execution of the exploit, leave the symbolic link as it was initially
``` 
sudo ln -sf /bin/dash /bin/sh
``` 

### Usage:

```
$ python3 exploit.py --file vulnprogram --port 4444
```
* ```--file``` -- Binary File
* ```--port``` -- Local Port

Do not forget to start your listener:

```
nc -lvnp 4444
```

## PoC

[![asciicast](https://asciinema.org/a/YiPxwqeRJwCF3VMeu1Du1ArmM.svg)](https://asciinema.org/a/YiPxwqeRJwCF3VMeu1Du1ArmM)
