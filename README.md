# MINITALK

## PROJECT INFORMATIONS
• You must create a communication program in the form of a client and server.
• The server must be launched first, and after being launched it must display its PID.
• The client will take as parameters:
◦ The server PID.
◦ The string that should be sent.
• The client must communicate the string passed as a parameter to the server. Once
the string has been received, the server must display it.
• Communication between your programs should ONLY be done using UNIX signals.
• The server must be able to display the string pretty quickly. By quickly we mean
that if you think it is too long, then it is probably too long (hint: 1 second for 100
characters is COLOSSAL)
• Your server should be able to receive strings from several clients in a row, without
needing to be restarted.
• You can only use the two signals SIGUSR1 and SIGUSR2.
# 42cursus - minitalk

![](https://github.com/obouadel/42-minitalk/workflows/norminette/badge.svg)
![](https://github.com/obouadel/42-minitalk/workflows/build/badge.svg)
![](https://img.shields.io/tokei/lines/github/obouadel/42-minitalk?style=plastic?color=blue)

### About

The purpose of this project is to code a small data exchange program using *UNIX signals*.

### Mandatory

- Produce `server` & `client` executables
- `client` must communicate a string passed as a parameter to `server` *(referenced by its process ID)* which then displays it
- Use `SIGUSR1` & `SIGUSR2` signals **ONLY**

### Bonus

- Add reception acknowledgement system
- Support Unicode characters

### Allowed Functions

- [`malloc`](https://man7.org/linux/man-pages/man3/free.3.html)
- [`free`](https://man7.org/linux/man-pages/man3/free.3.html)
- [`write`](https://man7.org/linux/man-pages/man2/write.2.html)
- [`getpid`](https://man7.org/linux/man-pages/man2/getpid.2.html)
- [`signal`](https://man7.org/linux/man-pages/man2/signal.2.html)
- [`sigemptyset & sigaddset`](https://man7.org/linux/man-pages/man3/sigsetops.3.html)
- [`sigaction`](https://man7.org/linux/man-pages/man2/sigaction.2.html)
- [`pause`](https://man7.org/linux/man-pages/man2/pause.2.html)
- [`kill`](https://man7.org/linux/man-pages/man2/kill.2.html)
- [`sleep`](https://man7.org/linux/man-pages/man3/sleep.3.html)
- [`usleep`](https://man7.org/linux/man-pages/man3/usleep.3.html)
- [`exit`](https://man7.org/linux/man-pages/man3/exit.3.html)

## Compilation

1. Clone repo including [`libft`](../../../42-libft) submodule via `git clone --recursive https://github.com/hanshazairi/42-minitalk.git`.
2. Compile files into `server` & `client` executables via `make -C 42-minitalk`.

## Demo

[![DemoMinitalk](https://i.imgur.com/vu1RyRc.gif)](i.imgur.com/vu1RyRc.gif)
