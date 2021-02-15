from flask import Flask, redirect, url_for, request, jsonify
import socket

ip   = "127.0.0.1";
PORT = 7070


app = Flask(__name__)

@app.route('/navigation/<coordinates>')
def navigation(coordinates):
    # if coordinates == "foodlab":
    #     message = "1"
    # if coordinates == "elctronic":
    #     message = "1"
    # if coordinates == "robotic":
    #     message = "1"
    # if coordinates == "4Dspace":
    #     message = "1"

    byte_message = coordinates.encode()
    opened_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    opened_socket.sendto(byte_message, (ip, PORT))
    opened_socket.close()
    return jsonify(hello='world')

if __name__ == '__main__':
    app.run(debug=True)
