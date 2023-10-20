# Virtual network configuration
```
since we are playing with an iso image for virtual box we setup the virtual host only network to assign ip's for bot my kali and boot2root machine

so i wont have to do a Ping sweep  since i defined a range for 3 machines only so i already have the ip for the vulnerable server
```

# services and ports scanning
![](./Screen%20Shot%202023-10-19%20at%2011.11.49%20PM.png)
```
using nmap the network mapper we found  port 80 for http and 143 for https

the http webpage  has no interesting content and the https has no index page . lets try do discover paths into the webapplication ,
we will be bruteforcing the https web app.
```

# directory listing
![](./Screen%20Shot%202023-10-19%20at%2011.25.33%20PM.png)

# vulnerabilities assessement
```
exploring the /forum site someone posted the logs for server connection's seaarching it we found credentials that could help us connect somewhere
```
![](./Screen%20Shot%202023-10-19%20at%2011.30.00%20PM.png)
```
that password is acctually the password of lmezard into forum where we got the email "laurie@borntosec.net" and fortuannatly it is the same password used for the /webmail portal  funny xD
```
![](./Screen%20Shot%202023-10-19%20at%2011.33.14%20PM.png)
```
as we can see and email from ft_root giving us the credentials to connect  with the root account on the phpmyadmin panel and probably now we have an insight about everything : databases, users, and hashes of password's

we can try to figure out how we can crack those hashes since we already discovered the source code of the stack that is hosting the website (php plateform + mysql database) but i will chosse to look for a way to execute code on the server or upload malicious code
```
![](./Screen%20Shot%202023-10-19%20at%2011.35.29%20PM.png)

```
after hours of mannually searching for a path were i can upload php code i foud that  /forum/templates_c can help us upload php code and execute it on the server so lets use sql statement to do so 
```
![](./Screen%20Shot%202023-10-20%20at%205.22.12%20PM.png)
![](./Screen%20Shot%202023-10-20%20at%205.23.28%20PM.png)
```
and the command is successfully executed to approve the Remote Code Execution . so lets upload our reverseshell to the server and setup our netcat listenner

first we will use the python module to setup an http server on our host to upload the rev_shell.php to the server
```
![](./Screen%20Shot%202023-10-20%20at%206.20.42%20PM.png)
![](./Screen%20Shot%202023-10-20%20at%206.20.10%20PM.png)

```
now we just need to setup our netcat listenner and request our uploaded rev_shell.php file to trigger baack a connection from the vulnerable server to our listenner host
```
![](./Screen%20Shot%202023-10-20%20at%206.24.22%20PM.png)
![](./Screen%20Shot%202023-10-20%20at%206.27.22%20PM.png)

# privilege escalation
```
after getting our initial foothold on the vulnerable server as "www-data" user we found the credentials of the user lmezard that might be either for ftp or ssh since those are the service's running on the enumerated ports we did in the enumeration phase
accessing ftp with the credentials found we get  challenge called fun and a README file that says : Complete this little challenge and use the result as password for user "laurie" to login in ssh
fun is a tar archive which can be decompressed and result into an ft_fun directory full of .pcap files and they are not really pcap files and has nothing to do with wireshark , only normal text file that contains random piece of code and the number of the line of code 

easy hein , try it urself.
after assembling the pieces of the puzzle we got the password for the ssh user "laurie"

we then ssh using laurie credentials and find another challeng called bomb and a README file that says : Diffuse this bomb! When you have all the password use it as "thor" user with ssh.

first lets check the security over the program 
```
![](./Screen%20Shot%202023-10-20%20at%206.54.50%20PM.png)
```
no stack protection was enabled means we can write shellcode on stack and no address randomization was enabled also . the binary is pretty easy to reverse depending on its logic
lets use ghidra and not even think about going hardcore with gdb and plain text assembly since ghidra will disassemble the program for us and also decompile pieces of the program and make it more readable c program for us 
bomb is a binary that needs to be deffused by giving it the correct input each time it has 6 phases.
```
![](./Screen%20Shot%202023-10-20%20at%207.05.02%20PM.png)
```
after finishing the challenge we construct the password and gain access to the ssh user thor .

another challend is waiting for us , this time its called turtle and the README says : Finish this challenge and use the result as password for "zaz" user.

the challenge is about drawing the password using turle ptyhon module to get the drawn password . the word found is "SLASH"
well it might need you to hash it before using it as ssh password to connect, easy you think , try it urself.

after getting access to zaz user  we find another binary named exploit_me , lets check the protection around the binary itself
```
![](./Screen%20Shot%202023-10-20%20at%207.13.55%20PM.png)
```
no stack protection or address randomization is enabled , it might be easy to reverse it hein ! try it urself first

after decompiling the program into c , the program is using an array of 140 byte then takes our input and strcpy it into the array then prints it back , that not safe you know because nothing is controlling the length of our input well lets try to overflow it and see what we can do from there.

./exploit_me $(python -c "print('A' * 140 + '1234');")  : we made the program to segfault and also overrided the stored address in ret. aha we found our offset why not use 'return to libc'  technique to exploit the bufferoverflow and make a call to system() and give it "/bin/sh" as parameter  

well for this to happen we will have to get the respective address's for system , exit , and "/bin/sh" during the runtime of the program to craft the following payload

payload = A*140 + address of system() + address of exit() + address of "/bin/sh"
```
![](./Screen%20Shot%202023-10-20%20at%207.29.22%20PM.png)

