import cv2
import time

# Load the pre-trained face and eye detection classifiers
face_cascade = cv2.CascadeClassifier(cv2.data.haarcascades + 'haarcascade_frontalface_default.xml')
eye_cascade = cv2.CascadeClassifier(cv2.data.haarcascades + 'haarcascade_eye.xml')

# Initialize variables
in_attention = False
attention_start_time = None
total_attention_time = 0  # Total duration of attention in seconds

# Initialize the video capture from the default camera (0)
cap = cv2.VideoCapture(0)

# Check if the camera is opened successfully
if not cap.isOpened():
    print("Error: Unable to access the camera.")
    exit()

while True:
    ret, frame = cap.read()
   
    if not ret:
        break

    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    faces = face_cascade.detectMultiScale(gray, scaleFactor=1.1, minNeighbors=5, minSize=(30, 30))

    # If faces are detected, consider it as attention
    if len(faces) > 0:
        if not in_attention:
            in_attention = True
            attention_start_time = time.time()
    else:
        if in_attention:
            elapsed_time = time.time() - attention_start_time
            total_attention_time += elapsed_time
            in_attention = False

    # Draw rectangles around the detected faces
    for (x, y, w, h) in faces:
        cv2.rectangle(frame, (x, y), (x + w, y + h), (0, 255, 0), 2)

    cv2.imshow('Attention Span Detector', frame)

    # Break the loop when the 'q' key is pressed
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# Release the camera capture and close the OpenCV window
cap.release()
cv2.destroyAllWindows()

# Calculate total attention time in minutes and seconds
total_attention_minutes = int(total_attention_time // 60)
total_attention_seconds = int(total_attention_time % 60)

print(f"Total Attention Time: {total_attention_minutes} minutes {total_attention_seconds} seconds")
