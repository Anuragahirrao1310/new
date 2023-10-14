# flask_app.py
from flask import Flask, request, jsonify
import cv2

app = Flask(__name__)

# Function to perform face detection on an image
def detect_faces(image_path):
    # Load the image
    image = cv2.imread(image_path)

    # Load a pre-trained face detection model
    face_cascade = cv2.CascadeClassifier(cv2.data.haarcascades + 'haarcascade_frontalface_default.xml')

    # Convert the image to grayscale for face detection
    gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

    # Detect faces in the image
    faces = face_cascade.detectMultiScale(gray, scaleFactor=1.1, minNeighbors=5, minSize=(30, 30))

    return faces

@app.route('/detect_faces', methods=['POST'])
def detect_faces_route():
    if 'image' not in request.files:
        return jsonify({'error': 'No image provided'})

    image = request.files['image']
    faces = detect_faces(image)

    return jsonify({'faces': faces.tolist()})

if __name__ == '__main__':
    app.run(debug=True)
