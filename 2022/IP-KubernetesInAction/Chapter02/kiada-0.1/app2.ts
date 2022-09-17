import { createServer } from "http"
import { hostname } from "os"
import { readFileSync } from "fs"

const version = "0.1";
const listenPort = 8080;

function sendResponse(status, contentType, encoding, body, response) {
    response.writeHead(status, {'Content-Type': contentType});
    response.write(body, encoding);
    response.end();
}

