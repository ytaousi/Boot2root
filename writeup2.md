# 
```
we will be following the same steps we did in the writeup1 until we get access to the server as  user "laurie" through ssh, then this time we will be exploiting a kernel version vulnerability to escalate our privileges to "root" directly
```

# Dirty Cow
```
A race condition was found in the way the Linux kernel's memory subsystem handled the copy-on-write (COW) breakage of private read-only memory mappings. An unprivileged local user could use this flaw to gain write access to otherwise read-only memory mappings and thus increase their privileges on the system.


```
