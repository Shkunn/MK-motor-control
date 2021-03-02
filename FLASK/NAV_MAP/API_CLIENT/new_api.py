from flask import Flask, redirect, url_for, request, jsonify
from flask_cors import CORS

import socket
import threading

IP   = "172.21.72.103"
PORT = 8080
IP_local    = "172.21.72.145"
PORT2 = 8081

app = Flask(__name__)
CORS(app)

listeningAddress = (IP_local, PORT2)
datagramSocket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
datagramSocket.bind(listeningAddress)

coord = ""
lock = threading.Lock()

def read_coord():
    global coord
    while True:
        localization, sourceAddress = datagramSocket.recvfrom(128)
        with lock: 
            coord = localization.decode()
            print("coord : " + str(coord))

@app.route('/navigation/<coordinates>')
def navigation(coordinates):
    byte_message = coordinates.encode()
    with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as opened_socket:
        opened_socket.sendto(byte_message, (IP, PORT))
    return jsonify(hello='world')

# Create a datagram based server socket that uses IPv4 addressing scheme
@app.route('/position_update/')
def position_update():
    global coord
    print(coord)
    with lock: return jsonify(coord)


if __name__ == '__main__':
    thread = threading.Thread(target=read_coord)
    thread.start()

    
    app.run(debug=True, threaded=True, use_reloader = False)
    thread.join()

    