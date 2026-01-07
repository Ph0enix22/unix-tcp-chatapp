# Simple Chat Application using TCP/IP Sockets in C

A simple text-based chat application implemented in C using TCP/IP sockets on Ubuntu/WSL. This project demonstrates real-time client-server communication over a reliable TCP connection.

---

## Features

- Client-server architecture (one server, one client)
- Uses TCP sockets (`AF_INET`, `SOCK_STREAM`)
- Runs on Ubuntu / WSL (Unix environment on Windows)
- Real-time two-way text messaging between two terminals
- Minimal, easy-to-read C code suitable for learning socket programming

---

## Architecture Overview

### Server
- Creates a TCP socket
- Binds to port `8080`
- Listens for incoming connections
- Accepts one client
- Receives messages from the client and sends replies

### Client
- Creates a TCP socket
- Connects to `127.0.0.1:8080`
- Sends user-typed messages to the server
- Receives and displays server replies

Under the hood, the OS uses TCP to ensure that all bytes sent by one side are delivered reliably and in order to the other.

---

## Files

- `server.c` – Server-side implementation
- `client.c` – Client-side implementation

---

## How to Compile & Run

Make sure you have `gcc` installed and you are inside the project directory.

### 1. Compile

```bash
gcc server.c -o server
gcc client.c -o client
```

This will create two executables: `server` and `client`.

### 2. Run the Server and Client

Open two Ubuntu terminals.

**Terminal 1** – Start the server:

```bash
cd /path/to/project
./server
```

Expected output:

```
Server waiting on port 8080...
```

**Terminal 2** – Start the client:

```bash
cd /path/to/project
./client
```

Expected output:

```
Connected to server.
You: 
```

### 3. Chat Example

**Client (Terminal 2):**

```
You: Firewall is down. I'm in.
```

**Server (Terminal 1):**

```
Client: Firewall is down. I'm in.
You: Copy. Accessing mainframe now.
```

**Client:**

```
Server: Copy. Accessing mainframe now.
You: Data stream looks clean.
```

**Server:**

```
Client: Data stream looks clean.
You: Good. Download and disconnect.
```

Press `Ctrl + C` in each terminal to stop the programs.

---

## Key Concepts Used

- **Socket** – Endpoint for communication over the network
- **TCP (SOCK_STREAM)** – Reliable, connection-oriented protocol
- `socket()` – Create a new socket descriptor
- `bind()` – Attach the server socket to IP/port (here, port `8080`)
- `listen()` – Put the server socket into listening mode
- `accept()` – Accept an incoming client connection
- `connect()` – Client initiates a TCP connection to the server
- `read()` / `write()` – Receive/send bytes through the socket
- `127.0.0.1` – Localhost (server and client on the same machine)
- **WSL (Windows Subsystem for Linux)** – Used to run Ubuntu on a Windows laptop

---

## Possible Extensions

Some ideas for future improvements:

- Support multiple clients using `select()` or threads
- Add usernames and timestamps to messages
- Implement encryption (e.g., TLS) for secure chat
- Store chat history in a file or database
- Build a simple GUI or web-based front end

---

## Requirements

- Ubuntu 22.04 LTS (or any Linux distribution)
- WSL2 (if running on Windows)
- GCC compiler

---

## Acknowledgements

Developed as part of the UNIX lab mini-project. Tested on Ubuntu 22.04 LTS (WSL2) with `gcc`.

*P.S. – If you're reading this, thanks for checking out my project! ☕*

---

## License

This project is open source and available for educational purposes.
