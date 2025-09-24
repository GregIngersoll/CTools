CC = gcc

BINARIES = unix_domain_sockets_client unix_domain_sockets_client
UDS_CLIENT_SOURCES = socket_utilities.c unix_domain_sockets_client.c
UDS_SERVER_SOURCES = socket_utilities.c unix_domain_sockets_server.c
UDS_CLIENT_OBJECTS = socket_utilities.o unix_domain_sockets_client.o
UDS_SERVER_OBJECTS = socket_utilities.o unix_domain_sockets_server.o

unix_domain_sockets_client: socket_utilities.o unix_domain_sockets_client.o

socket_utilities.o: socket_utilities.c

socket_utilities.c : socket_utilities.h

unix_domain_sockets_client.o : unix_domain_sockets_client.c

unix_domain_sockets_client.c : socket_utilities.h

clean:
	rm $(BINARIES) $(UDS_CLIENT_OBJECTS) $(UDS_SERVER_OBJECTS)
