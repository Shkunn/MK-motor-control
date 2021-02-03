const Http = new XMLHttpRequest();
const SERVER = "127.0.0.1:5000"
function control(direction) {
    let ip = document.getElementById("myip").value
    const url = "http:" + SERVER + "/control/" + ip + "/" + direction;
    Http.open("GET", url);
    Http.send();
}