from flask import Flask, redirect, url_for, request, jsonify
import socket

app = Flask(__name__)
HOST = "192.168.220.81"
PORT = 9000

@app.route('/control/<ip>/<direction>')
def control(ip, direction):
    if direction == "left":
        message = "left"
    elif direction == "right":
        message = "right"
    else:
        return jsonify(hello='error')

    byte_message = bytes(message, "utf-8")
    opened_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    opened_socket.sendto(byte_message, (ip, PORT))
    opened_socket.close()
    return jsonify(hello='world')


if __name__ == '__main__':
    app.run(debug = True)