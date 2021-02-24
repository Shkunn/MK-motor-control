import socket

# Define the IP address and the Port Number
ip    = "172.21.72.170"
port  = 8080

listeningAddress = (ip, port)

# Create a datagram based server socket that uses IPv4 addressing scheme
datagramSocket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
datagramSocket.bind(listeningAddress)

while(True):
    localization, sourceAddress = datagramSocket.recvfrom(128)
    print("Go to %s "%(localization.decode()))