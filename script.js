var dgram = require('dgram');

const PORT = 9000
const HOST = "192.168.220.81"

// creating a client socket
const client = dgram.createSocket('udp4')

const data_UP = Buffer.from('MSG from UDP client')
const data_DOWN = Buffer.from('Polpi')

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
    alert('HEHO CLICK')
}