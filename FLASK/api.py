from flask import Flask, redirect, url_for, request, jsonify
import socket

app = Flask(__name__)
HOST = "192.168.220.81"
PORT = 9000

@app.route('/control/<ip>/<direction>')
def control(ip, direction):
    if direction == "left":
        message = "1111"
    elif direction == "right":
        message = "11"
    elif direction == "up":
        message = "1"
    elif direction == "down":
        message = "111"
    elif direction == "close":
        message = "11111"
    else:
        return jsonify(hello='error')

    byte_message = bytes(message, "utf-8")
    opened_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    opened_socket.sendto(byte_message, (ip, PORT))
    opened_socket.close()
    return jsonify(hello='world')


if __name__ == '__main__':
    app.run(debug=True)
