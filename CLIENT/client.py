import socket

HOST = "192.168.220.81"
PORT = 9000

byte_message = bytes("Hello, World!", "utf-8")
opened_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
opened_socket.sendto(byte_message, (HOST, PORT))

opened_socket.close()