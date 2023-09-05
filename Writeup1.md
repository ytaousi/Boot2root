### sudo nmap -PU 10.0.2.15/24
```
Nmap scan report for 10.0.2.4

PORT    STATE SERVICE

21/tcp  open  ftp
22/tcp  open  ssh
80/tcp  open  http
143/tcp open  imap
443/tcp open  https
993/tcp open  imaps

MAC Address: 08:00:27:47:AC:48 (Oracle VirtualBox virtual NIC)
```


### nmap -sC -sV -Pn -p- 10.0.2.4
```
Nmap scan report for 10.0.2.4

PORT    STATE SERVICE  VERSION

21/tcp  open  ftp      vsftpd 2.0.8 or later
|_ftp-anon: got code 500 "OOPS: vsftpd: refusing to run with writable root inside chroot()".

22/tcp  open  ssh      OpenSSH 5.9p1 Debian 5ubuntu1.7 (Ubuntu Linux; protocol 2.0)
| ssh-hostkey: 
|   1024 07:bf:02:20:f0:8a:c8:48:1e:fc:41:ae:a4:46:fa:25 (DSA)
|   2048 26:dd:80:a3:df:c4:4b:53:1e:53:42:46:ef:6e:30:b2 (RSA)
|_  256 cf:c3:8c:31:d7:47:7c:84:e2:d2:16:31:b2:8e:63:a7 (ECDSA)

80/tcp  open  http     Apache httpd 2.2.22 ((Ubuntu))
|_http-title: Hack me if you can
|_http-server-header: Apache/2.2.22 (Ubuntu)

143/tcp open  imap     Dovecot imapd
| ssl-cert: Subject: commonName=localhost/organizationName=Dovecot mail server
| Not valid before: 2015-10-08T20:57:30
|_Not valid after:  2025-10-07T20:57:30
|_ssl-date: 2023-09-04T22:43:40+00:00; +1s from scanner time.
|_imap-capabilities: LITERAL+ LOGINDISABLEDA0001 have Pre-login post-login capabilities SASL-IR LOGIN-REFERRALS STARTTLS OK listed IDLE more ID IMAP4rev1 ENABLE

443/tcp open  ssl/http Apache httpd 2.2.22
|_ssl-date: 2023-09-04T22:43:40+00:00; +1s from scanner time.
|_http-server-header: Apache/2.2.22 (Ubuntu)
| ssl-cert: Subject: commonName=BornToSec
| Not valid before: 2015-10-08T00:19:46
|_Not valid after:  2025-10-05T00:19:46
|_http-title: 404 Not Found

993/tcp open  ssl/imap Dovecot imapd
|_ssl-date: 2023-09-04T22:43:40+00:00; +1s from scanner time.
| ssl-cert: Subject: commonName=localhost/organizationName=Dovecot mail server
| Not valid before: 2015-10-08T20:57:30
|_Not valid after:  2025-10-07T20:57:30
|_imap-capabilities: LITERAL+ capabilities AUTH=PLAINA0001 post-login Pre-login SASL-IR LOGIN-REFERRALS have OK listed IDLE more ID IMAP4rev1 ENABLE

Service Info: Host: 127.0.1.1; OS: Linux; CPE: cpe:/o:linux:linux_kernel
```


Dovecot mail server, OU = localhost, CN = localhost, emailAddress = root@mail.borntosec.net
