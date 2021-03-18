from flask import Flask, redirect, url_for, request, jsonify
import socket
from flask_cors import CORS

# IP   = "172.21.72.149";
IP   = "192.168.132.58";
PORT = 8081

app = Flask(__name__)
CORS(app)

@app.route('/navigation/<coordinates>')
def navigation(coordinates):
    byte_message = coordinates.encode()
    with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as opened_socket:
        opened_socket.sendto(byte_message, (IP, PORT))
    return jsonify(hello='world')

if __name__ == '__main__':
    app.run(debug=True)