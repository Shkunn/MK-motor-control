from flask import Flask, redirect, url_for, request, jsonify
import socket
from flask_cors import CORS

IP   = "172.21.72.103"
PORT = 8081

app = Flask(__name__)
CORS(app)

@app.route('/navigation/<coordinates>')
def navigation(coordinates):
    byte_message = coordinates.encode()
    with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as opened_socket:
        opened_socket.sendto(byte_message, (IP, PORT))
    return jsonify(hello='world')

IP_local    = "172.21.72.145"
PORT2 = 8081

listeningAddress = (IP_local, PORT2)
datagramSocket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
datagramSocket.bind(listeningAddress)
# Create a datagram based server socket that uses IPv4 addressing scheme



@app.route('/position_update/')
def position_update():
    # print("ted")	
    # localization, sourceAddress = datagramSocket.recvfrom(128)
    # print("Go to %s "%(localization.decode()))
    # return jsonify(hello=localization.decode())
    return jsonify(hello='world')

if __name__ == '__main__':
    app.run(debug=True, threaded=True)