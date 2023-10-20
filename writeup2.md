# 
```
we will be following the same steps we did in the writeup1 until we get access to the server as  user "laurie" through ssh.

the version of the kernel of the OS is vulnerable so this time we will be exploiting a kernel version vulnerability to escalate our privileges to "root" directly
```

# Dirty Cow
```
A race condition was found in the way the Linux kernel's memory subsystem handled the copy-on-write (COW) breakage of private read-only memory mappings. An unprivileged local user could use this flaw to gain write access to otherwise read-only memory mappings and thus increase their privileges on the system.

searching in the internet for a dirty cow exploit i used the c program found in the scripts section that allows me to ovveride the root user and define a custome password for it so lets compile our c programe and enjoy the root access

gcc dirty.c -pthread -o dirty -lcrypt

./dirty <password for the new root user>
```
![](./Screen%20Shot%202023-10-20%20at%204.48.18%20PM.png)
