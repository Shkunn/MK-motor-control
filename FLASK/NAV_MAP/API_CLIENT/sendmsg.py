import socket
import time

ip   = "172.21.72.167"
PORT = 8080

msg = 0
cc = bytes([msg])

with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as opened_socket:
    while True:
        opened_socket.setblocking(0)
        cc = bytes([msg])
        msg_string = f'{cc}'
        print(f"Sending {bytes(cc)} to {ip}:{PORT}")
        opened_socket.sendto(bytes(cc), (ip, PORT))
        time.sleep(0.5)
        msg += 1
        if msg == 254:
            msg = 0