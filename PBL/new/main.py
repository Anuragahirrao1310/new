import random
from http.server import BaseHTTPRequestHandler, HTTPServer
import threading

attention_percentage = 0

class RequestHandler(BaseHTTPRequestHandler):
    def do_GET(self):
        global attention_percentage
        if self.path == '/attention':
            self.send_response(200)
            self.send_header('Content-type', 'text/html')
            self.end_headers()
            self.wfile.write(str(attention_percentage).encode('utf-8'))

def attention_simulator():
    global attention_percentage
    while True:
        # Simulate attention detection with random values between 0 and 100
        attention_percentage = round(random.uniform(0, 100), 2)
        print(f"Simulated attention: {attention_percentage}%")
        threading.Event().wait(5)

if __name__ == "__main__":
    server_address = ('', 8080)
    httpd = HTTPServer(server_address, RequestHandler)

    print("Starting attention simulator server on port 8080...")
    threading.Thread(target=attention_simulator).start()
    httpd.serve_forever()
