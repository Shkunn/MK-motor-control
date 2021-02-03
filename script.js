var dgram = require('dgram');

const PORT = 9000
const HOST = "192.168.220.81"

// creating a client socket
const client = dgram.createSocket('udp4')

const data_UP = Buffer.from('MSG from UDP client')
const data_DOWN = Buffer.from('Polpi')
// let buffer2 = new ArrayBuffer(2);
// let buffer3 = new ArrayBuffer(3);
// let buffer4 = new ArrayBuffer(4);

function fonction1(PORT, HOST, client, data_UP) {
    client.send(data_UP, PORT, HOST, error => {
        if (error) {
            console.log(error)
            client.close()
        } else {
            console.log('Data sent !!!')
        }
    })   
}

function fonction2(PORT, HOST, client, data_DOWN) {
    client.send(data_DOWN, PORT, HOST, error => {
        if (error) {
            console.log(error)
            client.close()
        } else {
            console.log('Data sent !!!')
        }
    })   
}

function fonction3() {
    let buffer1 = new ArrayBuffer(1);
    if (buffer1.byteLength == 1) {
        alert("Yes, it's 1 bytes.")
    } else {
        alert("Oh no, it's the wrong size!");
    }
}