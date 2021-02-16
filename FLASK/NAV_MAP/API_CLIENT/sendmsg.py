import socket
import time

ip   = "172.21.72.167"
PORT = 8080

msg = b'lab'

with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as opened_socket:
    while True:
        print(f"Sending {msg} to {ip}:{PORT}")
        opened_socket.sendto(msg, (ip, PORT))
        time.sleep(1)