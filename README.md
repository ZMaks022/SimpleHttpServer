# SimpleHttpServer
Simple http server for Linux with using C++. It's intending if server should respond on http request by calling a program. The programm will be have request as standart input. Standart output is a response, which server will send to client. 
It works with multithreading. For every request server create a new process and therefore this solution don't recommended for high loaded projects.

#### get started
1. Build application using CMake.
2. Build default backend application (or setting config files in `Configs/hosts.config`).
3. Run Server `./HttpServer` or `./HttpServer 0000`, where '0000' is a port.
4. If you see in brawser "It work", The server was started successfully.
